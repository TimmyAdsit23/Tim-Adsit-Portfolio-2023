// Sean Szumlanski
// COP 3330, Spring 2023

// ========================
// Garland: TestCase18.java
// ========================
// A small test of the getString() method.


public class TestCase18
{
	public static void main(String [] args)
	{
		Garland g = new Garland();
		g.addString("benevolence");
		g.addString("beatific");

		String str = g.getString(1);

		System.out.println(str);
		System.out.println(str.equals("beatific") ? "Hooray!" : "oh no :(");
	}
}
