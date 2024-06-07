#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const Cure& instance);
		Cure& operator=(const Cure& rvalue);
		~Cure();

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
