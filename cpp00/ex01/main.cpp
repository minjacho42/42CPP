#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
	std::string op;
	PhoneBook phonebook;
	std::cout << "> ";
	while (std::getline(std::cin, op))
	{
		if (op.compare("ADD") == 0)
		{
			Contact newContact;
			if (!newContact.setField())
			{
				std::cout << "\033[1;31mError!\n\033[0m";
				std::cout << "> ";
				continue;
			}
			phonebook.add(newContact);
			std::cout << "\033[1;34mSuccessfully add user!\n\033[0m";
		}
		else if (op.compare("SEARCH") == 0)
		{
			std::cout << "\033[1;34mSearching for info...\n\033[0m";
			phonebook.search();
		}
		else if (op.compare("EXIT") == 0)
			break;
		else if (op.length() != 0)
			std::cout << "\033[1;31mCommand rejected\n\033[0m";
		std::cout << "> ";
	}
}
