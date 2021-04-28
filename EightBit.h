#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdint>
#include <vector>
#ifndef EIGHT_BIT_H
#define EIGHT_BIT_H
#include "WavHeader.h"
#include "SoundFile.h"
class Eightbit : public SoundFile
{
        char * data;
public:
	Eightbit(string n);
	~Eightbit();
	int readFile();
	void writeFile();
	Eightbit();
private:
	
};
