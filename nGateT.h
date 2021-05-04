/*
  ===================================================================
  Project Name: Semester Project
  Author: Claire Burkhardt
  Date: 4/26/21
  Filename: nGateT.h
  ===================================================================
*/

#ifndef NGATET_H
#define NGATET_H

#include <cstddef>
#include <typeinfo>

class nGateProcessor {
    public:

    template <typename T >

/**
*Claire
*This noise gate file inputs the buffer and uses audio processing to decrease all sound below a certain threshold (like 5% of the max value) to 0. The max/min/zeroVal (Basically the math) is dependent on 8 bit vs 16 bit, but once those values are determined, the math is calculated in variable form so that it can accomodate stereo/mono and 8/16 bit. Mono/stereo is irrelevant, since we're still gating all noise below a threshold regardless of which channel it comes from.
*@param input the buffer with type unsigned char (8 bit) or short (16 bit). Type is dependant on input from template.
*@param input the integer value of the buffer's length.
*/

    void processNoise (T* buffer, int bufferSize) {

        unsigned char* EightPlace = NULL;
        signed short* SixteenPlace = NULL;

        int percent;
        int minVal;
        int maxVal;
        int zeroVal;
            if ((typeid(buffer).name()) == typeid(EightPlace).name()) {
            percent = 5;
            minVal = 128 - 128*percent*.01;
	        maxVal =  128*percent*.01 + 128;
            zeroVal = 128;
        }

        if ((typeid(buffer).name()) == typeid(SixteenPlace).name()) {   
            percent = 5;
            minVal = -32768*.03;
            maxVal = 32767*.03;
            zeroVal = 0;
     }

        for (int i = 0; i < bufferSize; i++) {
		    if ( (buffer[i] < maxVal) && (buffer[i] > minVal ) ) {
			    buffer[i] = zeroVal;
            }

        }

    }
};


#endif //NGATE_H
