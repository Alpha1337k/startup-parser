#ifndef STARTUP_PARSER
#define STARTUP_PARSER

#include <vector>
#include <string>

class StartupParser
{
private:
	std::vector<std::pair<std::string, std::string> > _items;
public:
	StartupParser() {}
	StartupParser(int argc, char **argv, bool skipfirst=true)
	{
		_items.reserve(argc);
		std::string delim = "=";
		for (int i = 0 + skipfirst; i < argc; i++)
		{			
			std::string toadd(argv[i]);
			_items.push_back(std::make_pair(toadd.substr(0, toadd.find(delim)), toadd.substr(toadd.find(delim) + delim.length(), std::string::npos)));
		}
	}
	StartupParser(const StartupParser &sp) { *this = sp;}
	StartupParser &operator=(const StartupParser &sp)
	{
		_items = sp._items;

		return *this;
	}
	std::string *operator[](std::string idx)
	{
		for (size_t i = 0; i < _items.size(); i++)
		{
			if (_items[i].first == idx)
				return &_items[i].second;			
		}
		return 0;
	}
	std::pair<std::string, std::string>	&last()
	{
		return _items.back();
	}
	std::vector<std::pair<std::string, std::string> >	&getStorage()
	{
		return _items;
	}
	~StartupParser() {}
};

#endif