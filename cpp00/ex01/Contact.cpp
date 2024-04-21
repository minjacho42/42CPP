#include "Contact.hpp"

bool getInputOnlyPrintable(std::string& input)
{
	if (!std::getline(std::cin, input))
		return false;
	for (size_t i = 0; i < input.length(); i++)
		if (!std::isprint(input[i]) || (int)input[i] == 27)
			return false;
	return true;
}

Contact::Contact()
{
	this->first_name = "";
	this->last_name = "";
	this->nick_name = "";
	this->phone_number = "";
	this->darkest_secret = "";
}

bool Contact::setField()
{
	if (std::cin.eof() || std::cin.fail())
		return false;
	std::cout << "first name : ";
	if (!getInputOnlyPrintable(this->first_name))
		return false;
	std::cout << "last_name : ";
	if (!getInputOnlyPrintable(this->last_name))
		return false;
	std::cout << "nick_name : ";
	if (!getInputOnlyPrintable(this->nick_name))
		return false;
	std::cout << "phone_number : ";
	if (!getInputOnlyPrintable(this->phone_number))
		return false;
	std::cout << "darkest_secret : ";
	if (!getInputOnlyPrintable(this->darkest_secret))
		return false;
	return true;
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
