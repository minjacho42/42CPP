#include "Replace.hpp"

void leaks() {system("leaks cpp01_ex04");}

int main(int argc, char **argv)
{
	if (argc != 4)
		return (1);
	Replace replace(argv[1], argv[2], argv[3]);
	replace.run();
	// atexit(leaks);
}
