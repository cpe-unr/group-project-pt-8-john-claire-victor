#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdint>
#include <vector>
#include "WavHeader.h"
#include "FileManager.h"
using namespace std;


int main( int argc, char* argv [])
{
		//WAV_HEADER wavObj;
		int headerSize = sizeof(wav_hdr), filelength = 0;
		
		const char* filePath;
		string input;
		if (argc <= 1)
		{
			cout << "Input wav file name: ";
			cin >> input;
			cin.get();
			filePath = input.c_str();
		}
		else
		{
			filePath = argv[1];
			cout << "Input wav file name: " << filePath << endl;
		}
		FileManager fmgrObj(filePath);
		for(int i = 0 ; i < argc ; i ++)
		{
			fmgrObj.addFileName(argv[i]);
		}
		fmgrObj.readFiles();
		fmgrObj.printFiles();
		
		return 0;
}
