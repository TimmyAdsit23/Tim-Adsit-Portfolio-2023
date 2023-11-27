// Sean Szumlanski
// COP 3330, Spring 2023

// ========================
// Garland: TestCase06.java
// ========================
// A small test of the linkedListToString() method.


public class TestCase06
{
	public static void main(String [] args)
	{
		String str = Garland.linkedListToString(null);
		System.out.println(str.equals("") ? "Hooray!" : "oh no :(");
	}
}
