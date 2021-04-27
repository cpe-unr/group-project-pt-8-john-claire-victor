#include "FileManager.h"

	FileManager::FileManager(string d)
	{
		dirpath = d;
	}
	FileManager::~FileManager(){}


	WAV_HEADER * FileManager::readHeader(string fname)
	{
			
            WAV_HEADER * ptr = new  WAV_HEADER();
	    int headerSize = sizeof(wav_hdr);                                                                    
	    if ( inFile == nullptr )
	    {                      
	             cout << "unable to open file" << endl;  
	    }           
	    int bytesRead = fread(&wavObj, 1, headerSize, inFile);
	    cout << "Header Read: " << bytesRead << " bytes." << endl;
	    return ptr;
	}

	void FileManager::readFiles()
	{
		//go through dirpath and create and object (for loop) 10 <
		for (int i = 0 ; i < fileNames.size() ; i++ )
		{
			WAV_HEADER * wvhdr_ptr = readHeader(fileNames[i]);
			SoundFile* soundPtr = nullptr;
		        if(wvhdr_ptr-> audioFormat == 1)
		        {
			    soundPtr = new EightBit(); //(copy for sixteen bit)
		        }
		        else
			{
			    soundPtr = new SixteenBit(); //(copy for sixteen bit)
			}
			soundPtr->setHeader(wvhdr_ptr);
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

	void addFileName(string f)
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
