// Sean Szumlanski
// COP 3330, Spring 2023

// =============================
// PotionMaster: TestCase07.java
// =============================
// A slightly more elaborate test of the reagentToPotionsMap() method.
//
// If you run into any trouble with this test case, you might want to use the
// printMap() method included in PotionInfo.java to view the contents of your
// map.


import java.util.*;

public class TestCase07
{
	private static List<PotionInfo> getPotionsManual()
	{
		ArrayList<PotionInfo> potionsManual = new ArrayList<>();

		potionsManual.add(PotionInfo.PYGMY_OIL());
		potionsManual.add(PotionInfo.FLASK_OF_PURE_MOJO());
		potionsManual.add(PotionInfo.GURUS_ELIXIR());
		potionsManual.add(PotionInfo.LEZNUPARS_DRAUGHT());

		return potionsManual;
	}

	private static boolean checkMapContents(Map<String, Set<String>> map)
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

	public static void main(String [] args)
	{
		// Set up the potions manual for this particular test case.
		List<PotionInfo> potionsManual = getPotionsManual();

		// Build a reagent -> potions map from this potions manual.
		Map<String, Set<String>> map = PotionMaster.reagentToPotionsMap(potionsManual);

		// Check that the resulting map has exactly the right contents.
		if (checkMapContents(map))
		{
			System.out.println("Hooray!");
		}
		else
		{
			System.out.println("oh no :(");
			PotionInfo.printMap(map);
		}
	}
}
