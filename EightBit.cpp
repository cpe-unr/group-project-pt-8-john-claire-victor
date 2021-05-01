	#include "SoundFile.h"
	
	Eightbit:: Eightbit(string n) : SoundFile(n)
	{
	}
	Eightbit::Eightbit(){}
	Eightbit::~Eightbit(){}
	int Eightbit:: readFile()
	{
		cout << "8-bit readfile called" << endl;
	    std::ifstream file(fname,std::ios::binary | std::ios::in);
	    if(file.is_open()){
		//file.read((char*)&wavObj, sizeof(wav_hdr));
		data = new unsigned char[wavObj->bytesPerSec];
		file.read((char*)data, wavObj->bytesPerSec);
		cout <<"***" << data[0] << endl;
		}
		file.close();
	}
	void Eightbit::writeFile(const std::string &outFileName)
	{
		ofstream outFile(outFileName, std::ios::out | std::ios::binary);
		outFile.write((char*)&wavObj,sizeof(wav_hdr));
		outFile.write((char*)data, wavObj -> bytesPerSec);
		outFile.close();
	}
