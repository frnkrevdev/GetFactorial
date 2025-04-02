#include "InputValidation.h"
#include <iostream>

bool inputInvalid()
{
	// For extraneous inputs
	if (extraneousInput()) {
		clearAndIgnoreLine();
		// Error handling
		std::cout << "ERROR! EXTRANEOUS INPUT\n";
		return true;
	}

	// For inputs that fails in extraction
	if (inputFailedExtraction()) {
		clearAndIgnoreLine();
		// Error handling
		std::cout << "ERROR! INVALID INPUT\n";
		return true;
	}
	return false;
}