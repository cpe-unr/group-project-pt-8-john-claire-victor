//Created by Claire Burkhardt 3/21/21

#include "noiseGate.h"

Noise::Noise(int percent) : percent(percent) {}

void Noise::processBuffer(unsigned char* buffer, int bufferSize) {
	 
	int minVal = 128 - 128*percent*.01;
	int maxVal =  128*percent*.01 + 128;

	for (int i2 = 0; i2 < bufferSize; i2++) {
		if ( (*(buffer + i2) < maxVal) && (*(buffer + i2) > minVal ) ) {
			*(buffer + i2) = 128;
		}
	
	}

//overriding processbuffer
//	for (int i = 0; i < bufferSize; i++) {
//		if (*(buffer + i) > maxPlaceholder) {
//			maxPlaceholder = *(buffer + i);
//		}
//		if (*(buffer + i) < minPlaceholder) {
//			minPlaceholder = *(buffer + i);
//		}
//	}
//finding the largest minimum and negative values

//finding the largest abs value, scaling it down by the given percent
//	minPlaceholder = minPlaceholder + 128;
//	if (maxPlaceholder > minPlaceholder) {
//		maxAbs = maxPlaceholder * percent;
//	}
//	else {
//		maxAbs = minPlaceholder * percent;
//	}

//cycling through buffer again, reducing anything not meeting our standards to zero
//less than the greatest value, greater than our greater value
//138, the line is 118 to 138

}
