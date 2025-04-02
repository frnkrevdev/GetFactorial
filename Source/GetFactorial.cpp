#include "../InputValidation/InputValidation.h"		// Library for unexpected console inputs
#include <boost/multiprecision/cpp_int.hpp>			// Library for big integer numbers, also alternative gmp.h for C language
#include <iostream>
#include <string>

// Shortening data type for extra large int
using boost::multiprecision::cpp_int;

// This function let the user to enter a number for factorial
cpp_int getNumber()
{
	// Loops user input until it gets the valid input
	while (true)
	{
		// User input
		std::cout << "Enter the number for factorial: ";
		cpp_int num{};
		std::cin >> num;

		// Input Validation
		if (inputInvalid()) {
			// Repeat the loop if input is invalid
			continue;
		}
		if (num < 0) {
			// Repeat the loop if input is negative
			std::cout << "Factorial with negative numbers is not allowed.\n";
			continue;
		}
		// Exit the loop when user entered valid input and get that input
		return num;
	}
}

// This function calculates the factorial of the number then converts into string and prints it
void getFactorial(cpp_int num)
{
	cpp_int result{ num };		// Initialized using the user's input since it will be the starting value for factorial computation

	// Calculating the factorial of the number that the user entered
	for (cpp_int i{ num - 1 }; i > 0; --i) {
		result *= i;
	}

	// FOR OUTPUT READABILITY
	// Convert the result into string
	std::string resultString = result.str();
	// Getting the amount of characters of the converted result
	unsigned long long numlength{ static_cast<unsigned long long>(resultString.length()) };

	// Inserting comma for such big numbers (e.g. 10,987,654,321)
	for (int i{ 3 }; i < numlength; i += 3) {
		resultString.insert((numlength - i), 1, ',');
	}
	
	// Prints the final result
	std::cout << "The factorial of the number you entered is: " << resultString << '\n';
}

// This function let the user decide if the user wants to repeat the program or not
bool repeat()
{
	// Loops user input until it gets the valid input
	while (true)
	{
		// User input
		std::cout << "Do you want to repeat? (y/n): ";
		char again{};
		std::cin >> again;

		// Input validation (Calls if the input is extraneous)
		if (inputInvalid()){
			// Repeat the loop if input is extraneous
			continue;
		}

		// Executes when user entered valid type input
		switch (again) {
		case 'y':		return true;		// Exits the loop and the user is satisfied to repeat
		case 'n':		return false;		// Exits the loop and the user is no longer satisfied to repeat
		default:
			// Repeat the loop if input is invalid
			clearAndIgnoreLine();
			std::cout << "Invalid input.\n";
			continue;
		}
	}
}

int main()
{
	// Loop until the user is dissatisfied with the program
	while (true)
	{
		// The program begins here
		getFactorial(getNumber());
		
		// If the user is satisfied to repeat, repeat the program
		if (repeat()) {
			continue;
		}
		// Or else exit the program
		break;
	}

	// My message for those who used this program :)
	std::cout << "Thank you for using this program. Hehe :)\n";

	return 0;
}