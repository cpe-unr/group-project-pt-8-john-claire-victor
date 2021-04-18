//Created by Claire Burkhardt 3/21/21

#ifndef PROGRAMMING_ASSIGNMENT_NOISEGATE_H
#define PROGRAMMING_ASSIGNMENT_NOISEGATE_H
#include "IfileProcessing.h"

class Noise: public IfileProcessing {
	int percent;
public: 
	Noise(int percent);
	void processBuffer(unsigned char* buffer, int bufferSize) override;
//overriding processbuffer to be a limiter

};

#endif //PROGRAMMING_ASSIGNMENT_NOISEGATE_H
