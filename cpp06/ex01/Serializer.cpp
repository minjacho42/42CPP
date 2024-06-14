#include "Serializer.hpp"

Serializer::~Serializer() {}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::desrialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
