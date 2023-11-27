// Sean Szumlanski
// COP 3330, Spring 2023

// ========================
// Garland: TestCase13.java
// ========================
// A small test of the printStrings() and printString(int index) methods.


public class TestCase13
{
	public static void main(String [] args)
	{
		Garland g = new Garland();
		g.printStrings();

		// These should all print "(invalid index)".
		for (int i = -3; i <= 3; i++)
			g.printString(i);
	}
}
