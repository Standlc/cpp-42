#include "Contact.hpp"

void getContactInfo(std::string attribute, std::string &contactAttribute)
{
	std::cout << "Enter new contact's " << attribute << ": ";
	std::cin >> contactAttribute;
	if (std::cin.eof())
		exit(1);
}

void Contact::fillInfo()
{
	getContactInfo("first name", firstName);
	getContactInfo("last name", lastName);
	getContactInfo("nick name", nickName);
	getContactInfo("phone number", phoneNumber);
	getContactInfo("darkest secret", darkestSecret);
}

void Contact::show()
{
	std::cout << std::endl;
	std::cout << "first name: " << firstName << std::endl;
	std::cout << "last name: " << lastName << std::endl;
	std::cout << "nick name: " << nickName << std::endl;
	std::cout << "phone number: " << phoneNumber << std::endl;
	std::cout << "darkest secret: " << darkestSecret << std::endl;
	std::cout << std::endl;
}
