// Sean Szumlanski
// COP 3330, Spring 2023

// =============================
// PotionMaster: TestCase16.java
// =============================
// A small test for the canBrewPotion(PotionInfo, Set) method.


import java.util.*;

public class TestCase16
{
	// Test Case: Many reagents required, many reagents (including all required) on hand.
	public static void main(String [] args)
	{
		PotionInfo potion = PotionInfo.LEZNUPARS_DRAUGHT();
		Set<String> reagents = new HashSet<>();

		reagents.add("Icethorn");
		reagents.add("12-ounce Can of Root Beer");
		reagents.add("Vial of Unicorn Tears");
		reagents.add("Pygmy Oil");
		reagents.add("Frost Lotus");
		reagents.add("Phoenix Feather");
		reagents.add("Rain from a Category 3 Hurricane");
		reagents.add("Wax from a Partially Burned Candle");
		reagents.add("Black Lotus");

		// Note: We CAN brew Leznupar's Draught.
		boolean result = PotionMaster.canBrewPotion(potion, reagents);
		System.out.println((result == true) ? "Hooray!" : "oh no :(");
	}
}
