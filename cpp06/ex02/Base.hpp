#ifndef BASE_HPP
# define BASE_HPP

# include <cstdlib>
# include <ctime>
# include <exception>

class Base
{
	public:
		Base();
		virtual ~Base();
		static Base	*generate(void);
		static void	identify(Base *p);
		static void	identify(Base& p);
};

#endif
