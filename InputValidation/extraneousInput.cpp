#include <iostream>

// This is for checking if there is extraneous input
// Example: If your input type is int (e.g. 3) and you entered with extra characters (e.g. 3s)
bool extraneousInput()
{
	// Return true if it has extraneous input
	return std::cin && (std::cin.peek() != '\n');
}