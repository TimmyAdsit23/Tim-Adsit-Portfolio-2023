// Sean Szumlanski
// COP 3330, Spring 2023

// =============================
// PotionMaster: TestCase25.java
// =============================
// A test for the allPossiblePotions() method. Note that this method should
// return an empty set (NOT a null reference) if there are no potions we can
// brew.


import java.util.*;

public class TestCase25
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

	// Attempts to build a potion -> reagents map from this potions manual.
	private static Map<String, Set<String>> getPotionToReagentsTestCaseMap()
	{
		// Set up the potions manual for this particular test case.
		List<PotionInfo> potionsManual = getPotionsManual();

		// Build a potion -> reagents map from this potions manual.
		Map<String, Set<String>> map = PotionMaster.potionToReagentsMap(potionsManual);

		// Check that the resulting map has exactly the right contents.
		if (!checkPotionToReagentsMapContents(map))
		{
			System.out.println("Incorrect map. Aborting test case.");
			PotionInfo.printMap(map);

			// Kill the program.
			System.exit(1);
		}

		return map;
	}

	// Attempts to build a reagent -> potions map from this potions manual.
	private static Map<String, Set<String>> getReagentToPotionsTestCaseMap()
	{
		// Set up the potions manual for this particular test case.
		List<PotionInfo> potionsManual = getPotionsManual();

		// Build a reagent -> potions map from this potions manual.
		Map<String, Set<String>> map = PotionMaster.reagentToPotionsMap(potionsManual);

		// Check that the resulting map has exactly the right contents.
		if (!checkReagentToPotionsMapContents(map))
		{
			System.out.println("Incorrect map. Aborting test case.");
			PotionInfo.printMap(map);

			// Kill the program.
			System.exit(1);
		}

		return map;
	}

	// Checks that the map was properly constructed for this test case.
	private static boolean checkPotionToReagentsMapContents(Map<String, Set<String>> map)
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

	private static boolean checkReagentToPotionsMapContents(Map<String, Set<String>> map)
	{
		if (map.size() != 8)
			return false;

		if (!map.containsKey("Pygmy Suckerfish") ||
			!map.containsKey("Icethorn") ||
			!map.containsKey("Pygmy Oil") ||
			!map.containsKey("Frost Lotus") ||
			!map.containsKey("Wax from a Partially Burned Candle") ||
			!map.containsKey("Phoenix Feather") ||
			!map.containsKey("12-ounce Can of Root Beer") ||
			!map.containsKey("Rain from a Category 3 Hurricane"))
			return false;

		Set<String> set;

		// Check map for Pygmy Suckerfish.
		set = map.get("Pygmy Suckerfish");
		if (set.size() != 1)
			return false;
		if (!set.contains("Pygmy Oil"))
			return false;

		// Check map for Icethorn.
		set = map.get("Icethorn");
		if (set.size() != 1)
			return false;
		if (!set.contains("Flask of Pure Mojo"))
			return false;

		// Check map for Pygmy Oil.
		set = map.get("Pygmy Oil");
		if (set.size() != 2)
			return false;
		if (!set.contains("Flask of Pure Mojo") || !set.contains("Guru's Elixir"))
			return false;

		// Check map for Frost Lotus.
		set = map.get("Frost Lotus");
		if (set.size() != 2)
			return false;
		if (!set.contains("Flask of Pure Mojo") || !set.contains("Leznupar's Draught"))
			return false;

		// Check map for Wax from a Partially Burned Candle.
		set = map.get("Wax from a Partially Burned Candle");
		if (set.size() != 1)
			return false;
		if (!set.contains("Leznupar's Draught"))
			return false;

		// Check map for Phoenix Feather.
		set = map.get("Phoenix Feather");
		if (set.size() != 1)
			return false;
		if (!set.contains("Leznupar's Draught"))
			return false;

		// Check map for 12-ounce Can of Root Beer.
		set = map.get("12-ounce Can of Root Beer");
		if (set.size() != 1)
			return false;
		if (!set.contains("Leznupar's Draught"))
			return false;

		// Check map for Rain from a Category 3 Hurricane.
		set = map.get("Rain from a Category 3 Hurricane");
		if (set.size() != 1)
			return false;
		if (!set.contains("Leznupar's Draught"))
			return false;

		return true;
	}

	private static boolean checkSet(Set<String> set)
	{
		return (set.size() == 0);
	}

	public static void main(String [] args)
	{
		// Set up both maps.
		Map<String, Set<String>> ptrMap = getPotionToReagentsTestCaseMap();
		Map<String, Set<String>> rtpMap = getReagentToPotionsTestCaseMap();

		// Set up list of reagents on hand.
		Set<String> reagents = new HashSet<>();
		reagents.add("Icethorn");
		reagents.add("12-ounce Can of Root Beer");
		reagents.add("Vial of Unicorn Tears");
		reagents.add("Raven Feather");
		reagents.add("Frost Lotus");
		reagents.add("Phoenix Song");
		reagents.add("Rain from a Category 4 Hurricane");
		reagents.add("Wax from a Partially Burned Candle");
		reagents.add("Black Lotus");

		// Check which potions are brewable.
		Set<String> set = PotionMaster.allPossiblePotions(ptrMap, rtpMap, reagents);
		boolean result = checkSet(set);

		if (result)
		{
			System.out.println("Hooray!");
		}
		else
		{
			System.out.println("oh no :(");
			PotionInfo.printSet(set);
		}
	}
}
