#include "FileManager.h"

	FileManager::FileManager(string d)
	{
		dirpath = d;
		inFile = nullptr;
	}
	FileManager::~FileManager(){}


	WAV_HEADER * FileManager::readHeader(string fname)
	{
		cout << "readHeader called!"<< fname << endl;
        WAV_HEADER * wavObj = new  WAV_HEADER();
		int headerSize = sizeof(wav_hdr);
		inFile = fopen(fname.c_str(), "r");                         
			if ( inFile == nullptr )
			{                      
			         cout << "unable to open file" << endl;  
			}           
	    int bytesRead = fread(wavObj, 1, headerSize, inFile);
	    cout << "Header Read: " << bytesRead << " bytes." << endl;
		cout << "Printing Channels: " << wavObj -> numOfChan << endl;
	    return wavObj;
	}

	void FileManager::readFiles()
	{
		//go through dirpath and create and object (for loop) 10 <
		cout << "readFiles FMGR called!" << endl;
		for (int i = 0 ; i < fileNames.size() ; i++ )
		{

			cout << "File Names: " << fileNames[i] << endl;
			WAV_HEADER * wvhdr_ptr = readHeader(fileNames[i]);
			cout << "readFiles FMGR for loop called! 1 " << wvhdr_ptr <<
"Printing out numOfChan: " << wvhdr_ptr -> numOfChan << "Printing i: " << i << endl;
			SoundFile* soundPtr = nullptr;
		        if(wvhdr_ptr -> numOfChan == 1)
		        {
				cout << "creating 8 bit ptr" << endl;
			    soundPtr = new Eightbit(); //(copy for sixteen bit)
		        }
		        else
				{
				cout << "creating 16 bit ptr" << endl;
			    soundPtr = new Sixteenbit(); //(copy for sixteen bit)
				}
			
			soundPtr->setHeader(wvhdr_ptr, fileNames[i]);
			soundPtr -> printHeader();
			soundPtr->readFile();
    		dirfiles.push_back(soundPtr);
	    }
    }

	void FileManager::writeFiles()
	{
		//go through dirpath and create and object (for loop) 10 <
		for (int i = 0 ; i < dirfiles.size() ; i++ )
		{
    			dirfiles[i]->writeFile();
	    }
    }

	void FileManager::addFileName(string f)
	{
		fileNames.push_back(f);
	}

	void FileManager::printFiles()
	{
		//for (int i = 0 ; i < 10 ; i++ )
		//{
		//	SoundFile* ptr = new SoundFile("name of file.wav");
		//	ptr -> readFiles();
		// dirfiles.push_back(ptr);
		//}
	}
