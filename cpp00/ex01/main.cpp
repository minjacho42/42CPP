#include "Contact.hpp"
#include "PhoneBook.hpp"



int main()
{
	std::string op;
	PhoneBook phonebook;
	while (1)
	{
		std::cout << "> ";
		std::getline(std::cin, op);
		if (op.compare("ADD") == 0)
		{
			Contact newContact;
			newContact.setField();
			phonebook.add(newContact);
			std::cout << "\033[1;31mSuccessfully add user!\n\033[0m";
		}
		else if (op.compare("SEARCH") == 0)
		{
			std::cout << "\033[1;31mSearching for info...\n\033[0m";
			phonebook.search();
		}
		else if (op.compare("EXIT") == 0)
			break;
		else
			std::cout << "Command rejected\n";
	}
}
