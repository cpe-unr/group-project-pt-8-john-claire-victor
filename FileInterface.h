/**
* Created by John Jarvis 4/20/21	
**/
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdint>
#include <vector>
#ifndef FILE_INTERFACE_H
#define FILE_INTERFACE_H


class FileInterface
{
	public:
		/**
		* ABC that all classes that inherit this must use. Function is used to print the technical contents of a WAV file.
		**/
		virtual void printHeader() = 0;
		/**
		* ABC that all classes that inherit this must use. Function is used to read the contents of a wav fie.
		**/
		virtual int readFile() = 0;
		/**
		* ABC that all classes that inherit this must use. Function is used to write the contents of a wav file.
		**/
		virtual void writeFile()= 0;
};

#endif
