#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <string>
# include <iostream>

class Dog: public Animal
{
	private:
		Brain	*brain;
	public:
		Dog();
		Dog(const Dog& instance);
		~Dog();
		Dog& operator=(const Dog& rvalue);

		void			makeSound(void) const;
		void			setBrain(Brain& brain);
		const Brain&	getBrain(void) const;
		void			printBrain(void) const;
};

#endif
