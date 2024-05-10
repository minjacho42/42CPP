# include "Harl.hpp"

int main()
{
	Harl harl1;
	Harl harl2(
		"debug message",
		"info message",
		"warning message",
		"error message"
	);
	harl1.complain("warning");
	// harl2.complain("error");
}
