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
		cout <<"+++" <<data[0] << endl;
		}
		file.close();
		
	}
	void Sixteenbit::writeFile()
	{
	}

