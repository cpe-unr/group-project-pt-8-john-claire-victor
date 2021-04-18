/**Claire Burkhardt; CS202 Final Group Project - 4/17/21
 * This class is a file processor that overlays a noise gate on the audio file
 */

#ifndef NOISEGATE_H
#define NOISEGATE_H
#include "IfileProcessing.h"

class Noise: public IfileProcessing {
	int percent;
public: 
	Noise(int percent);
	void processBuffer(unsigned char* buffer, int bufferSize) override;
/** Overrides processbuffer to be a limiter
 */
};

#endif //NOISEGATE_H
