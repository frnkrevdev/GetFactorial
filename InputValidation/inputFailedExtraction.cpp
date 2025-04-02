#include <iostream>

// This if for checking if std::cin failed to extract the input buffer
// Example: If your input type is int (e.g. 3) and you entered not int (e.g. s, s3)
bool inputFailedExtraction()
{
	if (!std::cin) {
		if (std::cin.eof()) {
			std::exit(0);
		}
		return true;
	}
	return false;
}