/**Claire Burkhardt; CS202 Final Group Project - 4/17/21
 * This class is a file processor that overlays a limiter on the audio file
 */

#ifndef LIMITER_H
#define LIMITER_H
#include "IfileProcessing.h"

class Limiter: public IfileProcessing {
public: 
	void processBuffer(unsigned char* buffer, int bufferSize) override;

/** Overrides processbuffer to be a limiter
 */

};

#endif //LIMITER_H
