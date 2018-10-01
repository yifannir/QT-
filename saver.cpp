#include "saver.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
Saver::Saver(std::string init_path)
{
	path = init_path;
}

Saver::~Saver()
{
}

void Saver::save()
{
	ofstream os(path, ios::binary);


	//FILE.close();
}
