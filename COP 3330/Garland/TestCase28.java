// Sean Szumlanski
// COP 3330, Spring 2023

// ========================
// Garland: TestCase28.java
// ========================
// A test case with multiple Garland objects.


import java.util.Arrays;

public class TestCase28
{
	public static void main(String [] args)
	{
		String [] strings;

		strings = new String[] {"a", "glooming", "peace", "this", "morning", "with", "it", "brings"};
		Garland g1 = new Garland(strings);
		Arrays.fill(strings, "");

		strings = new String[] {"the", "sun", "for", "sorrow", "will", "not", "show", "his", "head"};
		Garland g2 = new Garland(strings);
		Arrays.fill(strings, "");

		System.out.println("===========");
		System.out.println("Garland g1:");
		System.out.println("===========");
		g1.printStrings();

		System.out.println();
		System.out.println("===========");
		System.out.println("Garland g2:");
		System.out.println("===========");
		g2.printStrings();
	}
}
