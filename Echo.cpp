/*Created by Claire Burkhardt 4/18/21
*/
#include "Echo.h"

Echo::Echo(int timeDelay) : timeDelay(timeDelay) {}

void Echo::processBuffer(unsigned char* buffer, int bufferSize) {
//overriding processbuffer
    short waveform = 0100;
    //waveform == 0100 (actually 0001) -> mono; == 0200 (actually 0002) -> stereo

    short datasize = 0001;
    // if it == 0001 -> 8-bit? ; and 0010 -> 16 bit?

    if (datasize == 0001) {
        Max = 255;
        Min = 0;
    }
    if (datasize == 0010) {
    //or whatever it is for 16 bit
        Max = 32768;
        Min = -32767;
    }



	if (waveform == 0100) {
		/* mono, don't have to worry with dual buffers
		*/
		for (int i = timeDelay; i < bufferSize; i ++ ) {
//			std::cout << buffer[i] << std::endl;
			if (Max  < (buffer[i] + buffer[i - timeDelay]*.45)) {
				buffer[i] = Max;
			}
			//if (datasize == 0010) {
				//compensating for the fact that audio in 16 bit runs negative
			//	if (Min > (buffer[i] + buffer[i - timeDelay]*.4)) {
			//		buffer[i] = Min;
			//	}
			//}

			//that block of code above (written to handle 16 bit data) is messing up the 8 bit stuff. I'll come back and see what the issues/if I need it once
			//I can process the 16 bit audio
			else {
			buffer[i] = (buffer[i] + buffer[i - timeDelay]*.45);
			}
		}
	
	}

	if (waveform == 0200) {
		/*stereo, dealing with left/right buffer switching
		*/
		for (int i1 = timeDelay; i1 < (bufferSize + 1); (i1 = i1 + 2) ) {
			if (Max  < (buffer[i1] + buffer[i1 - timeDelay]*.4)) {
				buffer[i1] = Max;
			}
			if (Min > (buffer[i1] + buffer[i1 - timeDelay]*.4)) {
				buffer[i1] = Min;

			}
			else {
			buffer[i1] = (buffer[i1] + buffer[i1 - timeDelay]*.4);
			}

		}

		for (int i2 = (timeDelay + 1); i2 < bufferSize; (i2 = i2 + 2) ) {
			if (Max  < (buffer[i2] + buffer[i2 - timeDelay]*.4)) {
				buffer[i2] = Max;
			}
			if (Min > (buffer[i2] + buffer[i2 - timeDelay]*.4)) {
				buffer[i2] = Min;

			}
			else {
			buffer[i2] = (buffer[i2] + buffer[i2 - timeDelay]*.4);
			}

		}

	}
}

