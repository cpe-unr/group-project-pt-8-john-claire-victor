#include "SoundFile.h"

	
	Sixteenbit::Sixteenbit(string n) : SoundFile(n)
	{
	}
	Sixteenbit::~Sixteenbit(){}
	Sixteenbit::Sixteenbit(){}
	int Sixteenbit::readFile()
	{
		 std::ifstream file(fname,std::ios::binary | std::ios::in);
	    if(file.is_open()){
		//file.read((char*)&wavObj, sizeof(wav_hdr));
		data = new unsigned char[wavObj->bytesPerSec];
		file.read(reinterpret_cast<char*>(data), wavObj->bytesPerSec);
		}
		file.close();
		
	}
	void Sixteenbit::writeFile(const std::string &outFileName)
	{
		ofstream outFile(outFileName, std::ios::out | std::ios::binary);
		outFile.write((char*)&wavObj,sizeof(wav_hdr));
		outFile.write((char*)data, wavObj -> bytesPerSec);
		outFile.close();
	}

