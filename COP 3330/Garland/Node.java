// DO NOT MODIFY THIS FILE! DO NOT COPY THIS CLASS INTO GARLAND.JAVA! DO NOT SUBMIT THIS FILE!
// DO NOT MODIFY THIS FILE! DO NOT COPY THIS CLASS INTO GARLAND.JAVA! DO NOT SUBMIT THIS FILE!
// DO NOT MODIFY THIS FILE! DO NOT COPY THIS CLASS INTO GARLAND.JAVA! DO NOT SUBMIT THIS FILE!


// Sean Szumlanski
// COP 3330, Spring 2023
//
// ==================
// Garland: Node.java
// ==================
// The Node class for the Garland assignment.


public class Node
{
	// Each node holds a single character.
	char data;

	// Reference to next string's first node.
	Node next;

	// Reference to node with the next character in this string.
	Node down;

	Node(char data)
	{
		this.data = data;
	}
}
