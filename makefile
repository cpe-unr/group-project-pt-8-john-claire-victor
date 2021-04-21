audioprocessor: main.cpp wav.o limiter.o echo.o noiseGate.o
	g++ -std=c++11 main.cpp Wav.o Limiter.o Echo.o noiseGate.o -o audioprocessor

wav.o: Wav.cpp Wav.h WaveHeader.h
	g++ -c -std=c++11 Wav.cpp

limiter.o: Limiter.cpp Limiter.h IfileProcessing.h
	g++ -c -std=c++11 Limiter.cpp

echo.o: Echo.cpp Echo.h IfileProcessing.h
	g++ -c -std=c++11 Echo.cpp

noiseGate.o: noiseGate.cpp noiseGate.h IfileProcessing.h
	g++ -c -std=c++11 noiseGate.cpp

clean:
	rm *.o audioprocessor