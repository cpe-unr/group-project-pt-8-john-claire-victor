/**Victor & Claire; CS202 Final Group Project - 4/24/21
 * This class is a file processor that normmalizes the audio file
 */
#ifndef CLASS_PROCESSOR_H
#define CLASS_PROCESSOR_H
#include "IfileProcessing.h"

class Normalizer : public IfileProcessing {
private:
	float peakAmplitude;
	float newAmplitude;
	float newMultiplier;
    int Max;
    int Min;
public:
    void processBuffer(unsigned char* buffer, int bufferSize) override;
};

#endif //CLASS_PROCESSOR_H

