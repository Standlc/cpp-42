#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>

class PhoneBook {
	Contact contacts[8];
	int contactsCount;
	public:
		PhoneBook();
		void addContact();
		void search();
		void showContact(int index);
		void showAllContacts();
};
