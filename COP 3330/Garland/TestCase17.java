// Sean Szumlanski
// COP 3330, Spring 2023

// ========================
// Garland: TestCase17.java
// ========================
// A small test of the getString() method.


public class TestCase17
{
	public static void main(String [] args)
	{
		Garland g = new Garland();
		g.addString("benevolence");

		String str = g.getString(0);

		System.out.println(str);
		System.out.println(str.equals("benevolence") ? "Hooray!" : "oh no :(");
	}
}
