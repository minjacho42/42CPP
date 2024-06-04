#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <string>
# include <iostream>

class Cat: public Animal
{
	private:
		Brain	*brain;
	public:
		Cat();
		Cat(const Cat& instance);
		~Cat();
		Cat& operator=(const Cat& rvalue);

		void			makeSound(void) const;
		void			setBrain(Brain& brain);
		const Brain&	getBrain(void) const;
		void			printBrain(void) const;
};

#endif
