// DO NOT MODIFY THIS FILE!
// DO NOT MODIFY THIS FILE!
// DO NOT MODIFY THIS FILE!


// Sean Szumlanski
// COP 3330, Spring 2023

// =============================
// PotionMaster: PotionInfo.java
// =============================
//
// This class helps us keep track of potion formulas. It includes a few methods
// that create common PotionInfo objects to be used across a variety of test
// cases.
//
// This class also contains some methods for printing out map and set contents
// (which are called automatically from some of the test cases if they fail, so
// you can easily examine what's going on in the maps and sets you're creating).


import java.util.*;

public class PotionInfo
{
	public String name;
	public String description;
	public List<String> reagents;

	PotionInfo(String name, String description, List<String> reagents)
	{
		this.name = name;
		this.description = description;

		// Note: We don't want to simply set 'this.reagents = reagents;'
		// If we did that, this.reagents would simply be a reference to the
		// reagents list passed to us by whoever called this method. So, if
		// the person who called this method later changed that list, they
		// would also be changing the reagents for this potion.

		// The right thing to do instead is to create an entirely new copy of
		// that list. Passing a list to the ArrayList constructor causes Java
		// to create an entirely new copy of that list.

		this.reagents = new ArrayList<>(reagents);
	}

	// =======================================================================
	// These methods can be used for debugging. They're called in several test
	// cases automatically upon test case failure.
	// =======================================================================

	public static void printMap(Map<String, Set<String>> map)
	{
		System.out.println();
		System.out.println("=============");
		System.out.println("Map Contents:");
		System.out.println("=============");

		for (String key : map.keySet())
		{
			System.out.print(key + " -> {");

			Set<String> set = map.get(key);
			boolean firstString = true;

			for (String val : set)
			{
				System.out.print((firstString ? "" : ", ") + val);
				firstString = false;
			}

			System.out.println("}");
		}
	}

	public static void printSet(Set<String> set)
	{
		System.out.println();
		System.out.println("=============");
		System.out.println("Set Contents:");
		System.out.println("=============");

		for (String s : set)
		{
			System.out.println(s);
		}
	}

	// ============================================================================
	// Below are several standard potion formulas to be used by various test cases.
	// ============================================================================

	public static final PotionInfo POLYJUICE_POTION()
	{
		// Source: Harry Potter, by J.K. Rowling.
		// See also: https://harrypotter.fandom.com/wiki/Polyjuice_Potion

		String name = "Polyjuice Potion";
		String desc = "Allows the user to to take on the appearance of another person.";

		ArrayList<String> reagents = new ArrayList<>();
		reagents.add("lacewing flies, stewed 21 days");
		reagents.add("leeches");
		reagents.add("powdered bicorn horn");
		reagents.add("knotgrass");
		reagents.add("fluxweed, picked at full moon");
		reagents.add("shredded boomslang skin");
		reagents.add("a strand of human hair");

		return new PotionInfo(name, desc, reagents);
	}

	public static final PotionInfo PYGMY_OIL()
	{
		// Source: World of Warcraft.
		// See also: https://www.wowhead.com/item=40195/pygmy-oil

		String name = "Pygmy Oil";
		String desc = "Transforms the user into a small, feisty gnome with a tribal mask.";

		ArrayList<String> reagents = new ArrayList<>();
		reagents.add("Pygmy Suckerfish");

		return new PotionInfo(name, desc, reagents);
	}

	public static final PotionInfo FLASK_OF_PURE_MOJO()
	{
		// Source: World of Warcraft.
		// See also: https://www.wowhead.com/item=46378/flask-of-pure-mojo

		String name = "Flask of Pure Mojo";
		String desc = "The user gains an incredible amount of mojo. Use wisely.";

		ArrayList<String> reagents = new ArrayList<>();
		reagents.add("Icethorn");
		reagents.add("Pygmy Oil");
		reagents.add("Frost Lotus");

		return new PotionInfo(name, desc, reagents);
	}

	public static final PotionInfo GURUS_ELIXIR()
	{
		// Source: World of Warcraft.
		// See also: https://www.wowhead.com/item=40076/gurus-elixir

		String name = "Guru's Elixir";
		String desc = "Causes increased proficiency at literally everything for one hour.";

		ArrayList<String> reagents = new ArrayList<>();
		reagents.add("Pygmy Oil");

		return new PotionInfo(name, desc, reagents);
	}

	public static final PotionInfo LEZNUPARS_DRAUGHT()
	{
		String name = "Leznupar's Draught";
		String desc = "Allows the user to swim through air as if it were water.";

		ArrayList<String> reagents = new ArrayList<>();
		reagents.add("Wax from a Partially Burned Candle");
		reagents.add("Frost Lotus");
		reagents.add("Phoenix Feather");
		reagents.add("12-ounce Can of Root Beer");
		reagents.add("Rain from a Category 3 Hurricane");

		return new PotionInfo(name, desc, reagents);
	}
}
