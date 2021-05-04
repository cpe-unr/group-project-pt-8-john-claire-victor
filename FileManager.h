/**
* Created by John Jarvis 4/20/21	
**/

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
	/**
	* Constructor for my File Manager class
	*@param  string d is what I set "dirpath" (file directory path) too
	*@return
	**/
	FileManager(string d);
	/**
	* Destructor for filemanager class
	**/
	~FileManager();
	/**
	* Function that reads the entire WAV file, or displays an error if it cannot open the file, or no file is there.
	*@param  fname is the name of the files inputed into the program
	*@return wavObj = the technical data of the inputed file
	**/
	WAV_HEADER * readHeader(string fname);
	/**
	* Function that goes through the file read in with the "ReadHeader" function, and checks a specific variable found within the wavheader.h file to decide whether it is an 8, or 16 bit, audio file. The function then sends the file data to an appropirate 8/16 bit class for file processing.
	**/
	void readFiles();
	/**
	* Function that gets the size of the files inputed, and then sends the data to a writefile function.
	**/
	void writeFiles();
	void printFiles();
	/**
	* Function that adds the name of every file inputed on the command line.
	*@param f = filename placeholder.
	**/
	void addFileName(string f);
};
#endif
