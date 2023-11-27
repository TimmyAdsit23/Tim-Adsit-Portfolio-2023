// Sean Szumlanski
// COP 3330, Spring 2023

// ========================
// Garland: TestCase12.java
// ========================
// A test of the Garland(String [] strings) constructor. Manually checks the
// structure of the resulting linked list.


public class TestCase12
{
	public static void main(String [] args)
	{
		String [] strings = new String[] { "the", "whole", "opinionated", "din" };
		Garland g = new Garland(strings);

		System.out.println(g.head().data);
		System.out.println(g.head().down.data);
		System.out.println(g.head().down.down.data);
		System.out.println(g.head().down.down.down);

		System.out.println(g.head().next.data);
		System.out.println(g.head().next.down.data);
		System.out.println(g.head().next.down.down.data);
		System.out.println(g.head().next.down.down.down.data);
		System.out.println(g.head().next.down.down.down.down.data);
		System.out.println(g.head().next.down.down.down.down.down);

		System.out.println(g.head().next.next.data);
		System.out.println(g.head().next.next.down.data);
		System.out.println(g.head().next.next.down.down.data);
		System.out.println(g.head().next.next.down.down.down.data);
		System.out.println(g.head().next.next.down.down.down.down.data);
		System.out.println(g.head().next.next.down.down.down.down.down.data);
		System.out.println(g.head().next.next.down.down.down.down.down.down.data);
		System.out.println(g.head().next.next.down.down.down.down.down.down.down.data);
		System.out.println(g.head().next.next.down.down.down.down.down.down.down.down.data);
		System.out.println(g.head().next.next.down.down.down.down.down.down.down.down.down.data);
		System.out.println(g.head().next.next.down.down.down.down.down.down.down.down.down.down.data);
		System.out.println(g.head().next.next.down.down.down.down.down.down.down.down.down.down.down);


		System.out.println(g.head().next.next.next.data);
		System.out.println(g.head().next.next.next.down.data);
		System.out.println(g.head().next.next.next.down.down.data);
		System.out.println(g.head().next.next.next.down.down.down);

		System.out.println(g.head().next.next.next.next);
	}
}
