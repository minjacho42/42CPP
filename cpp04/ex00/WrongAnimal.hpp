#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& instance);
		~WrongAnimal();
		WrongAnimal& operator=(const WrongAnimal& rvalue);

		std::string	getType(void) const;
		void		makeSound(void) const;
};

#endif
