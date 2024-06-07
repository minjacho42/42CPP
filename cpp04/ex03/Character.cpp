#include "Character.hpp"

Character::Character(const std::string& name): name(name)
{
	materia_list_len = 0;
}

Character::Character(const Character& instance)
{
	*this = instance;
}

Character& Character::operator=(const Character& rvalue)
{
	if (this == &rvalue)
		return (*this);
	for (int i = 0; i < materia_list_len; i++)
		materia_list[i] = NULL;
	for (int i = 0; i < rvalue.materia_list_len; i++)
		materia_list[i] = rvalue.materia_list[i]->clone();
	materia_list_len = rvalue.materia_list_len;
	name = rvalue.name;
	return (*this);
}

Character::~Character()
{
	std::cout << "[Character]: destructor called" << std::endl;
}

const std::string& Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria *m)
{
	if (materia_list_len < materia_list_size)
	{
		materia_list[materia_list_len] = m;
		materia_list_len++;
	}
	else
	{
		for (int i = 1; i < materia_list_size; i++)
			materia_list[i - 1] = materia_list[i];
		materia_list[materia_list_size - 1] = m;
	}
}

void Character::unequip(int idx)
{
	if (idx > materia_list_len - 1 || idx < 0)
		return ;
	for (int i = idx + 1; i < materia_list_len; i++)
		materia_list[i - 1] = materia_list[i];
	materia_list[materia_list_len - 1] = NULL;
	materia_list_len--;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx > materia_list_len - 1 || idx < 0)
	{
		std::cerr << "[Character]: "
			<< "not valid idx" << std::endl;
		return ;
	}
	materia_list[idx]->use(target);
}
