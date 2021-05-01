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
	
protected:
	string fname;
	WAV_HEADER * wavObj;
	FILE* inFile;
	int fileSize;
	size_t bytesRead;
	int getFileSize();
public:
	virtual void printHeader();
	int readFile();
	void writeFile();
        void setHeader(WAV_HEADER * obj, string fn);
	SoundFile(string n);
	~SoundFile();
	SoundFile();
};
class Eightbit : public SoundFile
{
       unsigned char* data = NULL;
public:
	Eightbit(string n);
	//void printHeader();
	~Eightbit();
	int readFile();
	void writeFile(const std::string &outFileName);
	Eightbit();
private:
	
};
class Sixteenbit : public SoundFile
{
       unsigned char* data = NULL;
public:
	Sixteenbit(string n);
	~Sixteenbit();
	//void printHeader();
	Sixteenbit();

	int readFile();
	void writeFile();
private:
	
};
#endif

