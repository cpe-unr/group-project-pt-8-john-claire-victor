//Created by Claire Burkhardt 3/21/21

#ifndef PROGRAMMING_ASSIGNMENT_LIMITER_H
#define PROGRAMMING_ASSIGNMENT_LIMITER_H
#include "Processor.h"
//#include "IfileProcessor.h"

class Limiter: public Processor {
public: 
	void processBuffer(unsigned char* buffer, int bufferSize) override;
//overriding processbuffer to be a limiter

};

#endif //PROGRAMMING_ASSIGNMENT_LIMITER_H
