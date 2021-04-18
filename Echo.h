//Created by Claire Burkhardt 3/21/21

#ifndef PROGRAMMING_ASSIGNMENT_ECHO_H
#define PROGRAMMING_ASSIGNMENT_ECHO_H
#include "Processor.h"

class Echo: public ifileProcessor {
	int timeDelay;
public: 
	Echo(int timeDelay);
	void processBuffer(unsigned char* buffer, int bufferSize) override;
//overriding processbuffer to be a limiter

};

#endif //PROGRAMMING_ASSIGNMENT_ECHO_H
