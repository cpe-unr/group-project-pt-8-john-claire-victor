#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdint>
#include <vector>
#ifndef SOUND_FILE_H
#define SOUND_FILE_H
#include "WavHeader.h"
#include "FileInterface.h"
class SoundFile : public FileInterface
{
private:
	FILE* inFile;
	WAV_HEADER * wavObj;
	string fname;
	int fileSize;
	size_t bytesRead;
	int getFileSize();
public:
	void printFile();
	int readFile();
	void writeFile();
        void setHeader(WAV_HEADER * obj, string fn);
	SoundFile(string n);
	~SoundFile();
	SoundFile();
};

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
class Sixteenbit : public SoundFile
{
       unsigned short * data;
public:
	Sixteenbit(string n);
	~Sixteenbit();
	Sixteenbit();

	int readFile();
	void writeFile();
private:
	
};
#endif

