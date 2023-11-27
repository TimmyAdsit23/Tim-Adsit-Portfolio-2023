// Sean Szumlanski
// COP 3330, Spring 2023

// =============================
// PotionMaster: TestCase13.java
// =============================
// A small test for the canBrewPotion(PotionInfo, Set) method.


import java.util.*;

public class TestCase13
{
	// Test Case: Many reagents required, one reagent (one of the required reagents) on hand.
	public static void main(String [] args)
	{
		PotionInfo potion = PotionInfo.LEZNUPARS_DRAUGHT();
		Set<String> reagents = new HashSet<>();

		reagents.add("Rain from a Category 3 Hurricane");

		// Note: We CANNOT brew Leznupar's Draught.
		boolean result = PotionMaster.canBrewPotion(potion, reagents);
		System.out.println((result == false) ? "Hooray!" : "oh no :(");
	}
}
