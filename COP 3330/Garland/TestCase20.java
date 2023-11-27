// Sean Szumlanski
// COP 3330, Spring 2023

// ========================
// Garland: TestCase20.java
// ========================
// A small test of the getNode() and linkedListToString() methods.


public class TestCase20
{
	public static void main(String [] args)
	{
		Garland g = new Garland();
		g.addString("benevolence");

		Node node = g.getNode(0);
		String str = Garland.linkedListToString(node);

		System.out.println(str);
		System.out.println(str.equals("benevolence") ? "Hooray!" : "oh no :(");
	}
}
