#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

Base	*generate(void);
void	identify(Base *p);
void	identify(Base& p);

int main()
{
	A	a;
	B	b;
	C	c;
	Base	*base = generate();

	identify(base);
	identify(a);
	identify(b);
	identify(c);
}

Base *generate(void)
{
	Base	*result;

	std::srand(std::clock());
	switch (std::rand() % 3)
	{
		case 0:
			result =  new A();
			break;
		case 1:
			result = new B();
			break;
		case 2:
			result = new C();
			break;
		default:
			result = NULL;
			break;
	}
	return result;
}

void identify(Base *p)
{
	A	*a;
	B	*b;
	C	*c;

	a = dynamic_cast<A *>(p);
	if (a)
		std::cout << 'A' << std::endl;
	b = dynamic_cast<B *>(p);
	if (b)
		std::cout << 'B' << std::endl;
	c = dynamic_cast<C *>(p);
	if (c)
		std::cout << 'C' << std::endl;
}

void identify(Base& p)
{
	A	a;
	B	b;
	C	c;

	try
	{
		a = dynamic_cast<A&>(p);
		std::cout << 'A' << std::endl;
	}
	catch (std::exception &e)
	{}
	try
	{
		b = dynamic_cast<B&>(p);
		std::cout << 'B' << std::endl;
	}
	catch (std::exception &e)
	{}
	try
	{
		c = dynamic_cast<C&>(p);
		std::cout << 'C' << std::endl;
	}
	catch (std::exception &e)
	{}
}
