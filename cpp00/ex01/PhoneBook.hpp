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
		const int max_contact_size = 8;
	public :
		PhoneBook();
		void add(Contact new_contact);
		void search();
		void exit();
};

#endif
