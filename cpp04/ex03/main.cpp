#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

// int main()
// {
// 	IMateriaSource *src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());

// 	ICharacter *me = new Character("me");

// 	AMateria *tmp1;
// 	AMateria *tmp2;
// 	tmp1 = src->createMateria("ice");
// 	me->equip(tmp1);
// 	tmp2 = src->createMateria("cure");
// 	me->equip(tmp2);

// 	ICharacter *bob = new Character("bob");

// 	me->use(0,*bob);
// 	me->use(1,*bob);
// 	me->use(2,*bob);

// 	delete bob;
// 	delete me;
// 	delete src;
// 	delete tmp1;
// 	delete tmp2;
// }

int main()
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");

	AMateria *tmp1;
	AMateria *tmp2;
	tmp1 = src->createMateria("ice");
	me->equip(tmp1);
	tmp2 = src->createMateria("cure");
	me->equip(tmp2);

	ICharacter *bob = new Character("bob");

	me->use(0,*bob);
	me->use(1,*bob);
	me->use(2,*bob);

	*bob = *me;
	bob->unequip(1);
	bob->unequip(0);
	bob->equip(tmp2);
	bob->use(0,*me);
	bob->use(1,*me);
	bob->use(2,*me);

	me->use(0,*bob);
	me->use(1,*bob);
	me->use(2,*bob);

	delete bob;
	delete me;
	delete src;
	delete tmp1;
	delete tmp2;
}
