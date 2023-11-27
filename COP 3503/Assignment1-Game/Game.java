/* Timothy Adsit
 * Dr. Steinberg
 * COP3503 Fall 2023
 * Programming Assignment 1
 */

import java.util.*;
import java.io.File;
import java.io.FileNotFoundException;

public class Game {
    int[][] board = new int[8][8];
    char[] moves = new char[99];
    int sizeForMethod = 8, x = 0, y;



    Game(int size, String fileNameP2)
    {
        this.sizeForMethod = size;
        y = size-1;
        readMoves(fileNameP2);
        
    }

    public void readMoves(String fileNameP2)
    {
        // r means right
        // b means down
        // d means diagonal
        Scanner fileReader;


        try
        {
            fileReader = new Scanner(new File(fileNameP2));
        } 
        catch(Exception e)
        {
            return;
        }

        
        for(int i = 0; fileReader.hasNextLine(); i++)
        {
            moves[i] = fileReader.nextLine().charAt(0);
            System.out.println(moves[i]);
        }
        
    }

    public int play(int whoWins)
    {
        // reset the game
        x = 0;
        y = sizeForMethod-1;

        if(whoWins == 1)
        {
            for(int i = 0; i < moves.length; i++)
            {

                // player 1's turn
                moveOptimally(board);

                if(x == sizeForMethod-1 && y == 0)
                {
                    return 1;
                }

                // player 2's turn
                movePiece(board, moves[i]);


                if(x == sizeForMethod-1 && y == 0)
                {
                    return 2;
                }
            }
            // if all goes wrong
            return 0;
        }
        else if(whoWins == 2)
        {
            // player 1 makes a misplay on their turn
            moveSuboptimally();

            // player 2 plays optimally
            moveOptimally(board);

            // they both now play optimally
            while(true)
            {
                // player 1's turn
                moveOptimally(board);

                if(x == sizeForMethod-1 && y == 0)
                {
                    return 1;
                }

                // player 2's turn
                moveOptimally(board);

                if(x == sizeForMethod-1 && y == 0)
                {
                    return 2;
                }
            }
        }
        // if all goes wrong
        return 0;
    }

    public void movePiece(int[][] board, char move)
    {
        // todo: take into account size
        board[x][y] = 0;

        if(move == 'r') 
            moveRight(board);
        else if(move == 'b')
            moveDown(board);
        else if(move == 'd')
            moveDiagonal(board);

        System.out.println("Moved piece");
        printBoard();
    }

    public void fillBoard()
    {
        for(int i = 0; i < sizeForMethod; i++)
        {
            for(int j = 0; j < sizeForMethod; j++)
            {
                board[i][j] = 0;
            }
        }
        board[0][sizeForMethod-1] = 1;
    }

    public void printBoard()
    {
        for(int j = sizeForMethod-1; j >= 0; j--)
        {
            for(int i = 0; i < sizeForMethod; i++)
            {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }

    public void moveOptimally(int[][] board)
    {
        // move to an odd x index
        // move to an even y index

        boolean moveRight = false;
        boolean moveDown = false;

        if(x % 2 == 0)
            moveRight = true;

        if(y % 2 == 1)
            moveDown = true;

        if(moveDown && moveRight)
            moveDiagonal(board);
        else if(moveRight)
            moveRight(board);
        else if(moveDown)
            moveDown(board);
        else
            moveRight(board); // forced to move, even if suboptimal
    }
    
    // here is where I remembered that the board is a global variable
    public void moveSuboptimally()
    {
        // move to an even x index
        // move to an odd y index

        boolean moveRight = false;
        boolean moveDown = false;

        if(x + 1 % 2 == 0) // if moving right results in an even x index...
            moveRight = true;
        else if(y - 1 % 2 == 1) // if moving down results in an odd index...
            moveDown = true;
        
        if(moveRight)
            moveRight(board);
        else if(moveDown)
            moveDown(board);
    }

    public void moveDiagonal(int[][] board)
    {
        board[x][y] = 0;

        if(x == sizeForMethod-1) //if all the way to the right
            board[x][--y] = 1; // down one
        else if(y == 0) // if all the way down
            board[++x][y] = 1; // right one
        else
            board[++x][--y] = 1; // diagonal
    }

    public void moveDown(int[][] board)
    {
        board[x][y] = 0;

        if(y == 0) // if all the way down
            board[++x][y] = 1; // right one
        else
            board[x][--y] = 1; // down one
    }

    public void moveRight(int[][] board)
    {
        board[x][y] = 0;

        if(x == sizeForMethod-1) //if all the way to the right
            board[x][--y] = 1; // down one
        else
            board[++x][y] = 1; // right one
    }
}
