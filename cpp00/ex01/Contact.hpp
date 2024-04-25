#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <cctype>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;

		static bool getInputOnlyPrintable(std::string& input);
	public:
		Contact();
		bool SetField();
		std::string GetFirstName();
		std::string GetLastName();
		std::string GetNickName();
		std::string GetPhoneNumber();
};

#endif
