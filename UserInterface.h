/*
  ===================================================================
  Project Name: Semester Project
  Author: Victor A. Percival
  Date: 04/24/21
  Filename: UserInterface.h
  ===================================================================
*/


#ifndef CLASS_USER_INTERFACE_H
#define CLASS_USER_INTERFACE_H

#include <string>
#include <vector>

class UserInterface
{
private:
	/**
	 * These values are what the user's selection is collectd from in the selection functions.
	 */
	int userSelection;
	int userSelection2;
public:
	/**
	 * This is the default constructor and destructor used for creating objects.
	 */
	UserInterface(void);
	~UserInterface(void);
	
	/**
	 * This is the setter and getter for the selection made on the main menu.
	 */
	int getUserSelection(void);
	void setUserSelection(int newSel);

	/**
	 * This is the setter and getter for the selection made on the submenu.
	 */
	int getUserSelection2(void);
	void setUserSelection2(int newSel2);

	/**
	 * The first function prints the menu to the console.
	 * The second function is the logic behind getting the user's input.
	 */
	void displayMenu(void);
	int mainSelection(int userSelection);

	/**
	 * The first function prints the submenu to the console after collecting the user's main menu input.
	 * The second function is the logic behind getting the user's input.
	 */
	void displayTypesMenu(void);
	int typeSelection();


	void menuSelection(void);

	int chooseAudioProcessing();
	int userChoosingFile(std::vector <std::string>  &audioFileNameVec);
	std::string newFile(std::vector <std::string>  &audioFileNameVec);
	
	void badExecution();
	void unfinishedMetadata();
	void unfinishedCSV();
	void CSVSuccess();
	void exitMessage();

	bool keepGoing();
};

#endif //CLASS_USER_INTERFACE_H
