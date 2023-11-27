// Sean Szumlanski
// COP 3330, Spring 2023

// ========================
// Garland: TestCase21.java
// ========================
// A small test of the getNode() and linkedListToString() methods.


public class TestCase21
{
	public static void main(String [] args)
	{
		Garland g = new Garland();
		g.addString("benevolence");
		g.addString("beatific");

		Node node = g.getNode(1);
		String str = Garland.linkedListToString(node);

		System.out.println(str);
		System.out.println(str.equals("beatific") ? "Hooray!" : "oh no :(");
	}
}
