
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void leaks(void)
{
	system("leaks cpp04_ex01");
}

int main()
{
	Cat *Cat1 = new Cat();
	Cat *Cat2 = new Cat();
	Dog *Dog1 = new Dog();
	Dog *Dog2 = new Dog();
	Brain *new_brain = new Brain();
	std::string *ideas = new std::string[100];
	Animal *animal_list[10];

	atexit(leaks);
	std::cout << "======== Deep Copy Test ========" << std::endl;

	ideas[0] = "meaw";
	ideas[4] = "I want some fish";
	new_brain->setIdeas(ideas);
	Cat1->setBrain(*new_brain);
	*Cat2 = *Cat1;

	Cat1->printBrain();
	Cat2->printBrain();
	ideas[4] = "I want some cheeze";
	new_brain->setIdeas(ideas);
	Cat2->setBrain(*new_brain);
	Cat1->printBrain();
	Cat2->printBrain();

	ideas[0] = "Bow";
	ideas[4] = "I want some gum";
	new_brain->setIdeas(ideas);
	Dog1->setBrain(*new_brain);
	*Dog2 = *Dog1;

	Dog1->printBrain();
	Dog2->printBrain();
	ideas[4] = "I want some meat";
	new_brain->setIdeas(ideas);
	Dog2->setBrain(*new_brain);
	Dog1->printBrain();
	Dog2->printBrain();

	std::cout << "======== Animal Object Array Test ========" << std::endl;

	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			animal_list[i] = new Cat();
		else
			animal_list[i] = new Dog();
	}
	for (int i = 0; i < 10; i++)
	{
		animal_list[i]->makeSound();
	}
	std::cout << "======== Descturctor Called ========" << std::endl;
	delete Cat1;
	delete Cat2;
	delete Dog1;
	delete Dog2;
	delete new_brain;
	delete[] ideas;
	for (int i = 0; i < 10; i++)
		delete animal_list[i];
}
