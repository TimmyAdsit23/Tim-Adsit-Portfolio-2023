// Sean Szumlanski
// COP 3330, Spring 2023

// ================================
// BlackBoxOfChaos: TestCase03.java
// ================================
// A small test to see whether the BlackBoxOfChaos class is generic and can
// hold integers. This uses different parameters for the chaotic spiral.


public class TestCase03
{
	public static void main(String [] args)
	{
		BlackBoxOfChaos<Integer> box = new BlackBoxOfChaos<>(10, 1984834, 6984931, 3984917);

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
