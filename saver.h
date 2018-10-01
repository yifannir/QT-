#include "global.h"

class Saver
{
public:
	Saver(std::string init_path);
	~Saver();
	void save();

public:
	std::string path;
};

