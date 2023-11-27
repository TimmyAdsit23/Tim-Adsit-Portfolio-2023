// Sean Szumlanski
// COP 3330, Spring 2023

// ========================
// Garland: TestCase10.java
// ========================
// A small test of the Garland() constructor and the addString() method.


public class TestCase10
{
	public static void main(String [] args)
	{
		Garland g = new Garland();
		g.addString("");

		System.out.println("head: " + g.head());
		System.out.println("size: " + g.size());
	}
}
