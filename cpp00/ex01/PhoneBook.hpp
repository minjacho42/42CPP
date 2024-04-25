#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <cctype>
# include <iomanip> //setw를 위한 헤더
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int contact_size;
		static const int kMaxContactSize = 8;

		void GetNthIndexContact();
		void RowPrinter(int idx);
		static void OneColumnPrinter(const std::string str);
		static void TableHeaderPrinter();
		static bool GetLineWithPrompt(std::string prompt, std::string& buffer);
	public:
		PhoneBook();
		void Add(Contact new_contact);
		void Search();
		static void Program(PhoneBook& phoneBook);
};

#endif
