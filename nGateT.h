/*Created by Claire Burkhardt 3/21/21
*/

#ifndef NGATET_H
#define NGATET_H

#include <cstddef>
#include <typeinfo>

class nGateProcessor {
    public:

    template <typename T >

    void processNoise (T* buffer, int bufferSize) {

    /* 
        the distinction between mono and stereo is irrelevant here; we're still gating all the noise (Regardless of which channel) that falls below a 5% threshold
     */
        unsigned char* EightPlace = NULL;
        signed short* SixteenPlace = NULL;

        int percent;
        int minVal;
        int maxVal;
        int zeroVal;
            if ((typeid(buffer).name()) == typeid(EightPlace).name()) {
//           std::cout << "true" << std::endl;
            percent = 5;
            minVal = 128 - 128*percent*.01;
	        maxVal =  128*percent*.01 + 128;
            zeroVal = 128;
//            std::cout << percent << std::endl;
        }

        if ((typeid(buffer).name()) == typeid(SixteenPlace).name()) {   
//            std::cout << "bad" << std::endl;
            percent = 5;
            minVal = -32768*.03;
            maxVal = 32767*.03;
            zeroVal = 0;
     }

        for (int i = 0; i < bufferSize; i++) {
		    if ( (buffer[i] < maxVal) && (buffer[i] > minVal ) ) {
			    buffer[i] = zeroVal;
            }

        }

    }
};


#endif //NGATE_H
