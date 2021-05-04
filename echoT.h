/*
  ===================================================================
  Project Name: Semester Project
  Author: Claire Burkhardt
  Date: 2/24/21
  Filename: EchoT.h
  ===================================================================
*/

#ifndef ECHOT_H
#define ECHOT_H


#include <cstdint>
#include <typeinfo>
#include <iostream>

class echoProcessor {

    public:
    
    template <typename T >
/**
*Claire
*This echo file inputs the buffer and uses audio processing to add an echo. The max/min/zeroVal (Basically the math) is dependent on 8 bit vs 16 bit, but once those values are determined, the math is calculated in variable form so that it can accomodate stereo/mono and 8/16 bit. Dr. Lancaster said in class that the echo processing shouldn't segment out the stereo audio channels, so there's no audio processing difference for mono/stereo in this function 
*@param input the buffer with type unsigned char (8 bit) or short (16 bit). Type is dependant on input from template
*@param input the integer value of the buffer's length
*@param input whether the buffer is stereo or mono (2 or 1)
*/
    void processEcho (T* buffer, int bufferSize, uint16_t numOfChan) {

        unsigned char* EightPlace = NULL;
        signed short* SixteenPlace = NULL;

        
        int Max;
        int Min;
        int timeDelay;
	int zeroVal;
        if ((typeid(buffer).name()) == typeid(EightPlace).name()) {
            Max = 255;
            Min = 0;
            timeDelay = 30000;
	    zeroVal = 128;
        }

        if ((typeid(buffer).name()) == typeid(SixteenPlace).name()) {               
            Max = 32768;
            Min = -32767;
            timeDelay = 30000;
	    zeroVal = 0;
      
            }


            for (int i = timeDelay; i < bufferSize; i++) {


		if (Max  < ( ( (buffer[i] - zeroVal) + (buffer[i - timeDelay] - zeroVal)*.5 ) + zeroVal) ) {
		    buffer[i] = Max;
                }
                else if (Min > ( ( (buffer[i] - zeroVal) + (buffer[i - timeDelay] - zeroVal)*.5 ) + zeroVal) )  {
                    buffer[i] = Min;

                }
                else {
                    buffer[i] = ( ( (buffer[i] - zeroVal) + (buffer[i - timeDelay] - zeroVal)*.5 ) + zeroVal);
                }
            }

 	}
};

#endif //ECHOT_H
