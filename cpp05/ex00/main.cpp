#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat intern = Bureaucrat("minjacho", 145);
		Bureaucrat boss = Bureaucrat("Boss", 3);
		try
		{
			while (true)
			{
				intern.decreaseGrade();
				std::cout << intern << std::endl;
			}
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			while (true)
			{
				boss.increaseGrade();
				std::cout << boss << std::endl;
			}
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << intern << "\n" << boss << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
