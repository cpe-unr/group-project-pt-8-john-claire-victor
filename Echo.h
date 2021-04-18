/**Claire Burkhardt; CS202 Final Group Project - 4/17/21
 * This class is a file processor that overlays an echo on the audio file
 */

#ifndef ECHO_H
#define ECHO_H
#include "IfileProcessing.h"

class Echo : public IfileProcessing {
	int timeDelay;
public: 
	Echo(int timeDelay);
	void processBuffer(unsigned char* buffer, int bufferSize) override;
/**overrides processbuffer to be an echoer
*/
};

#endif //ECHO_H
