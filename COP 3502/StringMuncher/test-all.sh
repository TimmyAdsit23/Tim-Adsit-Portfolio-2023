#!/bin/bash


# Sean Szumlanski
# COP 3502, Spring 2023

# ==========================
# StringMuncher: test-all.sh
# ==========================
# You can run this script at the command line like so:
#
#   bash test-all.sh
#
# For more details, see the assignment PDF.


################################################################################
# Shell check.
################################################################################

# Running this script with sh instead of bash can lead to false positives on the
# test cases. Yikes! These checks ensure the script is not being run through the
# Bourne shell (or any shell other than bash).

if [ "$BASH" != "/bin/bash" ] && [ "$BASH" != "/usr/bin/bash" ]; then
  echo ""
  echo " Bloop! Please use bash to run this script, like so: bash test-all.sh"
  echo ""
  exit
fi

if [ -z "$BASH_VERSION" ]; then
  echo ""
  echo " Bloop! Please use bash to run this script, like so: bash test-all.sh"
  echo ""
  exit
fi


################################################################################
# Initialization.
################################################################################

PASS_CNT=0
NUM_TEST_CASES=35

# Each test case is run twice: once for output check, once for memleak check.
TOTAL_TEST_CNT=`expr $NUM_TEST_CASES + $NUM_TEST_CASES`

# +2 below for the warnings and indentation checks.
TOTAL_TEST_CNT=`expr $TOTAL_TEST_CNT + 2`


################################################################################
# Check for commands that are required by this test script.
################################################################################

# This command is necessary in order to run all the test cases in sequence.
if ! [ -x "$(command -v seq)" ]; then
	echo ""
	echo " Error: seq command not found. You might see this message if you're"
	echo "        running this script on an old Mac system. Please be sure to"
	echo "        test your final code on Eustis. Aborting test script."
	echo ""
	exit
fi

# This command is necessary for various warning checks.
if ! [ -x "$(command -v grep)" ]; then
	echo ""
	echo " Error: grep command not found. You might see this message if you're"
	echo "        running this script on an old Mac system. Please be sure to"
	echo "        test your final code on Eustis. Aborting test script."
	echo ""
	exit
fi

# This command is necessary for various warning checks.
if ! [ -x "$(command -v perl)" ]; then
	echo ""
	echo " Error: perl command not found. You might see this message if you're"
	echo "        running this script on an old Mac system. Please be sure to"
	echo "        test your final code on Eustis. Aborting test script."
	echo ""
	exit
fi


################################################################################
# Magical incantations.
################################################################################

# Ensure that obnoxious glibc errors are piped to stderr.
export LIBC_FATAL_STDERR_=1

# Now redirect all local error messages to /dev/null (like "process aborted").
exec 2> /dev/null


################################################################################
# Check that all required files are present.
################################################################################

if [ ! -f StringMuncher.c ]; then
	echo ""
	echo " Error: You must place StringMuncher.c in this directory before"
	echo "        we can proceed. Aborting test script."
	echo ""
	exit
elif [ ! -f StringMuncher.h ]; then
	echo ""
	echo " Error: You must place StringMuncher.h in this directory before"
	echo "        we can proceed. Aborting test script."
	echo ""
	exit
elif [ ! -f CloneTest.c ]; then
	echo ""
	echo " Error: You must place CloneTest.c in this directory before"
	echo "        we can proceed. Aborting test script."
	echo ""
	exit
elif [ ! -d sample_output ]; then
	echo ""
	echo " Error: You must place the sample_output folder in this directory"
	echo "        before we can proceed. Aborting test script."
	echo ""
	exit
elif [ ! -f sample_output/CloneTest-output.txt ]; then
	echo ""
	echo " Error: You must place CloneTest-output.txt in the sample_output"
	echo "        directory before we can proceed. Aborting test script."
	echo ""
	exit
fi

for i in `seq -f "%02g" 1 $NUM_TEST_CASES`;
do
	if [ ! -f testcase$i.c ]; then
		echo ""
		echo " Error: You must place testcase$i.c in this directory before we"
		echo "        can proceed. Aborting test script."
		echo ""
		exit
	fi
	if [ ! -f sample_output/testcase$i-output.txt ]; then
		echo ""
		echo " Error: You must place testcase$i-output.txt in the sample_output"
		echo "        directory before we can proceed. Aborting test script."
		echo ""
		exit
	fi
done

grep -s -q "^#include \"StringMuncher\.h\"" StringMuncher.c
grep_val=$?

if [[ $grep_val != 0 ]]; then
	echo ""
	echo "  Whoa, buddy! Your StringMuncher.c file does not appear to have"
	echo "  a proper #include statement for StringMuncher.h. Please read"
	echo "  Section 2 of the assignment PDF before proceeding."
	echo ""
	exit
fi


################################################################################
# Run test cases.
################################################################################

echo ""
echo "================================================================"
echo "Running test cases..."
echo "================================================================"
echo ""

# Function for running a single test case.
function run_test_case()
{
	local testcase_file=$1
	local output_file=$2

	echo -n "  [Test Case] $testcase_file ... "

	# Attempt to compile, and check for compilation failure.
	gcc StringMuncher.c $testcase_file 2> /dev/null
	compile_val=$?
	if [[ $compile_val != 0 ]]; then
		echo "fail (failed to compile)"
		return
	fi

	# Run program. Capture return value to check whether it crashes.
	./a.out > myoutput.txt 2> /dev/null
	execution_val=$?
	if [[ $execution_val != 0 ]]; then
		echo "fail (program crashed)"
		return
	fi

	# Run diff and capture its return value.
	diff myoutput.txt sample_output/$output_file > /dev/null
	diff_val=$?
	
	# Output results based on diff's return value.
	if  [[ $diff_val != 0 ]]; then
		echo "fail (output mismatch)"
	else
		echo "PASS!"
		PASS_CNT=`expr $PASS_CNT + 1`
	fi
}

for i in `seq -f "%02g" 1 $NUM_TEST_CASES`;
do
	run_test_case "testcase$i.c" "testcase$i-output.txt"
done


################################################################################
# Check for memory leaks: run test cases through valgrind.
################################################################################

echo ""
echo "================================================================"
echo "Checking for memory leaks with valgrind..."
echo "================================================================"
echo ""

# Function for running a single test case through valgrind.
function run_valgrind_test()
{
	local testcase_file=$1
	local output_file=$2

	echo -n "  [Memory Leak Check] $testcase_file ... "

	# Abort immediately if valgrind is not installed on this system.
	if ! [ -x "$(command -v valgrind)" ]; then
		echo "fail (aborted)"
		return
	fi

	# Attempt to compile, and check for compilation failure.
	gcc StringMuncher.c testcase$i.c -g 2> /dev/null
	compile_val=$?
	if [[ $compile_val != 0 ]]; then
		echo "fail (failed to compile)"
		return
	fi

	# Run program through valgrind. Check whether program crashes.
	valgrind --leak-check=yes ./a.out > myoutput.txt 2> err.log
	execution_val=$?
	if [[ $execution_val != 0 ]]; then
		echo "fail (program crashed)"
		return
	fi

	# Check output for indication of memory leaks.
	grep --silent "no leaks are possible" err.log
	valgrindfail=$?
	if [[ $valgrindfail != 0 ]]; then
		echo "fail (memory leak detected)"
		return
	fi

	# Run diff and capture its return value.
	diff myoutput.txt sample_output/$output_file > /dev/null
	diff_val=$?
	
	# Output results based on diff's return value.
	if  [[ $diff_val != 0 ]]; then
		echo "fail (output mismatch)"
	else
		echo "PASS!"
		PASS_CNT=`expr $PASS_CNT + 1`
	fi
}

for i in `seq -f "%02g" 1 $NUM_TEST_CASES`;
do
	run_valgrind_test "testcase$i.c" "testcase$i-output.txt"
done

if ! [ -x "$(command -v valgrind)" ]; then
	echo ""
	echo "  ERROR: valgrind is not installed on this system."
fi


################################################################################
# Run bonus test case. Don't count toward final count.
################################################################################

echo ""
echo "================================================================"
echo "Running bonus test case for cloneStringMuncher()..."
echo "================================================================"
echo ""

function run_bonus_test ()
{
	echo -n "  [Bonus Test Case] CloneTest.c ... "

	# Attempt to compile, and check for compilation failure.
	gcc StringMuncher.c CloneTest.c 2> /dev/null
	compile_val=$?
	if [[ $compile_val != 0 ]]; then
		echo "fail (failed to compile)"
		return
	fi

	# Run program. Capture return value to check whether it crashes.
	./a.out > clonetest_output.txt 2> /dev/null
	execution_val=$?
	if [[ $execution_val != 0 ]]; then
		echo "fail (program crashed)"
		return
	fi

	# Run diff and capture its return value.
	diff clonetest_output.txt sample_output/CloneTest-output.txt > /dev/null
	diff_val=$?
	
	# Output results based on diff's return value.
	if  [[ $diff_val != 0 ]]; then
		echo "fail (output mismatch)"
	else
		echo "PASS!"
	fi
}

run_bonus_test


############################################################################
# Check for warnings.
############################################################################

echo ""
echo "================================================================"
echo "Checking for compiler warnings..."
echo "================================================================"
echo ""

if ! [ -x "$(command -v grep)" ]; then
	echo "  Skipping compiler warning check; grep not installed. You"
	echo "  might see this message if you're running this script on a"
	echo "  Mac. Please be sure to test your final code on Eustis."
else
	gcc StringMuncher.c -c &> ./err.log
	compile_flag=$?

	if [[ $compile_flag != 0 ]]; then
		echo "  Failed to compile."
	else
		grep --silent "warning" err.log
		warnings_flag=$?

		if [[ $warnings_flag == 0 ]]; then
			echo "  Warnings detected. :("
		else
			echo "  No warnings detected. Hooray!"
			PASS_CNT=`expr $PASS_CNT + 1`
		fi
	fi
fi


############################################################################
# Check for tabs vs. spaces.
############################################################################

echo ""
echo "================================================================"
echo "Checking for tabs vs. spaces..."
echo "================================================================"
echo ""

if ! [ -x "$(command -v grep)" ]; then
	echo "  Skipping tabs vs. spaces check; grep not installed. You"
	echo "  might see this message if you're running this script on a"
	echo "  Mac. Please be sure to test your final code on Eustis."
elif ! [ -x "$(command -v awk)" ]; then
	echo "  Skipping tabs vs. spaces check; awk not installed. You"
	echo "  might see this message if you're running this script on a"
	echo "  Mac. Please be sure to test your final code on Eustis."
else
	num_spc_lines=`grep "^ " StringMuncher.c | wc -l | awk '{$1=$1};1'`
	num_tab_lines=`grep "$(printf '^\t')" StringMuncher.c | wc -l | awk '{$1=$1};1'`
	num_und_lines=`grep "$(printf '^[^\t ]')" StringMuncher.c | wc -l | awk '{$1=$1};1'`

	echo "  Number of lines beginning with spaces: $num_spc_lines"
	echo "  Number of lines beginning with tabs: $num_tab_lines"
	echo "  Number of lines with no indentation: $num_und_lines"

	if [ "$num_spc_lines" -gt 0 ] && [ "$num_tab_lines" -gt 0 ]; then
		echo ""
		echo "  Whoa, buddy! It looks like you're starting some lines of code with"
		echo "  tabs, and other lines of code with spaces. You'll need to choose"
		echo "  one or the other."
		echo ""
		echo "  Try running the following commands to see which of your lines begin"
		echo "  with spaces (the first command below) and which ones begin with tabs"
		echo "  (the second command below):"
		echo ""
		echo "     grep \"^ \" StringMuncher.c -n"
		echo "     grep \"\$(printf '^\t')\" StringMuncher.c -n"
		echo ""
		echo "  --------------------------------------------------------------"
		echo "  TRUST THIS REPORT! ~~ TRUST THIS REPORT! ~~ TRUST THIS REPORT!"
		echo "  --------------------------------------------------------------"
		echo ""
		echo "  If this report says certain lines begin with spaces, but you"
		echo "  examine them in your text editor and they appear to begin with"
		echo "  tabs, they really do begin with spaces. Your editor is likely"
		echo "  hiding that from you using a feature called \"soft tabs\" that"
		echo "  you need to disable."
	elif [ "$num_spc_lines" -gt 0 ]; then
		echo ""
		echo "  Looks like you're using spaces for all your indentation! (Yay!)"
		PASS_CNT=`expr $PASS_CNT + 1`
	elif [ "$num_tab_lines" -gt 0 ]; then
		echo ""
		echo "  Looks like you're using tabs for all your indentation! (Yay!)"
		PASS_CNT=`expr $PASS_CNT + 1`
	else
		echo ""
		echo "  Whoa, buddy! It looks like none of your code is indented!"
	fi
fi


################################################################################
# Cleanup phase.
################################################################################

# Clean up the executable and output files generated by this script.
rm -f a.out
rm -f myoutput.txt
rm -f err.log
rm -f StringMuncher.o
rm -f sanitycheck_output.txt
rm -f clonetest_output.txt


################################################################################
# Final thoughts.
################################################################################

echo ""
echo "================================================================"
echo "Final Report"
echo "================================================================"

if [ $PASS_CNT -eq $TOTAL_TEST_CNT ]; then
	echo ""
	echo "              ,)))))))),,,"
	echo "            ,(((((((((((((((,"
	echo "            )\\\`\\)))))))))))))),"
	echo "     *--===///\`_    \`\`\`((((((((("
	echo "           \\\\\\ b\\  \\    \`\`)))))))"
	echo "            ))\\    |     ((((((((               ,,,,"
	echo "           (   \\   |\`.    ))))))))       ____ ,)))))),"
	echo "                \\, /  )  ((((((((-.___.-\"    \`\"((((((("
	echo "                 \`\"  /    )))))))               \\\`)))))"
	echo "                    /    ((((\`\`                  \\((((("
	echo "              _____|      \`))         /          |)))))"
	echo "             /     \\                 |          / ((((("
	echo "            /  --.__)      /        _\\         /   )))))"
	echo "           /  /    /     /'\`\"~----~\`  \`.       \\   (((("
	echo "          /  /    /     /\`              \`-._    \`-. \`)))"
	echo "         /_ (    /    /\`                    \`-._   \\ (("
	echo "        /__|\`   /   /\`                        \`\\\`-. \\ ')"
	echo "               /  /\`                            \`\\ \\ \\"
	echo "              /  /                                \\ \\ \\"
	echo "             /_ (                                 /_()_("
	echo "            /__|\`                                /__/__|"
	echo ""
	echo "                             Legendary."
	echo ""
	echo "                10/10 would run this program again."
	echo ""
	echo "  CONGRATULATIONS! You appear to be passing all the test cases!"
	echo ""
	echo "  Now, don't forget to create some extra test cases of your own."
	echo "  The test cases we have given you are not comprehensive. In"
	echo "  order to ensure your program will pass any test cases we use"
	echo "  in grading, you should generate several additional test cases"
	echo "  by hand and ensure your program works on those. Failure to do"
	echo "  so could result in you submitting code that has a small bug"
	echo "  you haven't detected yet, and that could cause catastrophic"
	echo "  point loss if that bug is triggered by a bunch of the test"
	echo "  cases we use when grading. Be sure to read through the test"
	echo "  cases provided with the assignment, as well, for examples of"
	echo "  how to build your own."
	echo ""
else
	echo "                           ."
	echo "                          \":\""
	echo "                        ___:____     |\"\\/\"|"
	echo "                      ,'        \`.    \\  /"
	echo "                      |  o        \\___/  |"
	echo "                    ~^~^~^~^~^~^~^~^~^~^~^~^~"
	echo ""
	echo "                           (fail whale)"
	echo ""
	echo "  The fail whale is friendly and adorable! He is not here to"
	echo "  demoralize you, but rather, to bring you comfort and joy"
	echo "  in your time of need. \"Keep plugging away,\" he says! \"You"
	echo "  can do this!\""
	echo ""
	echo "               TO CHECK WHY A TEST CASE IS FAILING:"
	echo ""
	echo "  For instructions on how to run these test cases individually"
	echo "  and inspect how your output differs from the expected output,"
	echo "  see Section 5 of the assignment PDF (pgs. 14-15)."
	echo ""
	echo "  You must also pass the warnings check and the indentation"
	echo "  check in order to part ways with the fail whale."
	echo ""
fi
