#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <string>
# include <iostream>

class WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat& instance);
		~WrongCat();
		WrongCat& operator=(const WrongCat& rvalue);

		void	makeSound(void) const;
};

#endif
