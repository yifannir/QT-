#include "global.h"
class Reader
{
public:
	Reader(std::string init_path);
	~Reader();
	void read();
public:
	std::string path;
};

