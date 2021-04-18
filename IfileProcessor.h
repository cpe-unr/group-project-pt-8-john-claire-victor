/** Claire Burkhardt
* CS202 Final Group Project - 4/17/21
* This file is the interface for all the audio processor files (like echo, noise gate, etc.) and includes the cirtual function processBuffer
*/

//not working right now :(

#ifndef IFILEPROCESSOR_H
#define IFILEPROCESSOR_H


#include <cstdint>
#include <cmath>

class IfileProcessor {
public:
    virtual void processBuffer(unsigned char* buffer, int bufferSize) = 0;
};


#endif //IFILEPROCESSOR_H
