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
		virtual void printFile() =0;
		virtual int readFile() = 0;
		virtual void writeFile()= 0;
};

#endif
