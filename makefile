ptest: newMain.cpp WavHeader.h FileManager.o EightBit.o SixteenBit.o SoundFile.o
	g++ -std=c++11 newMain.cpp FileManager.o EightBit.o SixteenBit.o SoundFile.o -o ptest

FileManager.o: FileManager.cpp FileManager.h WavHeader.h FileInterface.h
	g++ -c -std=c++11 FileManager.cpp

EightBit.o: EightBit.cpp SoundFile.h WavHeader.h FileInterface.h
	g++ -c -std=c++11 EightBit.cpp

SixteenBit.o: SixteenBit.cpp SoundFile.h WavHeader.h FileInterface.h
	g++ -c -std=c++11 SixteenBit.cpp

SoundFile.o: SoundFile.cpp SoundFile.h WavHeader.h FileInterface.h
	g++ -c -std=c++11 SoundFile.cpp


clean:
	rm *.o ptest
