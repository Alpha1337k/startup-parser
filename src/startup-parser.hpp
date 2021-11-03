#ifndef STARTUP_PARSER
#define STARTUP_PARSER

#include <map>
#include <string>

class StartupParser
{
private:
	std::map<std::string, std::string> _items;
	std::pair<std::string, std::string> _last;
public:
	StartupParser() {}
	StartupParser(int argc, char **argv, bool skipfirst=true)
	{
		std::string delim = "=";
		for (int i = 0 + skipfirst; i < argc; i++)
		{
			
			std::string toadd(argv[i]);
			_items[toadd.substr(0, toadd.find(delim))] = toadd.substr(toadd.find(delim) + delim.length(), std::string::npos);
		}
		if (argc >= 1)
		{
			std::string toadd(argv[argc - 1]);
			_last = std::make_pair(toadd.substr(0, toadd.find(delim)), toadd.substr(toadd.find(delim) + delim.length(), std::string::npos));
		}
	}
	StartupParser(const StartupParser &sp) { *this = sp;}
	StartupParser &operator=(const StartupParser &sp)
	{
		_items = sp._items;
		_last = sp._last;

		return *this;
	}
	std::string *operator[](std::string idx)
	{
		std::map<std::string, std::string>::iterator iter = _items.find(idx);
		if (iter == _items.end())
			return 0;
		return &iter->second;
	}
	std::pair<std::string, std::string>	&last()
	{
		return _last;
	}
	std::map<std::string, std::string>	&getStorage()
	{
		return _items;
	}
	~StartupParser() {}
};

#endif