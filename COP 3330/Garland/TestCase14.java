// Sean Szumlanski
// COP 3330, Spring 2023

// ========================
// Garland: TestCase14.java
// ========================
// A small test of the printStrings() and printString(int index) methods.


public class TestCase14
{
	public static void main(String [] args)
	{
		Garland g = new Garland();
		g.addString("din");

		System.out.println("=================");
		System.out.println("g.printStrings():");
		System.out.println("=================");
		g.printStrings();

		System.out.println();
		System.out.println("=================");
		System.out.println("g.printString(i):");
		System.out.println("=================");
		for (int i = -3; i <= 3; i++)
		{
			System.out.println("String at index " + i + ":");
			g.printString(i);
			System.out.println();
		}
	}
}
