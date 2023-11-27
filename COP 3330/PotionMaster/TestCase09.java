// Sean Szumlanski
// COP 3330, Spring 2023

// =============================
// PotionMaster: TestCase09.java
// =============================
// A small test for the canBrewPotion(PotionInfo, Set) method.


import java.util.*;

public class TestCase09
{
	// Test Case: One reagent required, one reagent (correct reagent) on hand.
	public static void main(String [] args)
	{
		PotionInfo potion = PotionInfo.PYGMY_OIL();
		Set<String> reagents = new HashSet<>();

		reagents.add("Pygmy Suckerfish");

		// Note: We CAN brew the Pygmy Oil.
		boolean result = PotionMaster.canBrewPotion(potion, reagents);
		System.out.println((result == true) ? "Hooray!" : "oh no :(");
	}
}
