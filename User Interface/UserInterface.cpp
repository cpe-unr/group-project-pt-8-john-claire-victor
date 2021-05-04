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
	std::cout << "1. Audio Statistics" << std::endl;
	std::cout << "2. Analyze Audio" << std::endl;
	std::cout << "3. Audio Playback" << std::endl;
	std::cout << "4. Export CSV" << std::endl;
	std::cout << "0. EXIT PROGRAM " << std::endl << std::endl; 
	return;
}

 /** 
  * If the user does not select an option between 0 and 4, an error message will be displayed and the user will be asked to make a correct selection.
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

int UserInterface::typeSelection(int userSelection2)
{
	std::cout << "Select an option: ";
	std::cin >> userSelection2;
	std::cout << "" << std::endl;

	while(std::cin.fail() || userSelection > 8)
	{
		system("CLS");
		std::cout << "ERROR: Enter a valid selection from the given choices" << std::endl << std::endl;
		std::cin.clear();
		std::cin.ignore(256,'\n');
		std::cout << "Select an option: ";
		std::cin >> userSelection2;
		std::cout << "" << std::endl;
	}

	return userSelection2;
}