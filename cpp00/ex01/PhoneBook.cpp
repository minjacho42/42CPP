#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contact_size(0){}

void PhoneBook::Add(Contact new_contact)
{
	for (int i = this->contact_size - 1; i >= 0; i--)
	{
		if (i > kMaxContactSize - 2)
			continue;
		this->contacts[i + 1] = this->contacts[i];
	}
	this->contacts[0] = new_contact;
	if (this->contact_size < 8)
		this->contact_size++;
}

void PhoneBook::Search()
{
	if (this->contact_size < 1) {
		std::cout << "\033[1;31mPhonebook Is Empty\n\033[0m";
		return;
	}
	TableHeaderPrinter();
	for (int i = 0; i < this->contact_size; i++)
	{
		RowPrinter(i);
		std::cout << "\n";
	}
	GetNthIndexContact();
}

void PhoneBook::OneColumnPrinter(const std::string str)
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

void PhoneBook::TableHeaderPrinter() {
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

void PhoneBook::RowPrinter(int idx)
{
	std::cout << std::setw(10);
	std::cout << idx + 1;
	std::cout << "|";
	PhoneBook::OneColumnPrinter(this->contacts[idx].GetFirstName());
	std::cout << "|";
	PhoneBook::OneColumnPrinter(this->contacts[idx].GetLastName());
	std::cout << "|";
	PhoneBook::OneColumnPrinter(this->contacts[idx].GetNickName());
	std::cout << "|";
}


void PhoneBook::GetNthIndexContact() {
	int n;
	std::string left;

	std::cout << "Please enter the index : ";
	std::cin >> n;
	if (std::cin.fail() || n < 1 || n > this->contact_size)
	{
		std::cin.clear();
		std::cout << "\033[1;31mInput Error!\n\033[0m";
	} else {
		std::cout << "First Name : " << this->contacts[n - 1].GetFirstName() << "\n";
		std::cout << "Last Name : " << this->contacts[n - 1].GetLastName() << "\n";
		std::cout << "Nick Name : " << this->contacts[n - 1].GetNickName() << "\n";
		std::cout << "Phone Number : " << this->contacts[n - 1].GetPhoneNumber() << "\n";
	}
	std::getline(std::cin, left);
	return;
}

bool PhoneBook::GetLineWithPrompt(std::string prompt, std::string& buffer) {
	if (std::cin.eof() || std::cin.fail())
		return false;
	std::cout << prompt;
	if (std::getline(std::cin, buffer))
		return true;
	else
		return false;
}

void PhoneBook::Program(PhoneBook& phoneBook) {
	std::string op;

	while (GetLineWithPrompt("PHONEBOOK> ", op)) {
		if (op.compare("ADD") == 0)
		{
			Contact newContact;
			if (!newContact.SetField())
			{
				std::cout << "\033[1;31mInput Error!\n\033[0m";
				continue;
			}
			phoneBook.Add(newContact);
			std::cout << "\033[1;34mSuccessfully add user!\n\033[0m";
		}
		else if (op.compare("SEARCH") == 0)
		{
			std::cout << "\033[1;34mSearching for info...\n\033[0m";
			phoneBook.Search();
		}
		else if (op.compare("EXIT") == 0)
			break;
		else if (op.length() != 0)
			std::cout << "\033[1;31mCommand rejected\n\033[0m";
	}
}
