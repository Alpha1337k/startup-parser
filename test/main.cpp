#include "../src/startup-parser.hpp"

static StartupParser sp;
#include <iostream>

int main(int argc, char **argv)
{
	sp = StartupParser(argc, argv);
	
	std::vector<std::pair<std::string, std::string> > itm = sp.getStorage();
	for (size_t i = 0; i < itm.size(); i++)
	{
		std::cout << itm[i].first << "===" << itm[i].second << std::endl;
	}
	
	std::cout << sp["data"] << "/" << sp.last().second << std::endl;
}