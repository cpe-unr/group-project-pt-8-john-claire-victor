//Created by Claire Burkhardt 3/21/21

#include "Limiter.h"

void Limiter::processBuffer(unsigned char* buffer, int bufferSize) {
//overriding processbuffer
	for (int i = 0; i < bufferSize; i++) {
		if (buffer[i] > 229) {
			buffer[i] = 229;
		}
		if (buffer[i] < 26) {
			buffer[i] = 26;
		}
	}

}

