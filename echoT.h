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
//            std::cout << "finished numchan" << std::endl;
  //      }

/*
        if (numOfChan == 2) {
            std::cout << "numchan = 2" << std::endl;
         
            for (int i = timeDelay; i < (bufferSize + 1); i = i + 2) {

		if (Max  < (buffer[i] + buffer[i - timeDelay]*.45) ) {
		    	    buffer[i] = Max;
                }
                else if (Min > (buffer[i] + buffer[i - timeDelay]*.45) ) {
                    buffer[i] = Min;
                }
                else {
                    buffer[i] = (buffer[i] + buffer[i - timeDelay]*.45);
                }
	


		if (Max  < (buffer[i+1] + buffer[i +1 - timeDelay]*.45) ) {
		    	    buffer[i+1] = Max;
                }
                else if (Min > (buffer[i] + buffer[i - timeDelay]*.45) ) {
                    buffer[i] = Min;
                }
                else {
                    buffer[i] = (buffer[i] + buffer[i - timeDelay]*.45);
                    buffer[i+1] = (buffer[i+1] + buffer[i + 1 - timeDelay]*.45);
                }



            }

*/

        /* 
            T* channelOne = NULL;
            T* channelTwo = NULL;
            int channelSize = 0;

            for (int i1 = 0; i1 < (bufferSize + 1); i1 = i1 + 2) {

                channelOne = new T[buffer[i1]];
                channelTwo = new T[buffer[i1 + 1]];
                channelSize++;
//                std::cout << "hi" <<std::endl;
//
//                channelOne[channelBufferSize] = buffer[i1];
//                channelTwo[channelBufferSize] = buffer[i1 + 1];
//               std::cout << buffer[i1] << channelOne[channelBufferSize] << channelTwo[channelBufferSize] << std::endl;
//                channelBufferSize++;
                
            }
            std::cout << "here " << channelSize <<std::endl;
            int ticker = 0;
            for (int i2 = timeDelay; i2 < 31440; i2++) {

		        if (Max  < (channelOne[i2] + channelOne[i2 - timeDelay]*.45) ) {
                    std::cout << "option1" <<std::endl;
		    	    channelOne[i2] = Max;
                }
                else if (Min > (channelOne[i2] + channelOne[i2 - timeDelay]*.45) ) {
                    channelOne[i2] = Min;
                    std::cout << "option2" <<std::endl;
                }
                else {
                    std::cout << "channel " << channelOne[i2] << " delay " << channelOne[i2 - timeDelay] << std::endl;
                    channelOne[i2] = (channelOne[i2] + channelOne[i2 - timeDelay]*.45);
                    std::cout << "option3" << ticker <<std::endl;
                    ticker ++;

                }

            }
            std::cout << "past" <<std::endl;
            for (int i3 = 0; i3 < channelSize; i3++) {

		        if (Max  < (channelTwo[i3] + channelTwo[i3 - timeDelay]*.45) ) {
		    	    channelTwo[i3] = Max;
                }
                else if (Min > (channelTwo[i3] + channelTwo[i3 - timeDelay]*.45) ) {
                    channelTwo[i3] = Min;
                }
                else {
                    channelTwo[i3] = (channelTwo[i3] + channelTwo[i3 - timeDelay]*.45);
                }

            }
        
        */
//        }

 	}
};

#endif //ECHOT_H
