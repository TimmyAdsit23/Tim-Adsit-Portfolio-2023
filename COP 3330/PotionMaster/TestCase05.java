// Sean Szumlanski
// COP 3330, Spring 2023

// =============================
// PotionMaster: TestCase05.java
// =============================
// A small test of the reagentToPotionsMap() method. This map ends up only
// having a single key.
//
// If you run into any trouble with this test case, you might want to use the
// printMap() method included in PotionInfo.java to view the contents of your
// map.


import java.util.*;

public class TestCase05
{
	private static List<PotionInfo> getPotionsManual()
	{
		ArrayList<PotionInfo> potionsManual = new ArrayList<>();

		potionsManual.add(PotionInfo.PYGMY_OIL());

		return potionsManual;
	}

	private static boolean checkMapContents(Map<String, Set<String>> map)
	{
		if (map.size() != 1)
			return false;

		if (!map.containsKey("Pygmy Suckerfish"))
			return false;

		Set<String> set;

		// Check map for Pygmy Suckerfish.
		set = map.get("Pygmy Suckerfish");
		if (set.size() != 1)
			return false;
		if (!set.contains("Pygmy Oil"))
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
