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
	/**
	* Gets the file size(s) for inputed file(s), and then returns the size of the files for future use. Made protected so that my child classes can use the file size aswell.
	*@return fileSize = size of all inputed file(s), int value.
	**/
	int getFileSize();
public:
	/**
	* Prints the technical data of a WAV file.
	*@return
	**/
	virtual void printHeader();
	
	/**
	* Setter for soundFile variables.
	*@param obj = war_header object so that this class can use wav_header variables
	*@param fn = filename inputed
	*@return
	**/
        void setHeader(WAV_HEADER * obj, string fn);
	/**
	* Parameterized constructor for SoundFile
	*@param n = placeholder that takes the name of the inputed file and sets it equal to fname.
	*@return
	**/
	SoundFile(string n);
	/**
	* Destructor for SoundFile
	*@return
	**/
	~SoundFile();
	/**
	* Default constructor for SoundFile
	*@return
	**/
	SoundFile();
};
class Eightbit : public SoundFile
{
       unsigned char* data = NULL;
public:
	/**
	* Parameterized constructor that initializes a variable from the parent soundFile class
	*@param string n is the file name that is then set to the fname variable
	**/
	Eightbit(string n);
	//void printHeader();
	/**
	* Destructor for Sixteenbit
	**/
	~Eightbit();
	/**
	* Function that reads the sound file so it can be used to create sound.
	**/
	int readFile();
	/**
	* Function that is supposed to write out the sound file.
	*@param outFileName = name of the new wav file outputed.
	**/
	void writeFile(const std::string &outFileName);
	/**
	* Default Constructor
	**/
	Eightbit();
private:
	
};
class Sixteenbit : public SoundFile
{
       unsigned char* data = NULL;
public:
	/**
	* Parameterized constructor that initializes a variable from the parent soundFile class
	*@param string n is the file name that is then set to the fname variable
	**/
	Sixteenbit(string n);
	/**
	* Destructor for Sixteenbit
	**/
	~Sixteenbit();
	//void printHeader();
	Sixteenbit();
	/**
	* Function that reads the sound file so it can be used to create sound.
	**/
	int readFile();
	/**
	* Function that is supposed to write out the sound file.
	**/
	void writeFile(const std::string &outFileName);
private:
	
};
#endif

