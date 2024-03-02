#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <cctype>

class Contact
{
	public :
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;
		Contact();
		Contact(std::string f_name, std::string l_name, std::string n_name, \
				std::string number, std::string secret);
		Contact(const Contact&);
};

#endif
