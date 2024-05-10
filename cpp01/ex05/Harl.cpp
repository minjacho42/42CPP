# include "Harl.hpp"

Harl::Harl():
	debug_msg("I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"),
	info_msg("I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"),
	warning_msg("I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."),
	error_msg("This is unacceptable! I want to speak to the manager now.")
	{}

Harl::Harl(const std::string& debug_msg, const std::string& info_msg, const std::string& warning_msg, const std::string& error_msg):
	debug_msg(debug_msg), info_msg(info_msg), warning_msg(warning_msg), error_msg(error_msg)
	{}

void Harl::debug()
{
	std::cout << debug_msg << std::endl;
}

void Harl::info()
{
	std::cout << info_msg << std::endl;
}

void Harl::warning()
{
	std::cout << warning_msg << std::endl;
}

void Harl::error()
{
	std::cout << error_msg << std::endl;
}

void Harl::complain(const std::string& level)
{
	int i;
	// Harl 맴버함수와 관련된 변수명이기 때문에
	// Harl에 속하는 함수 포인터 타입임을 명시해주어야 된다.
	// static 함수들에 대한 것인 경우에는 안써도 됨!
	void (Harl::*f_ptr[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string str_list[4] = {"debug", "info", "warning", "error"};

	for (i = 0; i < 4; i++) {
		if (!level.compare(str_list[i])) {
			(this->*f_ptr[i])();
			// f_ptr라는 함수 포인터 배열에서 i번째 함수 포인터가 가리키는 함수 (*f_ptr[i])이고,
			// 이때 이 함수는 this라는 인스턴스의 맴버함수이기에 this->를 써줘서 this의 내부 맴버변수를 참고 할 수 있게 한다.
			break;
		}
	}
	if (i == 4)
		std::cerr << "Level Doesn't Exist\n";
}
