// Sean Szumlanski
// COP 3330, Spring 2023

// ================================
// BlackBoxOfChaos: TestCase02.java
// ================================
// A small test to see whether the BlackBoxOfChaos class is generic and can
// hold integers.


public class TestCase02
{
	public static void main(String [] args)
	{
		BlackBoxOfChaos<Integer> box = new BlackBoxOfChaos<>(10, 2984834, 1787519, 844421);

		for (int i = 0; i < 20; i++)
			box.emplace(i);

		System.out.println();
		System.out.println("Contents:");
		System.out.println("=========");
		box.printContents();

		System.out.println();
		System.out.println("Contents:");
		System.out.println("=========");
		box.printContents();

		System.out.println();
		System.out.println("Contents:");
		System.out.println("=========");
		box.printContents();

		System.out.println();
		System.out.println("Contents:");
		System.out.println("=========");
		box.printContents();

		System.out.println();
		System.out.println("size: " + box.getSize());
	}
}
