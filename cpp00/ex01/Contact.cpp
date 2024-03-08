#include "Contact.hpp"

Contact::Contact(std::string f_name, std::string l_name, std::string n_name, std::string number, std::string secret) : \
		first_name(f_name), last_name(l_name), nick_name(n_name), phone_number(number), darkest_secret(secret) {}

Contact::Contact()
{
	this->first_name = "";
	this->last_name = "";
	this->nick_name = "";
	this->phone_number = "";
	this->darkest_secret = "";
	// std::cout << "first name : ";
	// std::getline(std::cin, this->first_name);
	// std::cout << "last_name : ";
	// std::getline(std::cin, this->last_name);
	// std::cout << "nick_name : ";
	// std::getline(std::cin, this->nick_name);
	// std::cout << "phone_number : ";
	// std::getline(std::cin, this->phone_number);
	// std::cout << "darkest_secret : ";
	// std::getline(std::cin, this->darkest_secret);
}

Contact::Contact(const Contact& obj)
{
	this->first_name = obj.first_name;
	this->last_name = obj.last_name;
	this->nick_name = obj.nick_name;
	this->phone_number = obj.phone_number;
	this->darkest_secret = obj.darkest_secret;
}
void Contact::oneColumnPrinter(const std::string str)
{
	std::string substr;

	if (str.length() > 10)
	{
		std::cout << str.substr(0, 9);
	}
	else
	{
		for (int i = str.length(); i < 10; i++)
			std::cout << " ";
		std::cout << str;
	}
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
	std::cout << idx;
	std::cout << "|";
	Contact::oneColumnPrinter(this->first_name);
	std::cout << "|";
	Contact::oneColumnPrinter(this->last_name);
	std::cout << "|";
	Contact::oneColumnPrinter(this->nick_name);
}
