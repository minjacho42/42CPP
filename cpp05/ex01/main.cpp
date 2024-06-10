#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat	intern = Bureaucrat("minjacho", 145);
	Bureaucrat	boss = Bureaucrat("Boss", 3);
	Form		lunch_menu = Form("lunch menu", 148, 150);
	Form		launch_bomb = Form("launch bomb", 10, 10);

	std::cout << intern << "\n" << boss << "\n" << lunch_menu << "\n" << launch_bomb << std::endl;
	intern.signForm(lunch_menu);
	std::cout << lunch_menu << std::endl;
	intern.signForm(launch_bomb);
	std::cout << launch_bomb << std::endl;
	boss.signForm(launch_bomb);
	std::cout << launch_bomb << std::endl;
}
