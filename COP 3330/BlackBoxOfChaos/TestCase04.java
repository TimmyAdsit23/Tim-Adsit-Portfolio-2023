// Sean Szumlanski
// COP 3330, Spring 2023

// ================================
// BlackBoxOfChaos: TestCase04.java
// ================================
// A small test to see whether the BlackBoxOfChaos class is generic and can
// hold strings.


public class TestCase04
{
	public static void main(String [] args)
	{
		BlackBoxOfChaos<String> box = new BlackBoxOfChaos<>(10, 2984834, 1787519, 844421);

		box.emplace("a");
		box.emplace("glooming");
		box.emplace("peace");
		box.emplace("this");
		box.emplace("morning");
		box.emplace("with");
		box.emplace("it");
		box.emplace("brings");
		box.emplace("the");
		box.emplace("sun");
		box.emplace("for");
		box.emplace("sorrow");
		box.emplace("will");
		box.emplace("not");
		box.emplace("show");
		box.emplace("its");
		box.emplace("head");

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
