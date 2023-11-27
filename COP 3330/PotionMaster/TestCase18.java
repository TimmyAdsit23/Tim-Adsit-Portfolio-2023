// Sean Szumlanski
// COP 3330, Spring 2023

// =============================
// PotionMaster: TestCase18.java
// =============================
// A small test for the canBrewPotion(String, Map, Set) method.


import java.util.*;

public class TestCase18
{
	// Returns a PotionInfo list with the desired potions for this test case.
	private static List<PotionInfo> getPotionsManual()
	{
		ArrayList<PotionInfo> potionsManual = new ArrayList<>();

		potionsManual.add(PotionInfo.PYGMY_OIL());

		return potionsManual;
	}

	// Attempts to build a map from this potions manual.
	private static Map<String, Set<String>> getTestCaseMap()
	{
		// Set up the potions manual for this particular test case.
		List<PotionInfo> potionsManual = getPotionsManual();

		// Build a potion -> reagents map from this potions manual.
		Map<String, Set<String>> map = PotionMaster.potionToReagentsMap(potionsManual);

		// Check that the resulting map has exactly the right contents.
		if (!checkMapContents(map))
		{
			System.out.println("Incorrect map. Aborting test case.");
			PotionInfo.printMap(map);

			// Kill the program.
			System.exit(1);
		}

		return map;
	}

	// Checks that the map was properly constructed for this test case.
	private static boolean checkMapContents(Map<String, Set<String>> map)
	{
		if (map.size() != 1)
			return false;

		if (!map.containsKey("Pygmy Oil"))
			return false;

		Set<String> set;

		// Check map for Pygmy Oil.
		set = map.get("Pygmy Oil");
		if (set.size() != 1)
			return false;
		if (!set.contains("Pygmy Suckerfish"))
			return false;

		return true;
	}

	// Test Case: One reagent required, one reagent (wrong reagent) on hand.
	public static void main(String [] args)
	{
		// Set up potion name and potion -> reagents map.
		String potion = "Pygmy Oil";
		Map<String, Set<String>> map = getTestCaseMap();

		// Set up list of reagents on hand.
		Set<String> reagents = new HashSet<>();
		reagents.add("Pygmy Suckerfish");

		// Note: We CAN brew the Pygmy Oil.
		boolean result = PotionMaster.canBrewPotion(potion, map, reagents);
		System.out.println((result == true) ? "Hooray!" : "oh no :(");
	}
}
