// Sean Szumlanski
// COP 3330, Spring 2023

// ========================
// Garland: TestCase16.java
// ========================
// A small test of the addString() and head() methods. Manually checks the
// structure of the resulting linked list(s).


public class TestCase16
{
	public static void main(String [] args)
	{
		Garland g = new Garland();

		g.addString("the");
		g.addString("pie");

		Node head = g.head();

		System.out.println(head.data);
		System.out.println(head.down.data);
		System.out.println(head.down.down.data);
		System.out.println(head.down.down.down);

		System.out.println(head.next.data);
		System.out.println(head.next.down.data);
		System.out.println(head.next.down.down.data);
		System.out.println(head.next.down.down.down);

		System.out.println(head.next.next);
	}
}
