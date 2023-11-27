// Sean Szumlanski
// COP 3330, Spring 2023

// =============================
// PotionMaster: TestCase04.java
// =============================
// A small test of the potionToReagentsMap() method.
//
// If you run into any trouble with this test case, you might want to use the
// printMap() method included in PotionInfo.java to view the contents of your
// map.


import java.util.*;

public class TestCase04
{
	private static List<PotionInfo> getPotionsManual()
	{
		ArrayList<PotionInfo> potionsManual = new ArrayList<>();

		potionsManual.add(PotionInfo.PYGMY_OIL());
		potionsManual.add(PotionInfo.FLASK_OF_PURE_MOJO());
		potionsManual.add(PotionInfo.GURUS_ELIXIR());

		return potionsManual;
	}

	private static boolean checkMapContents(Map<String, Set<String>> map)
	{
		if (map.size() != 3)
			return false;

		if (!map.containsKey("Pygmy Oil") ||
		    !map.containsKey("Flask of Pure Mojo") ||
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

		// Check map for Guru's Elixir.
		set = map.get("Guru's Elixir");
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
