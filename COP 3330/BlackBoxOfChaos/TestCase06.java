// Sean Szumlanski
// COP 3330, Spring 2023

// ================================
// BlackBoxOfChaos: TestCase06.java
// ================================
// A small test in which a ChaosException is thrown.


public class TestCase06
{
	public static void main(String [] args)
	{
		BlackBoxOfChaos<Integer> box = new BlackBoxOfChaos<>(10, 12, 12, 12);
		box.emplace(1);
	}
}
