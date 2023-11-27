// DO NOT MODIFY THIS FILE!
// DO NOT MODIFY THIS FILE!
// DO NOT MODIFY THIS FILE!

// =============================================================================
//          BlackBoxOfChaos ~ Sean Szumlanski ~ COP 3330 ~ Spring 2023
// =============================================================================
// The ChaoticSpiral class is used to govern the chaotic behaviors of the
// BlackBoxOfChaos class. Do not modify this file, and do not submit this file
// with your assignment.


public class ChaoticSpiral
{
	// Arcane parameters governing the behaviors of the chaotic spiral.

	private int resonanceFrequency;
	private int primalCortex;
	private int primaryChaosAspect;
	private int secondaryChaosAspect;
	private int gidgeySwitch;


	// This can be used to determine whether the chaotic spiral was properly
	// activated. If not, calling the getChaoticInteger() method will result
	// in a ChaosException being thrown.

	private boolean isActivated;

	public boolean isActivated()
	{
		return this.isActivated;
	}


	// This constructor creates a new ChaoticSpiral that is attuned to the
	// given parameters.
	//
	// Note that the creation of a ChaoticSpiral is not a thing to be done
	// lightly. Not all parameter combinations are powerful enough to be used
	// in the creation of a chaotic spiral. If any of these parameters are out
	// of sync, the spiral will collapse in on itself during creation, and any
	// further attempts to use this chaotic spiral will then result in a
	// ChaosException being thrown.

	ChaoticSpiral(int rf, int pc, int pca, int sca)
	{
		this.resonanceFrequency   = rf;
		this.primalCortex         = pc;
		this.primaryChaosAspect   = pca;
		this.secondaryChaosAspect = sca;
		this.gidgeySwitch         = 1;

		if (exhibitsPrimalDuality(pca, sca))
		{
			this.isActivated = true;
		}
		else
		{
			this.isActivated = false;
			System.out.println("Warning: Failed to activate chaotic spiral.");
		}
	}

	// This method checks wether the primary and secondary chaos aspects passed
	// to the ChaoticSpiral constructor exhibit the primal duality necessary
	// to activate a sufficiently powerful chaotic spiral.

	private boolean exhibitsPrimalDuality(int primary, int secondary)
	{
		int cup = Math.min(primary, secondary);
		int cap = Math.max(primary, secondary);
		int sek = (int) Math.sqrt(cap);

		boolean [] duality = new boolean[cap + 1];

		for (int i = 2; i <= sek; i++)
		{
			if (duality[i])
				continue;

			for (int j = i; j <= cap; j += i)
				duality[j] = true;

			if (duality[cup] || duality[cap])
				return false;
		}

		return true;
	}

	// This method returns a chaotic (i.e. quasi-random) integer greater than or
	// equal to zero. Hilariously, this method's performance degrades over time;
	// it becomes slower and slower the more we call it.

	public int getChaoticInteger()
	{
		if (!this.isActivated)
			throw new ChaosException("chaotic spiral was not activated");
		else
			return Math.abs(getChaoticInteger(this.gidgeySwitch++) % resonanceFrequency);
	}

	private int getChaoticInteger(int shard)
	{
		if (shard == 0)
			return primalCortex;

		return
			(primaryChaosAspect * getChaoticInteger(shard - 1) + secondaryChaosAspect);
	}
}
