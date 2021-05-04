/*
  ===================================================================
  Project Name: Semester Project
  Author: Victor A. Percival
  Date: 04/24/21
  Filename: UserInterface.cpp
  ===================================================================
*/

#include <iostream>
#include <string>
#include "UserInterface.h"


UserInterface::UserInterface(void)
{
}

UserInterface::~UserInterface(void)
{
}

 /**
  * This is the getter for first main menu user selection.
  */
int UserInterface::getUserSelection(void)
{
	return userSelection;
}

 /**
  * This is the setter for first main menu user selection.
  */
void UserInterface::setUserSelection(int newSel)
{
	userSelection = newSel;
	return;
}

 /**
  * This is the getter that will be used for the proceeding menu.
  */
int UserInterface::getUserSelection2(void)
{
	return userSelection2;
}

 /**
  * This is the setter that will be used for the proceeding menu.
  */
void UserInterface::setUserSelection2(int newSel2)
{
	userSelection2 = newSel2;
	return;
}


 /**
  * This is the main menu that is displayed to the user upon running the program.
  * The first two selections will display another menu that asks the user for an audio format.
  */
void UserInterface::displayMenu(void)
{
	std::cout << "***  AUDIO MENU  ***" << std::endl;
	std::cout << "====================" << std::endl;
	std::cout << "1. Process Audio" << std::endl;
	std::cout << "2. Modify Metadata" << std::endl;
	std::cout << "3. Export CSV" << std::endl;
	std::cout << "0. EXIT PROGRAM " << std::endl << std::endl; 
	return;
}

 /** 
  * If the user does not select an option between 0 and 3, an error message will be displayed and the user will be asked to make a correct selection.
  * This will loop until the user makes a correct selection.
  */

int UserInterface::mainSelection(int userSelection)
{
	std::cout << "Select an option: ";
	std::cin >> userSelection;
	std::cout << "" << std::endl;

	while(std::cin.fail() || userSelection > 4)
	{
		system("CLS");
		std::cout << "ERROR: Enter a valid selection from the given choices" << std::endl << std::endl;
		displayMenu();
		std::cin.clear();
		std::cin.ignore(256,'\n');
		std::cout << "Select an option: ";
		std::cin >> userSelection;
		std::cout << "" << std::endl;
	}

	return userSelection;
}

 /**
  * This is the displayed menu for a secondary selection unpon selecting one of the first two choices.
  * Depending on which of the two selections the user made, each of these will perform that analysis for the specified audio type.
  * The first two selections will display another menu that asks the user for an audio format.
  */

void UserInterface::displayTypesMenu(void)
{
	system("CLS");
	std::cout << "*** AUDIO TYPES ***" << std::endl;
	std::cout << "===================" << std::endl;
	std::cout << "1. Mono, 8 bit" << std::endl;
	std::cout << "2. Mono, 16 bit" << std::endl;
	std::cout << "3. Mono, 24 bit" << std::endl;
	std::cout << "4. Mono, 32 bit" << std::endl;
	std::cout << "5. Stereo, 8 bit" << std::endl;
	std::cout << "6. Stereo, 16 bit" << std::endl;
	std::cout << "7. Stereo, 24 bit" << std::endl;
	std::cout << "8. Stereo, 32 bit" << std::endl;
	std::cout << "0. EXIT PROGRAM " << std::endl << std::endl;
	return;
}

/** 
  * This is similar to the logic for ensuring the user makes a valid selection in the main menu.
  * If the user does not select an option between 0 and 8, an error message will be displayed and the user will be asked to make a correct selection.
  * This will loop until the user makes a correct selection.
  */

int UserInterface::typeSelection()
{
	int userSelectionI;
	std::cout << "===================" << std::endl;
	std::cout << "Select an option: ";
	std::cin >> userSelectionI;
	std::cout << "" << std::endl;

	while(std::cin.fail() || userSelectionI > 3)
	{
		system("CLS");
		std::cout << "ERROR: Enter a valid selection from the given choices" << std::endl << std::endl;
		std::cin.clear();
		std::cin.ignore(256,'\n');
		std::cout << "Select an option: ";
		std::cin >> userSelectionI;
		std::cout << "" << std::endl;
	}

	return userSelectionI;
}


int UserInterface::chooseAudioProcessing() {
	std::cout << "*** AUDIO Processing ***" << std::endl;
	std::cout << "===================" << std::endl;
	std::cout << "1. Echo" << std::endl;
	std::cout << "2. Noise Gate" << std::endl;
	std::cout << "3. Normalizer" << std::endl;
	std::cout << "0. EXIT" << std::endl;
	
	int userSelection3 = UserInterface::typeSelection();

	return userSelection3;


}

int UserInterface::userChoosingFile(std::vector <std::string>  &audioFileNameVec) {

	int num = 1;
	std::cout << "*** SELECT a File To Work With ***"<< std::endl;
	std::cout << "===================" << std::endl;

	for (int i = 0; i < audioFileNameVec.size(); i++) {
		std::cout << "File " << num << ". " << audioFileNameVec[i] << std::endl;
		num ++;
}

	int userSelection4 = UserInterface::typeSelection();
	return userSelection4;
}

void UserInterface::badExecution() {
	std::cout << "Proper format: ./ptest audio_file.wav [n times]" << std::endl;
	std::cout << "Ending program. Please use the above proper format." << std::endl;
}


std::string UserInterface::newFile(std::vector <std::string>  &audioFileNameVec) {
	int placeholder = 1;
	bool sameName = 1;
	std::string fileName;
	
	do {
		sameName = 1;
		std::cout << "Select a file name for your new file: ";
		std::cin >> fileName;
		std::cout << "" << std::endl;
	
		for (int i = 0; i < audioFileNameVec.size(); i++) {
			if (audioFileNameVec[i] == fileName) {
				sameName = 0;

			}
		}
		if (sameName == 1 ) {

			placeholder = 0;
		}
	} while (placeholder == 1);
	
	return fileName;

}

void UserInterface::unfinishedMetadata() {
	std::cout << "This is the part of our program that should change and overrwrite the metadata of a chosen file. The File I/O for it wasn't finished." << std::endl;
}

void UserInterface::unfinishedCSV() {
	std::cout << "This is the part of our program that should export a CSV file with all the information for all the audio files. The File I/O for it wasn't finished." << std::endl;
}

void UserInterface::CSVSuccess() {
	std::cout << "Success! Your audio files have been exported to a CSV" << std::endl;
}

void UserInterface::exitMessage() {
	std::cout << "Thank you for using our program to process your files. Exiting program." << std::endl;
}


//I deleted a ton of code for functions UserInterface and typeSelection and a few others that were built in the main file of the user interface but didn't work when refactored and had some global variables (I think) that they were predicated on. See the folder 'User Interface' for Victor's original version of this User Interface. I modified userSelection and wrote chooseAudioProcessing, userChoosingFile, badExecution, newFile, unfinishedMetadata/CSV, and exitMessage --Claire
