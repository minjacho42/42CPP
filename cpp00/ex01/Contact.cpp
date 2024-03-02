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
}

Contact::Contact(const Contact& obj)
{
	this->first_name = obj.first_name;
	this->last_name = obj.last_name;
	this->nick_name = obj.nick_name;
	this->phone_number = obj.phone_number;
	this->darkest_secret = obj.darkest_secret;
}
