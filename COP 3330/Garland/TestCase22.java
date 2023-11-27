// Sean Szumlanski
// COP 3330, Spring 2023

// ========================
// Garland: TestCase22.java
// ========================
// A small test of the addString(), size(), getNode(), and linkedListToString()
// methods.


public class TestCase22
{
	public static void main(String [] args)
	{
		Garland g = new Garland();
		g.addString("benevolence");
		g.addString("beatific");
		g.addString("bravado");

		System.out.println("size: " + g.size());

		for (int i = 0; i < g.size(); i++)
			System.out.println(Garland.linkedListToString(g.getNode(i)));

		for (int i = g.size() - 1; i >= 0; i--)
			System.out.println(Garland.linkedListToString(g.getNode(i)));
	}
}
