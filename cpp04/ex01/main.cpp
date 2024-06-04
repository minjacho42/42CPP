
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
}

// #include "WrongAnimal.hpp"
// #include "WrongCat.hpp"

// int main()
// {
// 	const WrongAnimal* meta = new WrongAnimal();
// 	const WrongAnimal* wrongcat = new WrongCat();

// 	std::cout << meta->getType() << std::endl;
// 	std::cout << wrongcat->getType() << std::endl;
// 	meta->makeSound();
// 	wrongcat->makeSound();
// 	delete meta;
// 	delete wrongcat;
// }
