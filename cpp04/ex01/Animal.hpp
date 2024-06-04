#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
	protected:
		std::string	type;

	public:
		Animal();
		Animal(const Animal& instance);
		virtual ~Animal();
		Animal& operator=(const Animal& rvalue);

		std::string		getType(void) const;
		virtual void	makeSound(void) const;
};

#endif
