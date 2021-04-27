#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdint>
#ifndef WAV_HEADER_H
#define WAV_HEADER_H
using namespace std;

typedef struct WAV_HEADER
{

	//RIFF HEADERs
	uint8_t RIFF[4];
	uint32_t ChunkSize;
	uint8_t WAVE[4];
	//FMT Stuff
	uint8_t fmt[4];
	uint32_t subChunk1Size;
	uint16_t audioFormat;
	uint16_t numOfChan;			// 1 for Mono, 2 for Stereo
	uint32_t samplesPerSec;
	uint32_t bytesPerSec;
	uint16_t blockAlign;
	uint16_t bitsPerSample; 
	//"data" chunk
	uint8_t subChunk2ID[4];
	uint32_t subChunk2Size; 
}wav_hdr;
#endif
