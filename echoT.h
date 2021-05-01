/*Created by Claire Burkhardt 4/18/21
*/

#ifndef ECHOT_H
#define ECHOT_H


#include <cstdint>
#include <typeinfo>
#include <iostream>

class echoProcessor {

    public:
    
    template <typename T >

    void processEcho (T* buffer, int bufferSize, uint16_t numOfChan) {

        unsigned char* EightPlace = NULL;
        signed short* SixteenPlace = NULL;

        
        int Max;
        int Min;
        int timeDelay;
	int zeroVal;
        if ((typeid(buffer).name()) == typeid(EightPlace).name()) {
            Max = 255;
            Min = 0;
            timeDelay = 30000;
	    zeroVal = 128;
        }

        if ((typeid(buffer).name()) == typeid(SixteenPlace).name()) {               
            Max = 32768;
            Min = -32767;
            timeDelay = 30000;
	    zeroVal = 0;
      
            }

  ///      if (numOfChan == 1) {
//            std::cout << "numchan = 1" << std::endl;

            for (int i = timeDelay; i < bufferSize; i++) {


		if (Max  < ( ( (buffer[i] - zeroVal) + (buffer[i - timeDelay] - zeroVal)*.5 ) + zeroVal) ) {
//		    std::cout << 1 << std::endl;
		    buffer[i] = Max;
                }
                else if (Min > ( ( (buffer[i] - zeroVal) + (buffer[i - timeDelay] - zeroVal)*.5 ) + zeroVal) )  {
                    buffer[i] = Min;
//		std::cout << 2 << std::endl;
                }
                else {
                    buffer[i] = ( ( (buffer[i] - zeroVal) + (buffer[i - timeDelay] - zeroVal)*.5 ) + zeroVal);
//		    std::cout << 3 << std::endl;
                }
            }

 	}
};

#endif //ECHOT_H
