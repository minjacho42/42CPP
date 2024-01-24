#include <iostream>
#include <string>
#include <cctype>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;
		Contact();

	public:
		Contact(std::string first_name, std::string last_name, \
				std::string nick_name, std::string phone_number, \
				std::string darkest_secret);
		std::string	GetFirstName();
		std::string	GetLastName();
		std::string	GetNickName();
		std::string	GetPhoneNumber();
		std::string	GetDarkestSecret();
		void		SetFirstName(std::string str);
		void		SetLastName(std::string str);
		void		SetNickName(std::string str);
		void		SetPhoneNumber(std::string str);
		void		SetDarkestSecret(std::string str);
}
