#include "SoundFile.h"

	SoundFile::SoundFile()
	{
		fileSize = 0;
		bytesRead = 0;
		inFile = NULL;
	}
	SoundFile::SoundFile(string n)
	{
		fname = n;
		fileSize = 0;
		bytesRead = 0;
		inFile = NULL;
	}
	SoundFile::~SoundFile()
	{
		fclose(inFile);
	}
	void SoundFile::setHeader(WAV_HEADER * obj, string fn)
	{
		
		wavObj = obj;
		bytesRead = sizeof(WAV_HEADER);
		fname = fn;
	}

	int SoundFile::getFileSize()
	{
		
		fseek(inFile, 0, SEEK_END);
	
		fileSize = ftell(inFile);
	
		fseek(inFile, 0, SEEK_SET);
		return fileSize;
	}
	void SoundFile::printHeader()
	{
		cout << "bytes per Sample printed: " << wavObj->bitsPerSample << endl;
		
		uint16_t bytesPerSample = wavObj->bitsPerSample / 8;
		uint64_t numSamples = wavObj->ChunkSize / bytesPerSample;
		static const uint16_t BUFFER_SIZE = 4096;
			
		getFileSize();
			
		cout << "File is: " << fileSize <<" bytes"<< endl; 
		cout << "RIFF header: " << wavObj->RIFF[0] << wavObj->RIFF[1] << wavObj->RIFF[2] << wavObj->RIFF[3] << endl;
		cout << "WAVE header: " << wavObj->WAVE[0] << wavObj->WAVE[1] << wavObj->WAVE[2] << wavObj->WAVE[3] << endl;
		///FMT chunk
		cout<< "FMT: " << wavObj->fmt[0] << wavObj->fmt[1] << wavObj->fmt[2] << wavObj->fmt[3] << endl;
		cout<< "Data size: " << wavObj->ChunkSize << endl;
			
		//sampling stuff
		cout << "Sampling Rate: " << wavObj->samplesPerSec << endl;
		cout << "Number of bits used: " << wavObj->bitsPerSample << endl;
		cout << "Number of Channels: " << wavObj->numOfChan << endl; //1 for mono, 2 for stereo
		cout << "Number of Bytes per Second: " << wavObj->bytesPerSec << endl;
		cout << "Data Length: " << wavObj->subChunk2Size << endl;
		cout << "Audio Format: " << wavObj->audioFormat << endl;
	}
		int SoundFile::readFile()
	{
	    /****  DO NOTHING; actual data is read in EightBit and SixteenBit class
		inFile = fopen(fname.c_str(), "r");
		int headerSize = sizeof(wav_hdr);
		if ( inFile == nullptr )
		{
			cout << "unable to open file" << endl;
		}
		bytesRead = fread(&wavObj, 1, headerSize, inFile);
			
		cout << "Header Read: " << bytesRead << " bytes." << endl;
		
		return bytesRead;
		****/
	}
	void SoundFile::writeFile()
	{
		//do not touch, thank you.
	}
