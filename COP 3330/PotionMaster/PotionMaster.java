// =============================================================================
// POSTING THIS FILE ONLINE OR DISTRIBUTING IT IN ANY WAY, IN PART OR IN WHOLE,
// IS AN ACT OF ACADEMIC MISCONDUCT AND ALSO CONSTITUTES COPYRIGHT INFRINGEMENT.
// =============================================================================

// Tim Adsit
// ti047613
// COP 3330, Spring 2023

// =============================================================================
//             PotionMaster ~ Sean Szumlanski ~ COP 3330 ~ Spring 2023
// =============================================================================
// Note: I've put this template together for you so you can see one safe way of
// breaking up the method signatures that are too long to put on one line
// without exceeding the limit of 100 characters per line. You can modify
// anything you want in this file, and you can remove this comment.
// =============================================================================


import java.util.*;

public class PotionMaster
{
	public static Map<String, Set<String>> potionToReagentsMap(List<PotionInfo> potionsManual)
	{
		Map<String, Set<String>> potionMap = new HashMap<>();
		
		// for every potion in the potion manual, make a set that is mapped to by the name of
		// the potion
		for (PotionInfo potion : potionsManual)
		{
			Set<String> reagentSet = new HashSet<>();
			for (String reagent : potion.reagents)
			{
				reagentSet.add(reagent);
			}

			potionMap.put(potion.name, reagentSet);
		}

		return potionMap;
	}

	public static Map<String, Set<String>> reagentToPotionsMap(List<PotionInfo> potionsManual)
	{
		Map<String, Set<String>> reagentMap = new HashMap<>();

		// for every reagent in a potion, in the potion manual, map the name of the reagent
		// to the name of all the potions that contain the reagent. If the reagentMap doesn't
		// have the reagent, make a new HashSet for the reagent, then insert.

		for (PotionInfo potion : potionsManual)
		{
			for (String reagent : potion.reagents)
			{
				if (!reagentMap.containsKey(reagent))
					reagentMap.put(reagent, new HashSet<String>());

				reagentMap.get(reagent).add(potion.name);
			}
		}


		return reagentMap;
	}

	public static boolean canBrewPotion(PotionInfo potionInfo, Set<String> reagentsOnHand)
	{
		// for the specific potion, if you don't have all of the reagents required on hand,
		// return false, if so, return true.

		for (String requiredReagent : potionInfo.reagents)
		{
			if (!reagentsOnHand.contains(requiredReagent))
			{
				return false;
			}
		}

		return true;
	}

	public static boolean canBrewPotion(String potionToBrew,
	                                    Map<String, Set<String>> potionToReagentsMap,
	                                    Set<String> reagentsOnHand)
	{
		// if the potionToReagents map doesn't have the potionToBrew included in its map, then we
		// can't check if we can brew the potion; return false.
		if (!potionToReagentsMap.containsKey(potionToBrew))
		{
			return false;
		}

		// for every requiredReagent in the specific reagent set of the potion, check if we do not
		// have one of the required reagents. If not, return false, otherwise, return true.
		for (String requiredReagent : potionToReagentsMap.get(potionToBrew))
		{
			if (!reagentsOnHand.contains(requiredReagent))
			{
				return false;
			}
		}

		return true;
	}

	public static Set<String> allPossiblePotions(Map<String, Set<String>> potionToReagentsMap,
	                                             Map<String, Set<String>> reagentToPotionsMap,
	                                             Set<String> reagentsOnHand)
	{
		Set<String> possiblePotions = new HashSet<>();
		boolean canMakeAPotion = false;

		// for all of the reagents on hand, if we don't have the reagent in our reagentToPotionMap,
		// we cannot check if we can make a potion of it, so continue to the next reagent. 
		for (String availableReagent : reagentsOnHand)
		{
			if (!reagentToPotionsMap.containsKey(availableReagent))
			{
				continue;
			}

			// If it is mapped, for every possible potion we can make out of this specific reagent,
			// check if we canBrewPotion out of the potions name, our known potionToReagentsMap, and
			// our reagents on hand. If we can, add it.
			for (String possiblePotion : reagentToPotionsMap.get(availableReagent))
			{
				if (canBrewPotion(possiblePotion, potionToReagentsMap, reagentsOnHand))
				{
					possiblePotions.add(possiblePotion);
					canMakeAPotion = true;
				}
			}
		}

		if (!canMakeAPotion)
		{
			Set<String> empty = new HashSet<>();
			return empty;
		}
			
		return possiblePotions;
	}

	public static double difficultyRating()
	{
		return 2;
	}

	public static double hoursSpent()
	{
		return 2.5;
	}
}
