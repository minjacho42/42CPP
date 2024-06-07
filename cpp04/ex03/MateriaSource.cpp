#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	materia_list_len = 0;
}

MateriaSource::MateriaSource(const MateriaSource& instance)
{
	*this = instance;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rvalue)
{
	if (this == &rvalue)
		return (*this);
	for (int i = 0; i < materia_list_len; i++)
		delete materia_list[i];
	for (int i = 0; i < rvalue.materia_list_len; i++)
		materia_list[i] = rvalue.materia_list[i]->clone();
	materia_list_len = rvalue.materia_list_len;
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "[MateriaSource]: destructor called" << std::endl;
	for (int i = 0; i < materia_list_len; i++)
		delete materia_list[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (materia_list_len < materia_list_size)
	{
		materia_list[materia_list_len] = m;
		materia_list_len++;
	}
	else
	{
		delete materia_list[0];
		for (int i = 1; i < materia_list_size; i++)
			materia_list[i - 1] = materia_list[i];
		materia_list[materia_list_size - 1] = m;
	}
}

AMateria *MateriaSource::createMateria(const std::string& type)
{
	int i;
	for (i = 0; i < materia_list_len; i++)
	{
		if (materia_list[i]->getType().compare(type) == 0)
			break;
	}
	if (i < materia_list_len)
		return (materia_list[i]->clone());
	else
		return NULL;
}
