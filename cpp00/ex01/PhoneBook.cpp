#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contact_size(0){}

void PhoneBook::add(Contact new_contact)
{
	for (int i = this->contact_size - 1; i >= 0; i--)
	{
		if (i > this->max_contact_size - 2)
			continue;
		this->contacts[i + 1] = this->contacts[i];
	}
	this->contacts[0] = new_contact;
	this->contact_size++;
}
