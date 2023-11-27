// Sean Szumlanski
// COP 3330, Spring 2023

// ========================
// Garland: TestCase02.java
// ========================
// A small test of the stringToLinkedList() method. Manually checks the
// structure of the resulting linked list.


public class TestCase02
{
	public static void main(String [] args)
	{
		Node head = Garland.stringToLinkedList("plum");

		System.out.println(head.data);
		System.out.println(head.down.data);
		System.out.println(head.down.down.data);
		System.out.println(head.down.down.down.data);
		System.out.println(head.down.down.down.down);

		System.out.println(head.next);
	}
}
