#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contact_size(0){}

void PhoneBook::add(Contact new_contact)
{
	for (int i = this->contact_size - 1; i >= 0; i--)
	{
		if (i > max_contact_size - 2)
			continue;
		this->contacts[i + 1] = this->contacts[i];
	}
	this->contacts[0] = new_contact;
	if (this->contact_size < 8)
		this->contact_size++;
}

void PhoneBook::search()
{
	if (this->contact_size < 1) {
		std::cout << "Phonebook is empty\n";
		return;
	}
	tableHeaderPrinter();
	for (int i = 0; i < this->contact_size; i++)
	{
		rowPrinter(i);
		std::cout << "\n";
	}
	getNthIndexContact();
}

void PhoneBook::oneColumnPrinter(const std::string str)
{
	std::string substr;

	if (str.length() > 10)
	{
		std::cout << str.substr(0, 9) << ".";
	}
	else
	{
		std::cout << std::setw(10);
		std::cout << str;
	}
}

void PhoneBook::tableHeaderPrinter() {
	std::cout << std::setw(10);
	std::cout << "INDEX";
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << "FST NAME";
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << "LST NAME";
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << "NICKNAME";
	std::cout << "|";
	std::cout << "\n";
	std::cout << "--------------------------------------------\n";
}

void PhoneBook::rowPrinter(int idx)
{
	std::cout << std::setw(10);
	std::cout << idx + 1;
	std::cout << "|";
	PhoneBook::oneColumnPrinter(this->contacts[idx].getFirstName());
	std::cout << "|";
	PhoneBook::oneColumnPrinter(this->contacts[idx].getLastName());
	std::cout << "|";
	PhoneBook::oneColumnPrinter(this->contacts[idx].getNickName());
	std::cout << "|";
}


void PhoneBook::getNthIndexContact() {
	std::string line;

	std::cout << "Please enter the index : ";
	if (!getline(std::cin, line))
	{
		std::cout << "\n";
		std::cout << "\033[1;31mError!\n\033[0m";
		return ;
	}
	line.
	if (n < 1 || n > 8) {
		std::cout << "Not Valid Index";
		return ;
	}
	std::cout << "First Name : " << this->contacts[n - 1].getFirstName() << "\n";
	std::cout << "Last Name : " << this->contacts[n - 1].getLastName() << "\n";
	std::cout << "Nick Name : " << this->contacts[n - 1].getNickName() << "\n";
	std::cout << "Phone Number : " << this->contacts[n - 1].getPhoneNumber() << "\n";
	return;
}

bool PhoneBook::getLineWithPrompt(std::string prompt, std::string& buffer) {
	if (std::cin.eof() || std::cin.fail())
		return false;
	std::cout << prompt;
	if (std::getline(std::cin, buffer))
		return true;
	else
		return false;
}

void PhoneBook::program(PhoneBook& phoneBook) {
	std::string op;

	while (getLineWithPrompt("> ", op)) {
		if (op.compare("ADD") == 0)
		{
			Contact newContact;
			if (!newContact.setField())
			{
				std::cout << "\033[1;31mError!\n\033[0m";
				continue;
			}
			phoneBook.add(newContact);
			std::cout << "\033[1;34mSuccessfully add user!\n\033[0m";
		}
		else if (op.compare("SEARCH") == 0)
		{
			std::cout << "\033[1;34mSearching for info...\n\033[0m";
			phoneBook.search();
		}
		else if (op.compare("EXIT") == 0)
			break;
		else if (op.length() != 0)
			std::cout << "\033[1;31mCommand rejected\n\033[0m";
	}
}
