#!/bin/bash

# Sean Szumlanski
# COP 3330, Spring 2023

# ============================
# PotionMaster: test-all.sh
# ============================
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
NUM_TEST_CASES=25

# +4 below for the warning and indentation checks.
TOTAL_TEST_CNT=`expr $NUM_TEST_CASES + 4`


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


################################################################################
# Check that all required files are present.
################################################################################

if [ ! -f PotionMaster.java ]; then
	echo ""
	echo " Error: You must place PotionMaster.java in this directory before we can"
	echo "        proceed. Aborting test script."
	echo ""
	exit
elif [ ! -f PotionInfo.java ]; then
	echo ""
	echo " Error: You must place PotionInfo.java in this directory before we can"
	echo "        proceed. Aborting test script."
	echo ""
	exit
elif [ ! -f SanityCheck.java ]; then
	echo ""
	echo " Error: You must place SanityCheck.java in this directory before we can"
	echo "        proceed. Aborting test script."
	echo ""
	exit
elif [ ! -d sample_output ]; then
	echo ""
	echo " Error: You must place the sample_output folder in this directory"
	echo "        before we can proceed. Aborting test script."
	echo ""
	exit
fi

for i in `seq -f "%02g" 1 $NUM_TEST_CASES`;
do
	if [ ! -f TestCase$i.java ]; then
		echo ""
		echo " Error: You must place TestCase$i.java in this directory before we"
		echo "        can proceed. Aborting test script."
		echo ""
		exit
	fi
done

for i in `seq -f "%02g" 1 $NUM_TEST_CASES`;
do
	if [ ! -f sample_output/TestCase$i-output.txt ]; then
		echo ""
		echo " Error: You must place TestCase$i-output.txt in the sample_output directory"
		echo "        before we can proceed. Aborting test script."
		echo ""
		exit
	fi
done


################################################################################
# Run test cases with input specified at command line (standard test cases).
################################################################################

echo ""
echo "================================================================"
echo "Running test cases..."
echo "================================================================"
echo ""

for i in `seq -f "%02g" 1 $NUM_TEST_CASES`;
do
	echo -n "  [Test Case] TestCase$i ... "

	# Make sure any pre-compiled classes get re-compiled.
	rm -rf *.class

	# Attempt to compile.
	javac PotionMaster.java TestCase$i.java 2> /dev/null
	compile_val=$?
	if [[ $compile_val != 0 ]]; then
		echo "fail (failed to compile)"
		continue
	fi

	# Run program. Capture return value to check whether it crashes.
	java TestCase$i > myoutput.txt 2> /dev/null
	execution_val=$?
	if [[ $execution_val != 0 ]]; then
		echo "fail (program crashed)"
		continue
	fi

	# Run diff and capture its return value.
	diff myoutput.txt sample_output/TestCase$i-output.txt > /dev/null
	diff_val=$?
	
	# Output results based on diff's return value.
	if  [[ $diff_val != 0 ]]; then
		echo "fail (output does not match)"
	else
		echo "PASS!"
		PASS_CNT=`expr $PASS_CNT + 1`
	fi
done


################################################################################
# Run sanity check.
################################################################################

echo ""
echo "================================================================"
echo "Checking your compiler's ability to produce adequate warnings..."
echo "================================================================"
echo ""

function run_sanity_check()
{
	echo -n "  [Sanity Check] SanityCheck.java ... "

	# Clean slate.
	rm -rf *.class

	# Attempt to compile, and check for compilation failure.
	javac SanityCheck.java 2> SanityCheck__warning.log
	compile_val=$?
	if [[ $compile_val != 0 ]]; then
		echo "fail (failed to compile)"
		return
	fi

	# Check for unchecked or unsafe operations warning.
	grep "Xlint:unchecked" SanityCheck__warning.log > /dev/null 2> /dev/null
	xlint_val=$?

	if  [[ $xlint_val != 0 ]]; then
		echo "fail (see below)"
		echo ""
		echo "================================================================"
		echo "WARNING! WARNING! WARNING!"
		echo "================================================================"
		echo ""
		echo "  Your system does not seem to be producing warnings about"
		echo "  unchecked or unsafe operations. Please be extra careful to"
		echo "  test your code on Eustis before submitting, and please be"
		echo "  aware that the additional checks for warnings below might"
		echo "  currently be unreliable on your system."
	else
		echo "PASS!"
		PASS_CNT=`expr $PASS_CNT + 1`
	fi
}

run_sanity_check


################################################################################
# Special check for compile-time warnings and warning suppression annotations.
################################################################################

echo ""
echo "================================================================"
echo "Running additional tests and safety checks..."
echo "================================================================"
echo ""

javac PotionMaster.java 2> PotionMaster__warning.log

grep unchecked PotionMaster__warning.log > /dev/null 2> /dev/null
warn_val=$?

grep "@Suppress" PotionMaster.java > /dev/null 2> /dev/null
supp_val=$?

warn_note=0
supp_note=0

if [[ $warn_val == 0 ]]; then
	echo "  [Additional Check] Compiles without warnings: ** fail **"
	warn_note=1
else
	echo "  [Additional Check] Compiles without warnings: PASS"
	PASS_CNT=`expr $PASS_CNT + 1`
fi

if [[ $supp_val == 0 ]]; then
	echo "  [Additional Check] No suppression annotations: ** fail **"
	supp_note=1
else
	echo "  [Additional Check] No suppression annotations: PASS"
	PASS_CNT=`expr $PASS_CNT + 1`
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
	num_spc_lines=`grep "^ " PotionMaster.java | wc -l | awk '{$1=$1};1'`
	num_tab_lines=`grep "$(printf '^\t')" PotionMaster.java | wc -l | awk '{$1=$1};1'`
	num_und_lines=`grep "$(printf '^[^\t ]')" PotionMaster.java | wc -l | awk '{$1=$1};1'`

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
		echo "     grep \"^ \" PotionMaster.java -n"
		echo "     grep \"\$(printf '^\t')\" PotionMaster.java -n"
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
		echo "  Whoa, buddy! It looks like none of your lines of code are indented!"
	fi
fi


################################################################################
# Cleanup phase.
################################################################################

rm -f *.class
rm -f PotionMaster__warning.log
rm -f SanityCheck__warning.log
rm -f myoutput.txt


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
	echo "  cases we use when grading."
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
	echo "  see Section 7 of the assignment PDF (pgs. 7-8)."
	echo ""
	echo "  You must also pass the indentation check in order to part"
	echo "  ways with the fail whale."

	if [[ $warn_note != 0 ]]; then
		echo ""
		echo "  You can type 'javac PotionMaster.java -Xlint:unchecked' at the"
		echo "  command line in Eustis for additional details about why your"
		echo "  code is generating warnings. Note that compiler warnings will"
		echo "  result in point deductions for this assignment."
	fi

	if [[ $supp_note != 0 ]]; then
		echo ""
		echo "  You seem to be using a @Suppress annotation in your code. This"
		echo "  might result in a point deduction for this assignment. This"
		echo "  message might appear even if you have commented out a suppress"
		echo "  annotation. Please be sure to remove any comments that include"
		echo "  @Suppress annotations of any kind so that your code won't be"
		echo "  flagged automatically for using suppressions."
	fi

	echo ""
fi
