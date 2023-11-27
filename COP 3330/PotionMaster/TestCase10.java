// Sean Szumlanski
// COP 3330, Spring 2023

// =============================
// PotionMaster: TestCase10.java
// =============================
// A small test for the canBrewPotion(PotionInfo, Set) method.


import java.util.*;

public class TestCase10
{
	// Test Case: One reagent required, many reagents (wrong reagents) on hand.
	public static void main(String [] args)
	{
		PotionInfo potion = PotionInfo.GURUS_ELIXIR();
		Set<String> reagents = new HashSet<>();

		reagents.add("Icethorn");
		reagents.add("Vial of Unicorn Tears");
		reagents.add("Charred Stardust");
		reagents.add("Frost Lotus");

		// Note: We CANNOT brew the Guru's Elixir.
		boolean result = PotionMaster.canBrewPotion(potion, reagents);
		System.out.println((result == false) ? "Hooray!" : "oh no :(");
	}
}
