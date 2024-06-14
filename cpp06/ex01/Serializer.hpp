#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
# include <stdint.h>

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& instance);
		Serializer& operator=(const Serializer& rvalue);
		~Serializer();
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data			*desrialize(uintptr_t raw);
};

#endif
