// Sean Szumlanski
// COP 3330, Spring 2023

// ========================
// Garland: TestCase15.java
// ========================
// A small test of the printStrings() and printString(int index) methods.


public class TestCase15
{
	public static void main(String [] args)
	{
		Garland g = new Garland();
		g.addString("the");
		g.addString("whole");
		g.addString("opinionated");
		g.addString("din");

		System.out.println("=================");
		System.out.println("g.printStrings():");
		System.out.println("=================");
		g.printStrings();

		System.out.println();
		System.out.println("=================");
		System.out.println("g.printString(i):");
		System.out.println("=================");
		for (int i = -3; i <= 5; i++)
		{
			System.out.println("String at index " + i + ":");
			g.printString(i);
			System.out.println();
		}
	}
}
