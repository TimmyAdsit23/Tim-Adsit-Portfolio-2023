// Sean Szumlanski
// COP 3330, Spring 2023

// =============================
// PotionMaster: TestCase08.java
// =============================
// A small test for the canBrewPotion(PotionInfo, Set) method.


import java.util.*;

public class TestCase08
{
	// Test Case: One reagent required, one reagent (wrong reagent) on hand.
	public static void main(String [] args)
	{
		PotionInfo potion = PotionInfo.PYGMY_OIL();
		Set<String> reagents = new HashSet<>();

		reagents.add("Icethorn");

		// Note: We CANNOT brew the Pygmy Oil.
		boolean result = PotionMaster.canBrewPotion(potion, reagents);
		System.out.println((result == false) ? "Hooray!" : "oh no :(");
	}
}
