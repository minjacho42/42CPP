#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character: public ICharacter
{
	private:
		std::string			name;
		AMateria			*materia_list[4];
		int					materia_list_len;
		static const int	materia_list_size = 4;

		Character();
	public:
		Character(const std::string& name);
		Character(const Character& instance);
		Character& operator=(const Character& rvalue);
		~Character();
		const std::string& getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
