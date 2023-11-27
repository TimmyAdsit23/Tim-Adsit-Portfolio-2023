// Sean Szumlanski
// COP 3330, Spring 2023

// =============================
// PotionMaster: TestCase11.java
// =============================
// A small test for the canBrewPotion(PotionInfo, Set) method.


import java.util.*;

public class TestCase11
{
	// Test Case: One reagent required, many reagents (including correct one) on hand.
	public static void main(String [] args)
	{
		PotionInfo potion = PotionInfo.GURUS_ELIXIR();
		Set<String> reagents = new HashSet<>();

		reagents.add("Icethorn");
		reagents.add("Vial of Unicorn Tears");
		reagents.add("Pygmy Oil");
		reagents.add("Frost Lotus");

		// Note: We CAN brew the Guru's Elixir.
		boolean result = PotionMaster.canBrewPotion(potion, reagents);
		System.out.println((result == true) ? "Hooray!" : "oh no :(");
	}
}
