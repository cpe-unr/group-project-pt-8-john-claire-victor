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

int UserInterface::getUserSelection(void)
{
	return userSelection;
}

void UserInterface::setUserSelection(int newSel)
{
	userSelection = newSel;
	return;
}

int UserInterface::getUserSelection2(void)
{
	return userSelection2;
}

void UserInterface::setUserSelection2(int newSel2)
{
	userSelection2 = newSel2;
	return;
}

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