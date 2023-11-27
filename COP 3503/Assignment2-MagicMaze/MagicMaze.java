/* Timothy Adsit
 * Dr. Steinberg
 * COP3503 Fall 2023
 * Programming Assignment 2
 */

import java.io.File;
import java.util.*;

public class MagicMaze{
    
    String name;
    int numRows, numCols; 
    char[][] map;
    boolean[][] visitedMap;
    ArrayList<Integer>[] xs = new ArrayList[10];
    ArrayList<Integer>[] ys = new ArrayList[10];


    public MagicMaze(String name, int rows, int cols)
    {
        this.name = name;
        this.numRows = rows;
        this.numCols = cols;
        this.map = new char[numRows][numCols];
        this.visitedMap = new boolean[numRows][numCols];

        // read the maze
        readMaze(name);
    }

    public boolean canMove(int row, int col)
    {
        if((row < 0 || row >= this.numRows) || (col < 0 || col >= this.numCols))
            return false;
        else if(visitedMap[row][col])
            return false;
        else if(map[row][col] == '@')
            return false;
        else
            return true;
    }

    

    public void readMaze(String fileName)
    {
        Scanner k;

        try
        {
            k = new Scanner(new File(fileName));
        } 
        catch(Exception e)
        {
            return;
        }

        String rowOfMaze;
        int i = 0;
        
        
        while(k.hasNextLine())
        {
            rowOfMaze = k.nextLine();
            for(int j = 0; j < rowOfMaze.length(); j++)
            {
                map[i][j] = rowOfMaze.charAt(j);
            }
            i++;
        }

        k.close();

        int teleNum;

        for(i = 0; i < 10; i++)
        {
            xs[i] = new ArrayList<Integer>(); //******* */
            ys[i] = new ArrayList<Integer>();
        }

        for(i = 0; i < numRows; i++)
                for(int j = 0; j < numCols; j++)
                {
                    teleNum = map[i][j] - '0';
                    if(teleNum > -1 && teleNum < 10)
                    {
                        xs[teleNum].add(j);
                        ys[teleNum].add(i);
                    }
                }


    }

    public boolean solveMagicMaze()
    {
        return rSolveMagicMaze(numRows-1, 0);
    }

    public boolean rSolveMagicMaze(int row, int col)
    {
        this.visitedMap[row][col] = true;
        int teleNum = map[row][col] - '0';


        
        if(teleNum > -1 && teleNum < 10)
            for(int i = 0; i < xs[teleNum].size(); i++)
                if(canMove(ys[teleNum].get(i), xs[teleNum].get(i)))
                    if(rSolveMagicMaze(ys[teleNum].get(i), xs[teleNum].get(i)))
                        return true;

        if(map[row][col] == 'X')
            return true;
        if(canMove(row+1, col)) // down one
            if(rSolveMagicMaze(row+1, col))
                return true;
        if(canMove(row, col+1)) // right one
            if(rSolveMagicMaze(row, col+1))
                return true;
        if(canMove(row-1, col)) // up one
            if(rSolveMagicMaze(row-1, col))
                return true;
        if(canMove(row, col-1)) // left one
            if(rSolveMagicMaze(row, col-1))
                return true;

        return false;
    }
}
