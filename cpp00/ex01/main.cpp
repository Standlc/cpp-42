#include <iostream>
#include <string>
#include <iomanip>
#include "PhoneBook.hpp"

int main()
{
	PhoneBook myPhoneBook;
	std::string userInput;

	while (1)
	{
		std::cout << "Phone book: ";
		std::cin >> userInput;
		if (std::cin.eof())
			return (1);
		if (userInput == "ADD")
			myPhoneBook.addContact();
		else if (userInput == "SEARCH")
			myPhoneBook.search();
		else if (userInput == "EXIT")
			return (0);
	}
	return (0);
}