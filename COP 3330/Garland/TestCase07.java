// Sean Szumlanski
// COP 3330, Spring 2023

// ========================
// Garland: TestCase07.java
// ========================
// A test of the addString() method. Manually checks the structure of the
// resulting linked list(s).


public class TestCase07
{
	public static void main(String [] args)
	{
		Garland g = new Garland();
		g.addString("the");
		g.addString("whole");
		g.addString("opinionated");
		g.addString("din");

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
