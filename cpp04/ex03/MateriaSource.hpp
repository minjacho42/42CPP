#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria			*materia_list[4];
		int					materia_list_len;
		static const int	materia_list_size = 4;

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& instance);
		MateriaSource& operator=(const MateriaSource& rvalue);
		~MateriaSource();

		virtual void learnMateria(AMateria *);
		virtual AMateria *createMateria(const std::string& type);
};

#endif
