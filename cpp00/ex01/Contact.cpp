#include "Contact.hpp"

Contact::Contact()
{
	this->first_name = "";
	this->last_name = "";
	this->nick_name = "";
	this->phone_number = "";
	this->darkest_secret = "";
}

void Contact::setField()
{
	std::cout << "first name : ";
	std::getline(std::cin, this->first_name);
	std::cout << "last_name : ";
	std::getline(std::cin, this->last_name);
	std::cout << "nick_name : ";
	std::getline(std::cin, this->nick_name);
	std::cout << "phone_number : ";
	std::getline(std::cin, this->phone_number);
	std::cout << "darkest_secret : ";
	std::getline(std::cin, this->darkest_secret);
}

void Contact::columnPrinter(int idx)
{
	std::cout << std::setw(10);
	std::cout << idx;
	std::cout << "|";
	Contact::oneColumnPrinter(this->first_name);
	std::cout << "|";
	Contact::oneColumnPrinter(this->last_name);
	std::cout << "|";
	Contact::oneColumnPrinter(this->nick_name);
	std::cout << "|";
}

void Contact::oneColumnPrinter(const std::string str)
{
	std::string substr;

	if (str.length() > 10)
	{
		std::cout << str.substr(0, 10);
	}
	else
	{
		std::cout << std::setw(10);
		std::cout << str;
	}
}
