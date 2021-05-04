semesterProjectExecutable: driver.cpp WavHeader.h FileManager.h echoT.h nGateT.h normalizerT.h UserInterface.o FileManager.o EightBit.o SixteenBit.o SoundFile.o
	g++ -std=c++11 driver.cpp UserInterface.o FileManager.o EightBit.o SixteenBit.o SoundFile.o -o ptest

FileManager.o: FileManager.cpp FileManager.h WavHeader.h FileInterface.h
	g++ -c -std=c++11 FileManager.cpp

EightBit.o: EightBit.cpp SoundFile.h WavHeader.h FileInterface.h
	g++ -c -std=c++11 EightBit.cpp

SixteenBit.o: SixteenBit.cpp SoundFile.h WavHeader.h FileInterface.h
	g++ -c -std=c++11 SixteenBit.cpp

SoundFile.o: SoundFile.cpp SoundFile.h WavHeader.h FileInterface.h
	g++ -c -std=c++11 SoundFile.cpp

UserInterface.o: UserInterface.cpp UserInterface.h
	g++ -c -std=c++11 UserInterface.cpp

audioprocessorlibrary.a: audioprocessorlibrary.o
	ar rvs audioprocessorlibrary.a audioprocessorlibrary.o

audioprocessorlibrary.o: nGateT.h normalizerT.h echoT.h blank.cpp
	g++ -c -std=c++11 blank.cpp -o audioprocessorlibrary.o


clean:
	rm *.o ptest

