//Created by Claire Burkhardt 3/21/21


class nGate {
    template <typename bitNum >

     processNoise (T* buffer, int bufferSize, /* getMono/Stero val, and also getPercent (needs user interface) */ ) {

    /* This code is for Mono
    hardcoding in percent to = 3%
        the distinction between mono and stereo is irrelevant here; we're still gating all the noise (Regardless of which channel) that falls below a certain threshold
     */
    
    int percent = 3;
    int minVal = 128 - 128*percent*.01;
	int maxVal =  128*percent*.01 + 128;

	for (int i2 = 0; i2 < bufferSize; i2++) {
		if ( (buffer[i2] < maxVal) && (buffer[i2] > minVal ) ) {
			buffer[i2] = 128;
		}

    }



    template <>
    signed short processNoise (signed short* buffer, int bufferSize,  /* get Percent */) {
//if our buffer is less than 32767*.03 and greater than -32767*.03; it now equals 0
// if buffer < maxVal*percent && buffer > minVal*percent
    int percent = 3;
    int minVal = -32767*.03
    

    }


};





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
