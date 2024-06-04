#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <string>
# include <iostream>

class Cat: public Animal
{
	public:
		Cat();
		Cat(const Cat& instance);
		~Cat();
		Cat& operator=(const Cat& rvalue);

		void	makeSound(void) const;
};

#endif
