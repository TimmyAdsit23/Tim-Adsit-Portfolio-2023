// Tim Adsit
// COP 3330, Spring 2023
// ti047614

import java.util.Arrays;

public class Strands 
{

    // REQUIRED METHODS

    public static void straightAndNarrow(String str)
    {
        if (str == null)
        {
            System.out.println("Pshh!");
            return;
        }

        for (int i = 0; i < str.length(); i++)
        {
            if (str.charAt(i) == ' ')
            {
                System.out.println();
            }
            else
            {
                System.out.print("  ");
                System.out.println(str.charAt(i));
            }    
        }
    }

    public static void straightAndNarrow(String str, int n)
    {
        if (str == null)
        {
            System.out.println("Pshh!");
            return;
        }

        for (int i = 0; i < str.length(); i++)
        {
            if (str.charAt(i) == ' ')
            {
                System.out.println();
            }
            else
            {
                for(int j = 0; j < n; j++)
                {
                    System.out.print(" ");
                }
                System.out.println(str.charAt(i));
            }     
        }
    }

    public static void meanderingPath(String str)
    {
        int [] spaces = {2,2,2,3,4,5,5,5,4,3}; // 10

        if (str == null)
        {
            System.out.println("Pshh!");
            return;
        }

        for (int i = 0; i < str.length(); i++)
            if (str.charAt(i) == ' ')
                System.out.println();
            else
                if (i != 0)
                {
                    for (int j = 0; j < spaces[i % spaces.length]; j++)
                        System.out.print(" ");

                    System.out.println(str.charAt(i));
                }
                else
                {
                    System.out.print("   ");
                    System.out.println(str.charAt(i));
                }
    }

    public static void classicRapunzel(String [] strings)
    {
        if (isStringsNull(strings))
            return;

        printRapunzel(strings);
    }

    public static void steamyMocha(String [] strings)
    {
        if (isStringsNull(strings))
            return;

        printMocha(strings);
    }

    public static void cascadingWaterfall(String [] strings)
    {
        if (isStringsNull(strings))
            return;

        printWaterfall(strings);
    }


    // HELPER METHODS

    public static boolean isStringsNull(String[] strings)
    {
        if (strings == null)
        {
            System.out.println("Pshh!");
            return true;
        }
        else
        {
            return false;
        }
    }
    
    public static int findMaxStringLength(String [] strings)
    {
        int maxLength = Integer.MIN_VALUE;

        // finds the max length
        for (int i = 0; i < strings.length; i++)
            if (maxLength < strings[i].length())
                maxLength = strings[i].length();
    
        return maxLength;
    }

    public static void printSpaces(int i)
    {
        int [] spaces = {2,2,2,3,4,5,5,5,4,3};

        if (i != 0)
            {
                for (int j = 0; j < spaces[i % spaces.length]; j++)
                {
                    System.out.print(" ");
                }
            }
            else
            {
                // the first time we print, we print 3 spaces
                System.out.print("   ");
            }
    }

    public static int findLatestIndex(String [] strings, int i)
    {
        int latestIndex = Integer.MIN_VALUE;

        // x iterates through every string
        for (int x = 0; x < strings.length; x++)
            // finds the char at the index of i in the latest string
            if (strings[x].length() > i && strings[x].charAt(i) != ' ')
                latestIndex = x;

        return latestIndex;
    }

    public static void printRapunzel(String [] strings)
    {
        int maxLength = findMaxStringLength(strings);

        // i iterates through every character in the largest string
        for (int i = 0; i < maxLength; i++)
        {
            int latestIndex = findLatestIndex(strings, i);
            
            if (latestIndex != Integer.MIN_VALUE)
            {
                printSpaces(i);
                printLine(strings, latestIndex, i);
            }
            else
            {
                System.out.println();
            }            
        }
    }

    public static void printLine(String [] strings, int latestIndex, int i)
    {
        // y iterates through every string until the latest string with chars
        for (int y = 0; y <= latestIndex; y++)
            // if the i that we're at is farther than a string's length
            if (strings[y].length() > i)
                printEligableCharacter(strings, latestIndex, i, y);
            else
                printIneligableCharacter(latestIndex, y);
        
        if (latestIndex == Integer.MIN_VALUE)
            System.out.println();
    }

    public static void printEligableCharacter(String [] strings, int latestIndex, int i, int y)
    {
        System.out.print(strings[y].charAt(i));

        // prints two spaces if not the last string with a character at the ith index
        // or prints a new line if the latest string
        if (y != latestIndex)
            System.out.print("  ");
        else
            System.out.println();
    }

    public static void printIneligableCharacter(int latestIndex, int y)
    {
        // either 3 spaces ...
        // (1 space for the missing character, two spaces for the
        // space inbetween itself and the next character)
        // ... or a new line
        if (y != latestIndex)
            System.out.print("   ");
        else
            System.out.println();
    }

    // SPECIFICALLY MOCHA STUFF

    public static void printMocha(String [] strings)
    {
        int maxLength = findStaggeredMaxStringLength(strings);

        // i iterates through every character in the largest string
        for (int i = 0; i < maxLength; i++)
            printStaggeredLine(strings, maxLength, i);
    }

    public static void printStaggeredLine(String [] strings, int maxLength, int i)
    {
        printSpaces(i);

        int latestEvenIndex = findStaggeredLatestIndex(strings, i);

        printStaggeredCharacter(strings, latestEvenIndex, i);
    }

    public static int findStaggeredLatestIndex(String [] strings, int i)
    {
        int latestIndex = Integer.MIN_VALUE;

        if (i == 0)
        {
            // finds the char at the index of i in the latest string
            for (int x = 0; x < strings.length; x++)
            {
                // if odd indexed string
                if (x % 2 == 0)
                {
                    if (strings[x].length() > i && strings[x].charAt(i) != ' ')
                    {
                        latestIndex = x;
                    }
                }
            }
        }
        else
        {
            // x iterates through every string
            for (int x = 0; x < strings.length; x++)
            {
                // finds the char at the index of i in the latest string

                // if odd indexed string
                if (x % 2 == 1) // HERE IS FIXING?
                {
                    // go up one because we are staggering
                    if (strings[x].length() > i-1 && strings[x].charAt(i-1) != ' ')
                    {
                        latestIndex = x; // might be a problem?
                    }
                }
                else if (strings[x].length() > i && strings[x].charAt(i) != ' ')
                {
                    latestIndex = x;
                }
            }
        }
        return latestIndex;
    }

    public static void printStaggeredCharacter(String [] strings, int latestIndex, int i)
    {
        // y iterates through every string until the latest string with chars
        for (int y = 0; y <= latestIndex; y++)
            if (y % 2 == 1)
                // if the string has a character at the i+1th index
                if (strings[y].length() > i-1 && i != 0)
                    printEligableCharacter(strings, latestIndex, i-1, y);
                else
                    printIneligableCharacter(latestIndex, y);
            else
                // if the i that we're at is farther than a string's length
                if (strings[y].length() > i)
                    printEligableCharacter(strings, latestIndex, i, y);
                else
                    printIneligableCharacter(latestIndex, y);    
               
    }

    public static int findStaggeredMaxStringLength(String [] strings)
    {
        int maxLength = Integer.MIN_VALUE;
        int stringLength;

        // finds the max length
        for (int i = 0; i < strings.length; i++)
        {
            // if odd...
            if (i % 2 == 1)
                // plus one for the starting space
                stringLength = strings[i].length()+1;
            else
                stringLength = strings[i].length();

            if (maxLength < stringLength)
                maxLength = stringLength;
        }
        return maxLength;
    }

    // SPECIFICALLY WATERFALL STUFF

    public static void printWaterfall(String [] strings)
    {
        int maxLength = findWaterfallMaxStringLength(strings);

        // i iterates through every character in the largest string
        for (int i = 0; i < maxLength; i++)
            printWaterfallLine(strings, maxLength, i);
    }

    public static int findWaterfallMaxStringLength(String [] strings)
    {
        int maxLength = Integer.MIN_VALUE;
        int stringLength;

        // finds the max length
        for (int i = 0; i < strings.length; i++)
        {
            // plus i for every space added for each additional string
            stringLength = strings[i].length() + i;

            if (maxLength < stringLength)
                maxLength = stringLength;
        }
        return maxLength;
    }

    public static void printWaterfallLine(String [] strings, int maxLength, int i)
    {
        int latestWaterfallIndex = findWaterfallLatestIndex(strings, i);
        
        if (latestWaterfallIndex == Integer.MIN_VALUE)
            System.out.println();
        else
            printSpaces(i);

        printWaterfallCharacter(strings, latestWaterfallIndex, i);
    }

    public static int findWaterfallLatestIndex(String [] strings, int i)
    {
        int latestIndex = Integer.MIN_VALUE;
        // x iterates through every string to find the last available character
        for (int x = 0; x < strings.length; x++)
            // plus x because that amount of spaces will be added before the string starts printing
            // if the string index is less than or equal to the character index, its eligable
            // also last char cant be space
            if (strings[x].length()+x > i && x <= i && strings[x].charAt(i-x) != ' ')
                latestIndex = x;

        return latestIndex;
    }

    public static void printWaterfallCharacter(String [] strings, int latestIndex, int i)
    {
        // y iterates through every string until the latest string with chars
        for (int y = 0; y <= latestIndex; y++)
            // if the i that we're at is farther than a string's length
            if (strings[y].length()+y > i)
                printEligableCharacter(strings, latestIndex, i-y, y);
            else
                printIneligableCharacter(latestIndex, y);
    }

    public static double difficultyRating()
    {
        return 2.3;
    }

    public static double hoursSpent()
    {
        return 8;
    }
}
