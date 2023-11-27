// Sean Szumlanski
// COP 3330, Spring 2023

// =============================
// PotionMaster: TestCase03.java
// =============================
// A small test of the potionToReagentsMap() method. This map ends up only
// having a single key.
//
// If you run into any trouble with this test case, you might want to use the
// printMap() method included in PotionInfo.java to view the contents of your
// map.


import java.util.*;

public class TestCase03
{
	private static List<PotionInfo> getPotionsManual()
	{
		ArrayList<PotionInfo> potionsManual = new ArrayList<>();

		potionsManual.add(PotionInfo.POLYJUICE_POTION());

		return potionsManual;
	}

	private static boolean checkMapContents(Map<String, Set<String>> map)
	{
		if (map.size() != 1)
			return false;

		if (!map.containsKey("Polyjuice Potion"))
			return false;

		Set<String> set;

		// Check map for Polyjuice Potion.
		set = map.get("Polyjuice Potion");
		if (set.size() != 7)
			return false;
		if (!set.contains("lacewing flies, stewed 21 days") ||
		    !set.contains("leeches") ||
		    !set.contains("powdered bicorn horn") ||
		    !set.contains("knotgrass") ||
		    !set.contains("fluxweed, picked at full moon") ||
		    !set.contains("shredded boomslang skin") ||
		    !set.contains("a strand of human hair"))
			return false;

		return true;
	}

	public static void main(String [] args)
	{
		// Set up the potions manual for this particular test case.
		List<PotionInfo> potionsManual = getPotionsManual();

		// Build a potion -> reagents map from this potions manual.
		Map<String, Set<String>> map = PotionMaster.potionToReagentsMap(potionsManual);

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
