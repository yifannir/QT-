#include "reader.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <istream>
#include <fstream>
using namespace std;


Reader::Reader(std::string init_path)
{
	path = init_path;
}


Reader::~Reader()
{
}

void Reader::read()
{
	
	shapeList.clear();

}
