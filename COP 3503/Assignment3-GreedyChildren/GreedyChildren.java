/* Timothy Adsit
 * Dr. Steinberg
 * COP3503 Fall 2023
 * Programming Assignment 3
 */


import java.io.File;
import java.util.*;

public class GreedyChildren {
    ArrayList<Integer> candySweet = new ArrayList<Integer>();
    ArrayList<Integer> childrenGreed = new ArrayList<Integer>();
    int happy = 0;
    int angry = 0;
    int numCandy, numChildren;
    String fileGreed, fileSweet;

    public GreedyChildren(int numCandy, int numChildren, String fileGreed, String fileSweet)
    {
        this.numCandy = numCandy;
        this.numChildren = numChildren;
        this.fileGreed = fileGreed;
        this.fileSweet = fileSweet;
    }

    public void read(String fileGreed, String fileSweet)
    {
        Scanner greed;
        Scanner sweet;


        try
        {
            greed = new Scanner(new File(fileGreed));
            sweet = new Scanner(new File(fileSweet));
        } 
        catch(Exception e)
        {
            return;
        }

        for(int i = 0; i < this.numCandy; i++)
            this.candySweet.add(sweet.nextInt());

        for(int i = 0; i < this.numChildren; i++)
            this.childrenGreed.add(greed.nextInt());
        

        greed.close();
        sweet.close();
    }

    public void greedyCandy()
    {
        read(fileGreed, fileSweet);

        // sorted both from least to greatest

        Collections.sort(this.candySweet);
        Collections.sort(this.childrenGreed);

        // reversed, now sorted from greatest to least

        Collections.reverse(candySweet); 
        Collections.reverse(childrenGreed);

        int candyIndex = 0;

        for(int i = 0; i < this.numChildren; i++) // for every kid
        {
            if(this.candySweet.get(candyIndex) >= this.childrenGreed.get(i)) // if the sweetness is enough
            {
                this.happy++;
                candyIndex++; // go to next candy
            }
            else // sweetness wasnt enough
            {
                this.angry++;
            }
            
        }
    }

    public void display()
    {
        System.out.println("There are " + happy + " happy children.");
        System.out.println("There are " + angry + " angry children.");
    }


}
