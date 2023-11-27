import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

public class MagicMaze2 {
    
    
    String name;
    int numRows, numCols; // x and y were here
    char[][] map;
    boolean[][] visitedMap;
    ArrayList<Integer>[] xs = new ArrayList[10];
    ArrayList<Integer>[] ys = new ArrayList[10];


    public MagicMaze2(String name, int rows, int cols)
    {
        this.name = name;
        this.numRows = rows;
        this.numCols = cols;
        this.map = new char[numRows][numCols];
        this.visitedMap = new boolean[numRows][numCols];

        // read the maze
        readMaze(name);

        // put the coordinates in the bottom left corner
        // x = 0;
        // y = numRows-1;
    }

    public boolean canMove(int row, int col){
        // System.out.println("row: " + row + "\nthis.numRows: " + this.numRows);
        // System.out.println("col: " + col + "\nthis.numCols: " + this.numCols);
        if((row < 0 || row >= this.numRows) || (col < 0 || col >= this.numCols))
            return false;
        else if(visitedMap[row][col])
        {
            return false;
        }
        else if(map[row][col] == '@')
        {
            return false;
        }
        else
        {
            // System.out.println("vistedMap[" + row + "][" + col + "]: " + visitedMap[row][col]);
            // System.out.println("map[" + row + "][" + col + "]: " + map[row][col]);
            return true;
        }
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
            xs[i] = new ArrayList<>();
            ys[i] = new ArrayList<>();
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
        // System.out.println("new rSolveMagicMaze");
        this.visitedMap[row][col] = true;
        int teleNum = map[row][col] - '0';

        // printMaze(row, col);

        
        if(teleNum > -1 && teleNum < 10)
        {
            for(int i = 0; i < xs[teleNum].size(); i++)
                if(canMove(ys[teleNum].get(i), xs[teleNum].get(i)))
                    if(rSolveMagicMaze(ys[teleNum].get(i), xs[teleNum].get(i)))
                        return true;
        }

        if(map[row][col] == 'X')
        {
            return true;
        }
        if(canMove(row+1, col)) // down one
        {
            // System.out.println("Doing a down one");
            // y = row+1;
            // x = col;


            if(rSolveMagicMaze(row+1, col))
                return true;
        }
        if(canMove(row, col+1)) // right one
        {
            // System.out.println("Doing a right one");
            // y = row;
            // x = col+1;

            
            if(rSolveMagicMaze(row, col+1))
                return true;
        }
        if(canMove(row-1, col)) // up one
        {
            // System.out.println("Doing a up one");
            // y = row-1;
            // x = col;

            
            if(rSolveMagicMaze(row-1, col))
                return true;
        }
        if(canMove(row, col-1)) // left one
        {
            // System.out.println("Doing a left one");
            // y = row;
            // x = col-1;

            
            if(rSolveMagicMaze(row, col-1))
                return true;
        }

        // visitedMap[row][col] = false;
        return false;
    }

    

    // public void printMaze(int row, int col)
    // {
    //     System.out.println("=======================");
    //     for(int i = 0; i < numRows; i++)
    //     {
    //         for(int j = 0; j < numCols; j++)
    //         {
    //             if(i == row && j == col)
    //             {
    //                 System.out.print("K");
    //             }
    //             else
    //                 System.out.print(map[i][j]);
    //         }
    //         System.out.println();
    //     }
    // }

    // public static void main(String[] args)
    // {
    //     MagicMaze stuff = new MagicMaze("maze2.txt", 11, 15);
    //     // System.out.println("x: " + stuff.x + "\ny: " + stuff.y);
        
    //     if(stuff.solveMagicMaze())
    //         System.out.println("true!");
    //     else
    //         System.out.println("false!");
    // 
}
