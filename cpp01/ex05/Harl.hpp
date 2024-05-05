#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

class Harl
{
	private:
		std::string debug_msg;
		std::string info_msg;
		std::string warning_msg;
		std::string error_msg;
		void debug();
		void info();
		void warning();
		void error();
	public:
		Harl();
		Harl(std::string debug_msg, std::string info_msg, std::string warning_msg, std::string error_msg);
		void complain(std::string level);
};

#endif
