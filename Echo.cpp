//Created by Claire Burkhardt 3/21/21

#include "Echo.h"

Echo::Echo(int timeDelay) : timeDelay(timeDelay) {}

void Echo::processBuffer(unsigned char* buffer, int bufferSize) {
//overriding processbuffer

	for (int i = timeDelay; i < bufferSize; i ++ ) {
		if (255  < (buffer[i] + buffer[i - timeDelay]*.4)) {
			buffer[i] = 255;
		}
		else {
		buffer[i] = (buffer[i] + buffer[i - timeDelay]*.4);
		}

//	for (int i = bufferSize; i > timeDelay; i--) {
//		*(buffer + i) = (*(buffer + i) + *(buffer + i - timeDelay)*.75);			

//		if (*(buffer + i) > 255) {
//			*(buffer + i) = 255;
//		}
//		if (*(buffer+i) < 0) {
//			*(buffer+i) = 0;
//		}
	}

}

