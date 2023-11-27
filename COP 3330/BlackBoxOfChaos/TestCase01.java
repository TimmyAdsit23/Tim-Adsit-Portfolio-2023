// Sean Szumlanski
// COP 3330, Spring 2023

// ================================
// BlackBoxOfChaos: TestCase01.java
// ================================
// A brief test case to help ensure you've implemented the difficultyRating()
// and hoursSpent() methods correctly.
//
// For detailed compilation and testing instructions, see the assignment PDF.


public class TestCase01
{
	public static void main(String [] args)
	{
		double difficulty = BlackBoxOfChaos.difficultyRating();
		System.out.println((difficulty < 1.0 || difficulty > 5.0) ? "oh no :(" : "Hooray!");

		double hours = BlackBoxOfChaos.hoursSpent();
		System.out.println((hours <= 0.0) ? "oh no :(" : "Hooray!");
	}
}
