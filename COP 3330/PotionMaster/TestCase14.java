// Sean Szumlanski
// COP 3330, Spring 2023

// =============================
// PotionMaster: TestCase14.java
// =============================
// A small test for the canBrewPotion(PotionInfo, Set) method.


import java.util.*;

public class TestCase14
{
	// Test Case: Many reagents required, many reagents (wrong reagents) on hand.
	public static void main(String [] args)
	{
		PotionInfo potion = PotionInfo.LEZNUPARS_DRAUGHT();
		Set<String> reagents = new HashSet<>();

		reagents.add("Icethorn");
		reagents.add("Vial of Unicorn Tears");
		reagents.add("Flask of Pure Mojo");
		reagents.add("Black Box of Chaos");
		reagents.add("Pygmy Oil");
		reagents.add("Frost Lotus");
		reagents.add("Leznupar's Draught");
		reagents.add("Pygmy Oil");
		reagents.add("Milkweed Seed");

		// Note: We CANNOT brew Leznupar's Draught.
		boolean result = PotionMaster.canBrewPotion(potion, reagents);
		System.out.println((result == false) ? "Hooray!" : "oh no :(");
	}
}
