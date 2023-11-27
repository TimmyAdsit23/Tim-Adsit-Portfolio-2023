// Sean Szumlanski
// COP 3330, Spring 2023

// =============================
// PotionMaster: TestCase22.java
// =============================
// A test for the canBrewPotion(String, Map, Set) method.


import java.util.*;

public class TestCase22
{
	// Returns a PotionInfo list with the desired potions for this test case.
	private static List<PotionInfo> getPotionsManual()
	{
		ArrayList<PotionInfo> potionsManual = new ArrayList<>();

		potionsManual.add(PotionInfo.PYGMY_OIL());
		potionsManual.add(PotionInfo.FLASK_OF_PURE_MOJO());
		potionsManual.add(PotionInfo.LEZNUPARS_DRAUGHT());
		potionsManual.add(PotionInfo.GURUS_ELIXIR());

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
		if (map.size() != 4)
			return false;

		if (!map.containsKey("Pygmy Oil") ||
		    !map.containsKey("Flask of Pure Mojo") ||
		    !map.containsKey("Leznupar's Draught") ||
		    !map.containsKey("Guru's Elixir"))
			return false;

		Set<String> set;

		// Check map for Pygmy Oil.
		set = map.get("Pygmy Oil");
		if (set.size() != 1)
			return false;
		if (!set.contains("Pygmy Suckerfish"))
			return false;

		// Check map for Flask of Pure Mojo.
		set = map.get("Flask of Pure Mojo");
		if (set.size() != 3)
			return false;
		if (!set.contains("Icethorn") ||
		    !set.contains("Pygmy Oil") ||
		    !set.contains("Frost Lotus"))
			return false;

		// Check map for Leznupar's Draught.
		set = map.get("Leznupar's Draught");
		if (set.size() != 5)
			return false;
		if (!set.contains("Wax from a Partially Burned Candle") ||
		    !set.contains("Frost Lotus") ||
		    !set.contains("Phoenix Feather") ||
		    !set.contains("12-ounce Can of Root Beer") ||
		    !set.contains("Rain from a Category 3 Hurricane"))
			return false;

		// Check map for Guru's Elixir.
		set = map.get("Guru's Elixir");
		if (set.size() != 1)
			return false;
		if (!set.contains("Pygmy Oil"))
			return false;

		return true;
	}

	// Test Case: Many reagents required, many reagents (but not all required reagents) on hand.
	public static void main(String [] args)
	{
		// Set up potion name and potion -> reagents map.
		String potion = "Leznupar's Draught";
		Map<String, Set<String>> map = getTestCaseMap();

		// Set up list of reagents on hand.
		Set<String> reagents = new HashSet<>();
		reagents.add("Icethorn");
		reagents.add("12-ounce Can of Root Beer");
		reagents.add("Vial of Unicorn Tears");
		reagents.add("Pygmy Oil");
		reagents.add("Frost Lotus");
		reagents.add("Phoenix Feather");
		reagents.add("Rain from a Category 4 Hurricane");
		reagents.add("Wax from a Partially Burned Candle");
		reagents.add("Black Lotus");

		// Note: We CANNOT brew Leznupar's Draught.
		boolean result = PotionMaster.canBrewPotion(potion, map, reagents);
		System.out.println((result == false) ? "Hooray!" : "oh no :(");
	}
}
