// Sean Szumlanski
// COP 3330, Spring 2023

// ========================
// Garland: TestCase05.java
// ========================
// A small test of the linkedListToString() method with a manually-constructed
// linked list.


public class TestCase05
{
	public static void main(String [] args)
	{
		Node head;

		head = new Node('s');
		head.down = new Node('p');
		head.down.down = new Node('i');
		head.down.down.down = new Node('n');
		head.down.down.down.down = new Node('d');
		head.down.down.down.down.down = new Node('l');
		head.down.down.down.down.down.down = new Node('e');

		String str = Garland.linkedListToString(head);

		System.out.println(str);
		System.out.println(str.equals("spindle") ? "Hooray!" : "oh no :(");
	}
}
