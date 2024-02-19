#include "Contact.hpp"

Contact::Contact(std::string f_name, std::string l_name, std::string n_name, std::string number, std::string secret) : \
		first_name(f_name), last_name(l_name), nick_name(n_name), phone_number(number), darkest_secret(secret) {}

Contact::Contact()
{

}
