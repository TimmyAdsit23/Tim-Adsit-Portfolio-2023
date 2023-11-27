/* Tim Adsit
 * Dr. Andrew Steinberg
 * COP3503 Fall 2023
 * Programming Assignment 4
 */


// delta = 2
// Same symbol costs 0
// vowel and different vowel costs 1
// constant and different constant costs 1
// vowel and consonant costs 3

public class SequenceAlignment {
    final int delta = 2;
    String one, two;
    int[][] chart;
    int[][] traceback;
    


    public SequenceAlignment(String strOne, String strTwo)
    {
        one = strOne;
        two = strTwo;

        chart = new int[one.length()+1][two.length()+1];
        traceback = new int[one.length()+1][two.length()+1];

        // computeAlignment(2);
        // System.out.println(getAlignment());
    }

    

    public int getMin(int left, int up, int diagonal, int[][] trace, int i, int j)
    {
        int alpha = alphaCalculator(one.charAt(i-1),two.charAt(j-1));
        int leftNum = left + delta, upNum = up + delta, diagonalNum = alpha + diagonal;
        int min = Math.min(diagonalNum, Math.min(upNum, leftNum));
        // System.out.println("===============");
        // System.out.println(min);
        // System.out.println("===============");

        if(min == diagonalNum)
        {
            trace[i][j] = 3; // 3 means took from the diagonal value
            return diagonalNum;
        }
        else if(min == upNum)
        {
            trace[i][j] = 2; // 2 means took from the up value
            return upNum; // getting from the top skips a letter from the left to right word, or two
        }
        else if(min == leftNum)
        {
            trace[i][j] = 1; // 1 means took from the left value
            return leftNum; // getting from the left skips a letter from the up and down word, or one
        }
        return 1000000; // something went wrong
    }

    public int alphaCalculator(char cOne, char cTwo)
    {
        if(isVowel(cOne) && isVowel(cTwo))
        {
            if(cOne == cTwo)
                return 0; // same vowels
            else
                return 1; // vowel and different vowel
        }
        else if(isVowel(cOne) != isVowel(cTwo))
            return 3; // one of them is true, one vowel one consonant
        else
        {
            if(cOne == cTwo)
                return 0; // same consonant
            else
                return 1; // consonant and different consonant
        }
    }

    public boolean isVowel(char letter)
    {
        if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
            return true;
        
        return false;
    }

    public void computeAlignment(int somethingforsomereason)
    {
        for(int i = 0; i < one.length()+1; i++)
        {
            chart[i][0] = delta*i;
        }
        for(int j = 0; j < two.length()+1; j++)
        {
            chart[0][j] = delta*j;
        }

        for(int i = 1; i < one.length()+1; i++) // i is our row position in the int chart
        {
            for(int j = 1; j < two.length()+1; j++) // j is our column position in the int chart
            {
                chart[i][j] = getMin(chart[i-1][j], chart[i][j-1], chart[i-1][j-1], traceback, i, j);
            }
        }
        // printChart(chart);
        // System.out.println("================");
        // printChart(traceback);
    }

    public String getAlignment()
    {
        String strOne = "", strTwo = "";

        for(int i = one.length(), j = two.length(); i > 0 && j > 0; )
        {
            if(traceback[i][j] == 3) // 3 is diagonal
            {
                strOne = one.charAt(i-1) + strOne;
                strTwo = two.charAt(j-1) + strTwo;
                i--;
                j--;
            }
            else if(traceback[i][j] == 2) // 2 is up
            {
                strOne = "-" + strOne;
                strTwo = two.charAt(j-1) + strTwo;
                j--;
            }
            else if(traceback[i][j] == 1) // 1 is left
            {
                strOne = one.charAt(i-1) + strOne;
                strTwo = "-" + strTwo;
                i--;
            }
        }

        return strOne + " " + strTwo;
    }

    public void printChart(int[][] chart)
    {
        for(int i = 0; i < chart.length; i++)
        {
            for(int j = 0; j < chart[i].length; j++)
            {
                System.out.print(chart[i][j]);
            }
            System.out.println();
        }
    }

    // public static void main(String[] args)
    // {
    //     SequenceAlignment k = new SequenceAlignment("four", "for");
    //     System.out.println("should be: four fo-r");
    // }
}
