#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	contactsCount = 0;
}

void PhoneBook::addContact()
{
	contacts[contactsCount % 8].fillInfo();
	contactsCount++;
}

std::string truncate(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void PhoneBook::showAllContacts()
{
	for (int i = 0; i < contactsCount && i < 8; i++)
	{
		std::cout << std::setw(10);
		std::cout << i << "|";
		std::cout << std::setw(10);
		std::cout << truncate(contacts[i].firstName) << "|";
		std::cout << std::setw(10);
		std::cout << truncate(contacts[i].lastName) << "|";
		std::cout << std::setw(10);
		std::cout << truncate(contacts[i].nickName) << std::endl;
	}
}

int isNotSingleDigit(std::string &input, int &output)
{
	if (std::isdigit(input[0]) && input.size() == 1)
	{
		output = input[0] - '0';
		return (0);
	}
	return 1;
}

void PhoneBook::search()
{
	int index = 0;
	std::string input;

	if (!contactsCount)
	{
		std::cout << "You don't have any contacts yet\n";
		return;
	}
	showAllContacts();
	std::cout << "Enter an index: ";
	std::cin >> input;
	while (isNotSingleDigit(input, index) || index < 0 || index >= contactsCount || index > 7)
	{
		if (std::cin.eof())
			exit(1);
		std::cout << "The index you entered isn't valid" << std::endl;
		std::cout << "Enter an index: ";
		std::cin >> input;
	}
	contacts[index].show();
}
