#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdint>
#include <vector>
#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include "WavHeader.h"
#include "SoundFile.h"
class FileManager 
{
	private:
	  vector<SoundFile*> dirfiles;
	  string dirpath;
	  vector <string> fileNames;
	FILE* inFile;
	WAV_HEADER * wavObj;

	public:

	FileManager(string d);
	~FileManager();
	WAV_HEADER * readHeader(string fname);

	void readFiles();
	void writeFiles();
	void printFiles();
	void addFileName(string f);
};
#endif
