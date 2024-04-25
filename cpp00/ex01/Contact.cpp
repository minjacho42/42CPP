#include "Contact.hpp"

Contact::Contact() : first_name(""),
	last_name(""),
	nick_name(""),
	phone_number(""),
	darkest_secret("") {}

bool Contact::getInputOnlyPrintable(std::string& input)
{
	if (!std::getline(std::cin, input))
	{
		std::cout << "\n";
		return false;
	}
	if (input.length() < 1)
		return false;
	for (size_t i = 0; i < input.length(); i++)
		if (!std::isprint(input[i]) || (int)input[i] == 27)
			return false;
	return true;
}

bool Contact::SetField()
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

std::string Contact::GetFirstName() {
	return (this->first_name);
}

std::string Contact::GetLastName() {
	return (this->last_name);
}

std::string Contact::GetNickName() {
	return (this->nick_name);
}

std::string Contact::GetPhoneNumber() {
	return (this->phone_number);
}
