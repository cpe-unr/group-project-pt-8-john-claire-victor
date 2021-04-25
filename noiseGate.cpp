//Created by Claire Burkhardt 3/21/21

#include "noiseGate.h"

Noise::Noise(int percent) : percent(percent) {}

void Noise::processBuffer(unsigned char* buffer, int bufferSize) {

short waveform = 0100;
    //waveform == 0100 (actually 0001) -> mono; == 0200 (actually 0002) -> stereo

    short datasize = 0001;
    // if it == 0001 -> 8-bit? ; and 0010 -> 16 bit?

    if (datasize == 0001) {
    	minVal = 128 - 128*percent*.01;
		maxVal =  128*percent*.01 + 128;
		zeroVal = 128;     
    }
    if (datasize == 0010) {
    //or whatever it is for 16 bit
    	minVal = 32768*percent*.01;
		maxVal =  32767*percent*.01;
		zeroVal = 0;
    }



	for (int i2 = 0; i2 < bufferSize; i2++) {
		if ( ( (buffer[i2]) < maxVal) && (std::abs(buffer[i2]) > minVal ) ) {
			buffer[i2] = zeroVal;
		}
	
	}


}
