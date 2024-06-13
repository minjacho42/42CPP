#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
	Data *ptr = new Data(1999, 1.9, 1999.0109);
	Data *new_ptr = Serializer::desrialize(Serializer::serialize(ptr));

	std::cout << *ptr << std::endl;
	std::cout << *new_ptr << std::endl;
	delete ptr;
}
