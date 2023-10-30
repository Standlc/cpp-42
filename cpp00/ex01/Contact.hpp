#include <iostream>
#include <string>
#include <iomanip>

class Contact {
	std::string phoneNumber;
	std::string darkestSecret;
	public:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		void fillInfo();
		void show();
};
