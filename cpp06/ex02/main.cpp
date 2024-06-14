#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	A	a;
	B	b;
	C	c;
	Base	*base = Base::generate();

	Base::identify(base);
	Base::identify(a);
	Base::identify(b);
	Base::identify(c);
}
