#include <iostream>
#include "Normalizer.h"

void Normalizer::processBuffer(unsigned char* buffer, int bufferSize) {
//will add getwaveform  & getdatasize as passed into the function above when necessary

    short waveform = 0100;
    //waveform == 0100 (actually 0001) -> mono; == 0200 (actually 0001) -> stereo

    short datasize = 0001;
    // if it == 0001 -> 8-bit? ; and 0010 -> 16 bit?

    if (datasize == 0001) {
        Max = 255;
        Min = 0;
        
        peakAmplitude = 0;
    }
//    if (datasize == 0010) {
    //or whatever it is for 16 bit
  //      Max = 32768;
    //    Min = -32767;
      //  peakAmplitude = 0;
  //  }


   	for(int idx = 0; idx < bufferSize; idx++) {
    //   std::cout << buffer[idx] << std::endl;
    	
        //peakAmplitude = std::max(peakAmplitude, std::fabs(buffer[idx]));
        //this ^^ wouldn't run on my complier, so I redid the find max part

        if (waveform == 0100) {
            if ((buffer[idx] < 256) && (buffer[idx] > 0) ) {
                if (peakAmplitude < ( std::fabs (buffer[idx] - 128) ) )  {
                peakAmplitude = std::fabs(buffer[idx] - 128);
                std::cout << peakAmplitude << std::endl;
                std::cout << buffer[idx] << std::endl;
                }
            }
        }

    //    if (waveform == 0200) {
     //       if (peakAmplitude < std::fabs(buffer[idx]) ) {
     //           peakAmplitude = std::fabs(buffer[idx]);
        //    }
       // }
    }
    newMultiplier = (128 / peakAmplitude + .12);
    std::cout << newMultiplier << std::endl;
    for (int idx1 = 0; idx1 < bufferSize; ++idx1) {
        buffer[idx1] *= newMultiplier;
    }  
}
