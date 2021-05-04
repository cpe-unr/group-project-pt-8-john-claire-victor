#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdint>
#include <vector>
#include "WavHeader.h"
#include "FileManager.h"
#include "echoT.h"
#include "nGateT.h"
#include "normalizerT.h"
#include "UserInterface.h"


using namespace std;


int main( int argc, char* argv [])
{
		//WAV_HEADER wavObj;
		int headerSize = sizeof(wav_hdr), filelength = 0;
		
/** this tells the user to input the audio files they'd like to manage */

		const char* filePath;
		string input;
		if (argc <= 1)
		{
			cout << "Input wav file name: ";
			cin >> input;
			cin.get();
			filePath = input.c_str();
		}
		else
		{
			filePath = argv[1];
			cout << "Input wav file name: " << filePath << endl;
		}
		FileManager fmgrObj(filePath);
		for(int i = 1 ; i < argc ; i ++)
		{
			fmgrObj.addFileName(argv[i]);
		}
		fmgrObj.readFiles();
		cout << "Finished ReadFiles!Boo" << endl;
//		fmgrObj.printFiles();
		

 /**Next, show the user's options and get their preference **/
	UserInterface mainuser;
	mainuser.displayMenu();
	int userSelection;
	userSelection = mainuser.typeSelection();

/** Now set up a switch to execute these different options **/

	switch(userSelection) // Uncomment functions when ready to be implemented
	{
	
		case 1:
//process audio
			int userProcessingSelection;
			userProcessingSelection = mainuser.chooseAudioProcessing();
//pick your file
			std::cout << filename[0] << std::endl;
		//come back to this!!
	//


				switch(userProcessingSelection) {
					case 1:

					case 2:

					case 3:

					case 0:
						exit;
						break;

				}

 
			break;
		case 2:
//modify metadata
	//		switchuser.displayTypesMenu();
	//		typeSelection();
			break;
		case 3:
//export csv
		 
			break;
		case 4:
			//Processor::exportCSV();
			
		case 0:
			exit;
			break;
		}



	system("PAUSE");
	return 0;
}



/**
const std::string testfile = "yes-8-bit-stereo.wav";
const std::string echofile = "echos.wav";
const std::string limitfile = "limit.wav";
const std::string noisefile = "noise.wav";
int main() {
    // Uncomment these lines when ready.

    Wav wav;

    wav.readFile(testfile);
    echoProcessor *echoprocessor = new echoProcessor;
    echoprocessor->processEcho(wav.getBuffer(), wav.getBufferSize(), wav.getNum_Channels());
    wav.writeFile("1Echos.wav");
    delete echoprocessor;

//    Follow the pattern above to generate the limit and noise files
//    using the filenames provided

    wav.readFile(testfile);
    nGateProcessor *ngateprocessor = new nGateProcessor;
    ngateprocessor->processNoise(wav.getBuffer(), wav.getBufferSize());
    wav.writeFile("1nGate.wav");
    delete ngateprocessor;

    wav.readFile(testfile);
    normalizerProcessor *normalizerprocessor = new normalizerProcessor;
    normalizerprocessor->processNormalizer(wav.getBuffer(), wav.getBufferSize());
    wav.writeFile("1Normalizer.wav");
    delete normalizerprocessor;

    return 0;
**/
