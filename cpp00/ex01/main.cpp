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
		}
		else if (op.compare("SEARCH") == 0)
		{
			std::cout << "Searching phonebook info...\n";
			phonebook.search();
		}
		else if (op.compare("EXIT") == 0)
			break;
		else
			std::cout << "Command rejected\n";
	}
}
