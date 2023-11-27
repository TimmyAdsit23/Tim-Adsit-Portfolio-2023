// Sean Szumlanski
// COP 3330, Spring 2023

// ========================
// Garland: TestCase27.java
// ========================
// A small test of the removeString() method.


public class TestCase27
{
	public static void main(String [] args)
	{
		Garland g = new Garland();
		g.addString("benevolence");
		g.addString("beatific");
		g.addString("bravado");

		System.out.println("================");
		System.out.println("Before removals:");
		System.out.println("================");
		System.out.println("size: " + g.size());
		for (int i = 0; i < g.size(); i++)
			System.out.println(g.getString(i));

		g.removeString(1);
		g.removeString(0);

		System.out.println();
		System.out.println("===============");
		System.out.println("After removals:");
		System.out.println("===============");
		System.out.println("size: " + g.size());
		for (int i = 0; i < g.size(); i++)
			System.out.println(g.getString(i));
	}
}
