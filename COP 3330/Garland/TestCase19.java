// Sean Szumlanski
// COP 3330, Spring 2023

// ========================
// Garland: TestCase19.java
// ========================
// A small test of the getString() method.


public class TestCase19
{
	public static void main(String [] args)
	{
		Garland g = new Garland();
		g.addString("benevolence");
		g.addString("beatific");
		g.addString("bravado");

		System.out.println("size: " + g.size());

		for (int i = 0; i < g.size(); i++)
			System.out.println(g.getString(i));

		for (int i = g.size() - 1; i >= 0; i--)
			System.out.println(g.getString(i));
	}
}
