// =============================================================================
// POSTING THIS FILE ONLINE OR DISTRIBUTING IT IN ANY WAY, IN PART OR IN WHOLE,
// IS AN ACT OF ACADEMIC MISCONDUCT AND ALSO CONSTITUTES COPYRIGHT INFRINGEMENT.
// =============================================================================

// Tim Adsit
// ti047614

// =============================================================================
//          BlackBoxOfChaos ~ Sean Szumlanski ~ COP 3330 ~ Spring 2023
// =============================================================================
// This is an absurdist data structure. Sometimes it loses the values you place
// inside it. Sometimes it finds them again. The goal of this assignment is to
// make the BlackBoxOfChaos class generic (i.e., to set it up to hold any type
// of data -- not just ints). Please read all instructions in the attached PDF.
// =============================================================================


// Each compartment in the black box of chaos is made up of four quadrants. Each
// quadrant holds a value. A quadrant might also have a latch that leads to a
// deeper compartment within the box.

class Quadrant <T>
{
	T value;
	Compartment<T> latch;

	Quadrant(T value)
	{
		this.value = value;
	}

	public T getValue()
	{
		return value;
	}

	public void setLatch(Compartment<T> c)
	{
		this.latch = c;
	}

	public Compartment<T> getLatch()
	{
		return latch;
	}

	public boolean hasLatch()
	{
		return latch != null;
	}
}

class Compartment <T>
{
	// Each compartment within the black box of chaos is divided into four
	// quadrants, one for each cardinal direction: north, south, east, and west.

	Quadrant<T> north;
	Quadrant<T> south;
	Quadrant<T> east;
	Quadrant<T> west;

	private static final String [] directions
		= new String[] {"north", "south", "east", "west"};

	// This Compartment has a reference to the BlackBoxOfChaos that it resides
	// within, mostly because some of these methods need access to that box's
	// ChaoticSpiral in order to function properly.

	private BlackBoxOfChaos<T> box;

	// A record of how many levels deep this compartment is within the box.

	private int depth;


	Compartment(BlackBoxOfChaos<T> box, int depth)
	{
		this.box = box;
		this.depth = depth;
	}

	// This method adds a new value to this compartment. If this compartment is
	// full, this method feels around in the different quadrants of this
	// compartment, searching for latches that might lead to other compartments.
	// If it finds one, it goes to that next compartment and tries to insert
	// this new value there.
	//
	// If this compartment is full and this method does not find another
	// compartment branching off of this one, it will create a new compartment,
	// connect that new compartment to this one, and emplace this new value in
	// that new compartment.
	//
	// Note that this method calls on a chaotic process to search for a latch
	// that leads to another compartment. It might fail to find a latch even if
	// one exists. If that's the case, there's also a small chance that this
	// method will overwrite an existing latch when creating a new compartment,
	// causing the black box to lose the compartment that the overwritten latch
	// led to previously.

	public void emplace(T value)
	{
		// If this compartment is full, we need to move on to the next
		// compartment in the box.

		if (!this.hasSpace())
		{
			Compartment<T> nextCompartment = this.findOrCreateNextCompartment();
			nextCompartment.emplace(value);
		}

		// Otherwise, find an empty quadrant. We always fill quadrants in the
		// same order, and we only move on to a new Compartment if every
		// Quadrant in this Compartment already contains a value. The order in
		// which we process these quadrants is one of the few non-chaotic
		// behaviors within a BlackBoxOfChaos.

		Quadrant<T> newQuadrant = new Quadrant<>(value);

		if (north == null)
			north = newQuadrant;
		else if (south == null)
			south = newQuadrant;
		else if (east == null)
			east = newQuadrant;
		else if (west == null)
			west = newQuadrant;
	}

	private boolean hasSpace()
	{
		return (north == null || south == null || east == null || west == null);
	}

	// This method finds the next compartment in the box, or creates a new
	// compartment if this one does not appear lead to another one. Either way,
	// it returns a reference to that next compartment.
	//
	// As with most things in the black box of chaos, this method cannot be
	// trusted. There are a few caveats to the behavior described above:
	//
	// 1. This method attempts to searche all four quadrants of this compartment
	//    for a latch that leads to the next compartment in the box. If this
	//    method cannot find such a latch, it creates a new compartment and
	//    chooses a quadrant at random to link to that new compartment via that
	//    quadrant's latch.
	//
	// 2. This method is somewhat chaotic and might fail to find a latch if one
	//    exists. In that case, this method might overwrite an existing latch
	//    as it links this compartment to the next one, causing us to lose our
	//    reference to that other compartment and all the values it contains.
	//    Alternatively, this process might result in the box having multiple
	//    compartments branching off of this one.

	private Compartment<T> findOrCreateNextCompartment()
	{
		// First, try to find an adjacent compartment via the latches.
		Compartment<T> foundCompartment = searchLatches();
		if (foundCompartment != null)
			return foundCompartment;

		// If we get down here, we have to create a new compartment.
		return createNewCompartment();
	}

	// This method creates a new compartment within the black box of chaos. Note
	// that this might overwrite an existing latch reference, in which case we
	// will permanently lose access to all the values in the compartment that
	// latch led to.

	private Compartment<T> createNewCompartment()
	{
		Compartment<T> newCompartment = new Compartment<>(this.box, this.depth + 1);

		int direction = box.getChaoticSpiral().getChaoticInteger() % 4;

		if (direction == 0)
			north.setLatch(newCompartment);
		else if (direction == 1)
			south.setLatch(newCompartment);
		else if (direction == 2)
			east.setLatch(newCompartment);
		else if (direction == 3)
			west.setLatch(newCompartment);

		System.out.print("-> New compartment latch: ");
		System.out.print(directions[direction]);
		System.out.print(" quadrant.\n");

		return newCompartment;
	}

	// Prints most of the values in this compartment most of the time, probably.
	// Then attempts to move on to the next compartment.

	public void printContents()
	{
		System.out.println("Compartment depth: " + this.depth);

		boolean [] printed = new boolean[4];
		int numTries = 40;

		for (int i = 0; i < numTries; i++)
		{
			int direction = box.getChaoticSpiral().getChaoticInteger() % 4;

			if (printed[direction])
				continue;

			if (direction == 0 && north != null)
				System.out.println(north.getValue());

			else if (direction == 1 && south != null)
				System.out.println(south.getValue());

			else if (direction == 2 && east != null)
				System.out.println(east.getValue());

			else if (direction == 3 && west != null)
				System.out.println(west.getValue());

			printed[direction] = true;
		}

		// Attempt to move on to the next compartment.

		Compartment<T> nextCompartment = searchLatches();

		if (nextCompartment != null)
			nextCompartment.printContents();
	}

	// Randomly thrash about, hoping to encounter a latch that leads to the
	// next compartment. If so, return a reference to that compartment. If not,
	// return null.

	private Compartment<T> searchLatches()
	{
		int numTries = (box.getChaoticSpiral().getChaoticInteger() + 1) * 4;

		for (int i = 0; i < numTries; i++)
		{
			// Note: Modding by 5 allows for the possibility that we won't even
			// check one of our latches below, since there are only 4 quadrants.

			int direction = box.getChaoticSpiral().getChaoticInteger() % 5;

			if (direction == 0 && north != null && north.hasLatch())
				return north.getLatch();
			if (direction == 1 && south != null && south.hasLatch())
				return south.getLatch();
			if (direction == 2 && east != null && east.hasLatch())
				return east.getLatch();
			if (direction == 3 && west != null && west.hasLatch())
				return west.getLatch();
		}

		return null;
	}
}

public class BlackBoxOfChaos <T>
{
	// Number of elements that have been inserted into thsi box.
	private int size;
	public int getSize() { return size; }

	// Reference to the first compartment (which holds values) within the box.
	private Compartment<T> firstCompartment;

	// Reference to the chaotic spiral governing the box's behaviors.
	private ChaoticSpiral chaoticSpiral;
	public ChaoticSpiral getChaoticSpiral() { return chaoticSpiral; }

	// Indicates whether the box is actually functional or not.
	private boolean isFunctional;


	// This constructor creates a new ChaoticSpiral that is attuned to the
	// parameters listed below. If these parameters lead to the successful
	// creation of an active chaotic spiral, that spiral is engraved onto the
	// black box of chaos and will power all of its operations moving forward.
	// If for some reason the chaotic spiral fails to activate, this box will
	// be locked down an non-functional.

	BlackBoxOfChaos(int resonanceFrequency,
	                int primalCortex,
	                int primaryChaosAspect,
	                int secondaryChaosAspect)
	{
		this.chaoticSpiral = new ChaoticSpiral(resonanceFrequency,
		                                       primalCortex,
		                                       primaryChaosAspect,
		                                       secondaryChaosAspect);

		// Check whether the chaotic spiral was activated. If not, this black
		// box of chaos is defunct.
		if (!this.chaoticSpiral.isActivated())
		{
			this.isFunctional = false;
			System.out.println("Warning: Box is irrevocably locked and unusable.");

			return;
		}

		// Create the first compartment in the black box of chaos and initialize
		// all remaining fields.
		this.firstCompartment = new Compartment<>(this, 0);
		this.size = 0;
		this.isFunctional = true;
	}

	// Add a new value to the black box of chaos. This kicks off a process in
	// which we descend farther and farther into the depths of the box's various
	// compartments, always starting with the first compartment.
	//
	// We assume firstCompartment has been initialized by our constructor and is
	// non-null, unless the box is inactive (in which case we throw a
	// ChaosException).

	public void emplace(T value)
	{
		if (!isFunctional)
		{
			throw new ChaosException("non-functional black box of chaos");
		}

		System.out.println("Inserting " + value + "...");
		firstCompartment.emplace(value);
		++size;
	}

	// This method kicks off a process in which we descend farther and farther
	// into the depths of the box's various compartments, always starting with
	// the first compartment, printing the values we encounter as we go.
	//
	// Most of the time, most of the values in the box will get printed,
	// probably.
	//
	// We assume firstCompartment has been initialized by our constructor and is
	// non-null, unless the box is inactive (in which case we throw a
	// ChaosException).

	public void printContents()
	{
		if (!isFunctional)
		{
			throw new ChaosException("non-functional black box of chaos");
		}

		firstCompartment.printContents();
	}

	public static double difficultyRating()
	{
		return 2.5;
	}

	public static double hoursSpent()
	{
		return 1.5;
	}

}
