/** Claire Burkhardt
* CS202 Final Group Project - 4/17/21
* This file is the interface for all the audio processor files (like echo, noise gate, etc.) and includes the virtual function processBuffer
*/

//not working right now :(

#ifndef IFILEPROCESSING_H
#define IFILEPROCESSING_H


#include <cstdint>
#include <cmath>

class IfileProcessing {
public:
    virtual void processBuffer(unsigned char* buffer, int bufferSize) = 0;
};


#endif //IFILEPROCESSING_H
