#ifndef NORMALIZERT_H
#define NORMALIZERT_H

#include <iostream>
#include <typeinfo>
#include <cmath>
class normalizerProcessor {
    public:
     template <typename T >

    void processNormalizer (T* buffer, int bufferSize) {
/* Dr. Lancaster said in class that echo shouldn't segment out the stereo audio channels, so there's no audio processing difference for mono/stereo in this function */

        unsigned char* EightPlace = NULL;
        signed short* SixteenPlace = NULL;

        int Max;
        int Min;
        int zeroVal;
        float absMaxAmplitude;
        float newMultiplier;
//        std::cout << "in normalizer  buffer " << typeid(buffer).name() << " eightPlace " << typeid(SixteenPlace).name() << std::endl;

        if ((typeid(buffer).name()) == typeid(EightPlace).name()) {
//            std::cout << "YAY in eightplacenormalizer type id" << std::endl;
            Max = 256;
            Min = 0;
            zeroVal = 128;
            absMaxAmplitude = 128;
        }

        if ((typeid(buffer).name()) == typeid(SixteenPlace).name()) {           
            Max = 32768;
            Min = -32768;
            zeroVal = 0;
            absMaxAmplitude = 32768;
        }
        int peakAmplitude = 0;

   	for(int idx = 0; idx < bufferSize; idx++) {
    //    std::cout << Max << std::endl;
        if ((buffer[idx] < Max) && (buffer[idx] > Min) ) {
    
            if (peakAmplitude < ( std::fabs ( std::fabs(buffer[idx]) - zeroVal) ) )  {
                peakAmplitude = std::fabs(std::fabs(buffer[idx]) - zeroVal);
    //            std::cout << peakAmplitude << std::endl;
    //            std::cout << buffer[idx] << std::endl;
            }
        }
    }


    newMultiplier = (absMaxAmplitude / peakAmplitude);
//    if (newMultiplier != 1) {
//	newMultiplier = newMultiplier*.87;
//    }
//come back to this!

//    std::cout << peakAmplitude << " multiplier " << newMultiplier << std::endl;
    for (int i1 = 0; i1 < bufferSize; ++i1) {

        buffer[i1] *= newMultiplier;
    }  
     }
};

#endif //NORMALIZERT_H
