// Sean Szumlanski
// COP 3330, Spring 2023

// ========================
// Garland: TestCase24.java
// ========================
// A small test of the removeString() method.


public class TestCase24
{
	public static void main(String [] args)
	{
		Garland g = new Garland();
		g.addString("benevolence");
		g.addString("beatific");
		g.addString("bravado");

		int toRemove = 1;

		System.out.println("=========================");
		System.out.println("Before g.removeString(" + toRemove + "):");
		System.out.println("=========================");
		System.out.println("size: " + g.size());
		for (int i = 0; i < g.size(); i++)
			System.out.println(g.getString(i));

		// Should return true for successful removal.
		boolean b = g.removeString(toRemove);
		System.out.println();
		System.out.println("=============================");
		System.out.println("Status for g.removeString(" + toRemove + "):");
		System.out.println("=============================");
		System.out.println(b);

		System.out.println();
		System.out.println("========================");
		System.out.println("After g.removeString(" + toRemove + "):");
		System.out.println("========================");
		System.out.println("size: " + g.size());
		for (int i = 0; i < g.size(); i++)
			System.out.println(g.getString(i));
	}
}
