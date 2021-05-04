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


int main( int argc, char* argv []) {
	vector <string> audioFileNameVec;
	UserInterface mainuser;
		//WAV_HEADER wavObj;
	int headerSize = sizeof(wav_hdr), filelength = 0;
	int doMore = 1;
		
/** this tells the user to input the audio files they'd like to manage */

	const char* filePath;
	string input;
		if (argc <= 1)
		{
			mainuser.badExecution();
			return 0;
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

			audioFileNameVec.push_back(argv[i]);
		}

//		fmgrObj.readFiles();
/**The file I/O in this program is all commented out and replaced with placeholders because the File I/O, while set up, has a segmentation fault that prevents the program from running. **/
//fmgrObj.printFiles();
		

 /**Next, show the user's options and get their preference **/

	do {	
		mainuser.displayMenu();
		int userSelection;
		userSelection = mainuser.typeSelection();

/** Set up a switch to execute these different options **/

		switch(userSelection) {
	
			case 1: {

/** Case 1 is audio processing. First, allow the user to choose the file they want to use **/

				int userChoosenFile;
				userChoosenFile = mainuser.userChoosingFile(audioFileNameVec);

/**Now, allow the user to pick what type of audio processing they would like **/

				int userProcessingSelection;
				userProcessingSelection = mainuser.chooseAudioProcessing(); 

				switch(userProcessingSelection) {
/**Use this switch to run the audio processing **/

					case 1: {
						echoProcessor *echoprocessor = new echoProcessor;
// 						echoprocessor->processEcho(fmgrObj.getBuffer(), fmgrObj.getBufferSize(), fmgrObj.getNum_Channels());

// the above code is commented out because it can't compile without working File I/O. The logic behind the audio processing itself was tested as a spike and should be sound.
    						delete echoprocessor;
						}
						break;
	
					case 2: {
						nGateProcessor *ngateprocessor = new nGateProcessor;
//						ngateprocessor->processNoise(fmgrObj.getBuffer(), fmgrObj.getBufferSize());

// the above code is commented out because it can't compile without working File I/O. The logic behind the audio processing itself was tested as a spike and should be sound.
    						delete ngateprocessor;
						}
						break;
	
					case 3: {
						normalizerProcessor *normalizerprocessor = new normalizerProcessor;
//						normalizerprocessor->processNormalizer(fmgrObj.getBuffer(), fmgrObj.getBufferSize());

// the above code is commented out because it can't compile without working File I/O. The logic behind the audio processing itself was tested as a spike and should be sound.
						delete normalizerprocessor;
						}
						break;

					case 0:
						exit;
						break;

				}
/** After finishing the technical audio processing, create a new file with the processed audio. First, as the user for a name (and double check that the name isn't a dupe). Then write a new file **/

				std::string newFileName;
				newFileName = mainuser.newFile(audioFileNameVec);
//				fmgrObj.writeFile("newFileName");

//The above code is commented out because it won't compile without working File I/O.

	 			}
				break;
			case 2: {
	
				int userChoosenFile1 = mainuser.userChoosingFile(audioFileNameVec);

				mainuser.unfinishedMetadata();
/** Case 2 is the section of our program that should modify the metadata and then overwrite it. The File I/O for it didn't get set up. **/

				}
				break;
			case 3: {

				std::string newFileName1 = mainuser.newFile(audioFileNameVec);
				mainuser.unfinishedCSV();
/** Case 3 is the section of our program that should export a CSV file with all the information for all the audio files. The File I/O for it didn't get set up. **/
				mainuser.CSVSuccess();
			 	}
				break;
			
			case 0:
				doMore = 0;
				mainuser.exitMessage();
				exit;
				break;
		}

	} while (doMore == 1);
	return 0;
}



