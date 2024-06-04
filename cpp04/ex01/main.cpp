
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Dog *Dog1 = new Dog();
	Dog *Dog2 = new Dog();
	Brain *new_brain1 = new Brain();
	Brain *new_brain2 = new Brain();
	std::string *ideas = new std::string[100];

	ideas[0] = "meaw";
	ideas[4] = "I want some fish";
	new_brain1->setIdeas(ideas);
	Dog1->setBrain(*new_brain1);
	*Dog2 = *Dog1;

	Dog1->printBrain();
	Dog2->printBrain();
	ideas[5] = "I want some cheeze";
	new_brain2->setIdeas(ideas);
	Dog2->setBrain(*new_brain2);
	Dog1->printBrain();
	Dog2->printBrain();
	// system("leaks cpp04_ex01");
}
