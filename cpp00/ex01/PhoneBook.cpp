#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contact_size(0), max_contact_size(8){}

void PhoneBook::add(Contact new_contact)
{
	for (int i = this->contact_size - 1; i >= 0; i--)
	{
		if (i > this->max_contact_size - 2)
			continue;
		// std::cout << i << " ---> " << i + 1 << "\n";
		this->contacts[i + 1] = this->contacts[i];
	}
	this->contacts[0] = new_contact;
	if (this->contact_size < 8)
		this->contact_size++;
	// std::cout << "Add Success\n" << "contact size : " << this->contact_size << " max contact size : " << this->max_contact_size << "\n";
}

void PhoneBook::search()
{
	for (int i = 0; i < this->contact_size; i++)
	{
		this->contacts[i].columnPrinter(i + 1);
		std::cout << "\n";
	}
}
