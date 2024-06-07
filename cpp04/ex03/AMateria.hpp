#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	private:
		AMateria();
	protected:
		std::string type;
	public:
		AMateria(const std::string& type);
		AMateria(const AMateria& instance);
		AMateria& operator=(const AMateria& rvalue);
		virtual ~AMateria();

		const std::string& getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target) = 0;
};

#endif
