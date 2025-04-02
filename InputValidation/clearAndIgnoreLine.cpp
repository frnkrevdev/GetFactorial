#include <iostream>

// This is for clearing the input buffer
void clearAndIgnoreLine()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}