#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <cctype>
# include <iomanip>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;
	public :
		Contact();
		void setField();
		void columnPrinter(int idx);
		static void oneColumnPrinter(const std::string str);
};

#endif
