#include "../src/startup-parser.hpp"

static StartupParser sp;
#include <iostream>

int main(int argc, char **argv)
{
	sp = StartupParser(argc, argv);
	
	std::cout << *sp["data"] << std::endl;
}