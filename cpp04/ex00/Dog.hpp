#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <string>
# include <iostream>

class Dog: public Animal
{
	public:
		Dog();
		Dog(const Dog& instance);
		~Dog();
		Dog& operator=(const Dog& rvalue);

		void	makeSound(void) const;
};

#endif
