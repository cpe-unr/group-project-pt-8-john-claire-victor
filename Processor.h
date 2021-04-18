/** Claire Burkhardt
* CS202 Final Group Project - 4/17/21
* This file is the base class for all the processor functions to be derived from w/ the abstract function processBuffer
*/

#ifndef PROCESSOR_H
#define PROCESSOR_H
//#include "IfileProcessor.h"

#include <cstdint>
#include <cmath>

class Processor {
public:
    virtual void processBuffer(unsigned char* buffer, int bufferSize) = 0;
};



#endif //PROCESSOR_H
