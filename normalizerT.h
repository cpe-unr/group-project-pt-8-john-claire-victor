/*
  ===================================================================
  Project Name: Semester Project
  Author: Claire Burkhardt
  Date: 4/29/21
  Filename: normalizerT.h
  ===================================================================
*/
#ifndef NORMALIZERT_H
#define NORMALIZERT_H

#include <iostream>
#include <typeinfo>
#include <cmath>
class normalizerProcessor {
    public:
     template <typename T >

/**
*Claire
*This normalizer file inputs the buffer and uses audio processing to normalize all sound up to a certain threshold. The max/min/zeroVal/max amplitude (Basically the math) is dependent on 8 bit vs 16 bit, but once those values are determined, the math is calculated in variable form so that it can accomodate stereo/mono and 8/16 bit.
*@param input the buffer with type unsigned char (8 bit) or short (16 bit). Type is dependant on input from template.
*@param input the integer value of the buffer's length.
*/

    void processNormalizer (T* buffer, int bufferSize) {


        unsigned char* EightPlace = NULL;
        signed short* SixteenPlace = NULL;

        int Max;
        int Min;
        int zeroVal;
        float absMaxAmplitude;
        float newMultiplier; 

        if ((typeid(buffer).name()) == typeid(EightPlace).name()) { 
            Max = 256;
            Min = 0;
            zeroVal = 128;
            absMaxAmplitude = 128;
        }

        if ((typeid(buffer).name()) == typeid(SixteenPlace).name()) {           
            Max = 32768;
            Min = -32768;
            zeroVal = 0;
            absMaxAmplitude = 32768;
        }
        int peakAmplitude = 0;

   	for(int idx = 0; idx < bufferSize; idx++) { 
        if ((buffer[idx] < Max) && (buffer[idx] > Min) ) {
    
            if (peakAmplitude < ( std::fabs ( std::fabs(buffer[idx]) - zeroVal) ) )  {
                peakAmplitude = std::fabs(std::fabs(buffer[idx]) - zeroVal); 
            }
        }
    }


    newMultiplier = (absMaxAmplitude / peakAmplitude);
 
    for (int i1 = 0; i1 < bufferSize; ++i1) {

        buffer[i1] *= newMultiplier;
    }  
     }
};

#endif //NORMALIZERT_H
