// Tim Adsit
// COP 3330, Spring 2023
// ti047614


/*

public class Node
{
    char data; // Each node holds a single character.

    Node next; // Reference to next string's first node (provided we are at
    // the first node in some string; if not, this is null).

    Node down; // Reference to node with the next character in this string.
    // This is the only available constructor for this class.

    Node(char data)
    {
        this.data = data;
    }


}

 */


// draw pictures for everything very carefully
// print memory addresses and check


public class Garland 
{
    
    private Node head; // Reference to the top-left node in this garland.
    private int size; // The number of strings currently in this garland

    public static Node stringToLinkedList(String s)
    {
        if(s == null || s.length() == 0)
            return null;
        
        Node a = new Node(s.charAt(0));
        a.down = stringToLinkedList(s.substring(1, s.length()));
        return a;
    }

    public static String linkedListToString(Node head)
    {
        int sizeOfLinkedList = 0;
        Node next = head;
        while(next != null)
        {
            next = next.down;
            sizeOfLinkedList++;
        }

        char [] string = new char[sizeOfLinkedList];
        next = head;

        for(int i = 0; i < sizeOfLinkedList; i++)
        {
            string[i] = next.data;
            next = next.down;
        }

        return new String(string);
    }

    Garland()
    {
        this.head = null;
        this.size = 0;
    }

    Garland(String [] strings)
    {
        Node tail = head;
        
        for(int i = 0; i < strings.length; i++)
        {
            tail = addString(strings[i], tail);
        }
    }

    public Node head()
    {
        return this.head;
    }

    public int size()
    {
        return this.size;
    }

    // add a string to the end of the garland. if it is empty, make a new head of the garland
    // if it is not, place at the end of the garland.
    public void addString(String s)
    {
        if(s == null || s.length() == 0)
            return;
        
        if(this.size == 0)
        {
            this.head = stringToLinkedList(s);
        }
        else
        {
            Node newStringHead = this.head;
            while(newStringHead.next != null)
            {
                newStringHead = newStringHead.next;
            }

            newStringHead.next = stringToLinkedList(s);
        }

        this.size++;
    }

    // overloaded addString since the default one sucks. Tail pointer supremecy ftw
    public Node addString(String s, Node tail)
    {
        if(s == null || s.length() == 0)
            return null;

        Node newTail;

        if(tail == null)
        {
            this.head = stringToLinkedList(s);
            newTail = this.head;
        }
        else
        {
            tail.next = stringToLinkedList(s);
            newTail = tail.next;
        }

        this.size++;
        return newTail;
    }

    public Node getNode(int index)
    {
        if(!validIndex(index))
            return null;
        
        Node nodeToFind = this.head;

        for(int i = 0; i < index; i++)
        {
            nodeToFind = nodeToFind.next;
        }

        return nodeToFind;
    }

    public String getString(int index)
    {
        if(!validIndex(index))
            return null;

        Node headOfString = getNode(index);

        return linkedListToString(headOfString);
    }

    public boolean removeString(int index)
    {
        if(!validIndex(index))
            return false;
        
        if(index == 0)
        {
            this.head = head.next;
        }
        else if(index == size-1)
        {
            Node iterator = this.head;

            // sets iterator to be the next to last node.
            while(iterator.next.next != null)
            {
                iterator = iterator.next;
            }

            // get rid of the last node
            iterator.next = null;
        }
        else
        {
            // cuts out the index to be removed by garbage collector. It is a valued member of
            // coding society.
            getNode(index-1).next = getNode(index+1);
        }

        this.size--;
        return true;
    }

    public boolean printString(int index)
    {
        if(!validIndex(index))
        {
            System.out.println("(invalid index)");
            return false;
        }
        
        System.out.println(linkedListToString(getNode(index)));

        return true;
    }

    public void printStrings()
    {
        if(this.size == 0)
        {
            System.out.println("(empty list)");
            return;
        }

        Node stuff = this.head;
        Node headIterator = this.head;

        while(headIterator != null)
        {
            while(stuff != null)
            {
                System.out.print(stuff.data);
                stuff = stuff.down;
            }
            System.out.println();
            headIterator = headIterator.next;
            stuff = headIterator;
        }
    }

    public static double difficultyRating()
    {
        return 1.5;
    }

    public static double hoursSpent()
    {
        return 2;
    }

    // helper methods
    public boolean validIndex(int index)
    {
        if(index < 0 || index >= this.size)
            return false;
        return true;
    }


// public static void main(String [] args)
// {
//     Node head = Garland.stringToLinkedList("plum");

//     System.out.println(head.data);
//     System.out.println(head.down.data);
//     System.out.println(head.down.down.data);
//     System.out.println(head.down.down.down.data);
//     System.out.println(head.down.down.down.down);
//     System.out.println(head.next);

// }

}
