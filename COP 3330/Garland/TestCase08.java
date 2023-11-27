// Sean Szumlanski
// COP 3330, Spring 2023

// ========================
// Garland: TestCase08.java
// ========================
// A test of the addString() method. Manually checks the structure of the
// resulting linked list(s).


public class TestCase08
{
	public static void main(String [] args)
	{
		Garland g = new Garland();
		g.addString("liminal");

		System.out.println(g.head().data);
		System.out.println(g.head().down.data);
		System.out.println(g.head().down.down.data);
		System.out.println(g.head().down.down.down.data);
		System.out.println(g.head().down.down.down.down.data);
		System.out.println(g.head().down.down.down.down.down.data);
		System.out.println(g.head().down.down.down.down.down.down.data);
		System.out.println(g.head().down.down.down.down.down.down.down);

		System.out.println(g.head().next);
	}
}
