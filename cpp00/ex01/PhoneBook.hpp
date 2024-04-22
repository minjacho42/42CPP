#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cctype>
#include "Contact.hpp"

class PhoneBook
{
	private :
		Contact contacts[8];
		int contact_size;
		static const int max_contact_size = 8;

		void getNthIndexContact();
		void rowPrinter(int idx);
		static void oneColumnPrinter(const std::string str);
		static void tableHeaderPrinter();
		static bool getLineWithPrompt(std::string prompt, std::string& buffer);
	public :
		PhoneBook();
		void add(Contact new_contact);
		void search();
		static void program(PhoneBook& phoneBook);
};

#endif
