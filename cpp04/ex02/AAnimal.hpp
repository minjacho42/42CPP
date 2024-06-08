#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>
# include <iostream>

class AAnimal
{
	protected:
		std::string	type;

	public:
		AAnimal();
		AAnimal(const AAnimal& instance);
		virtual ~AAnimal();
		AAnimal& operator=(const AAnimal& rvalue);

		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0;
};

#endif
