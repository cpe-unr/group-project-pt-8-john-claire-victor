/*
  ===================================================================
  Project Name: Semester Project
  Author: Victor A. Percival; Claire Burkhardt
  Date: 04/24/21; 5/3/21
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


/**
*Claire
*Has the user choose what type of audio processing they would like to do
*@return the integer representative of the respective audio processing choice (1 - echo, 2 - noise gate, 3 - normalizeR)
*/
	int chooseAudioProcessing();
/**
*Claire
*Displays a list of files that have been loaded into the program and instructs the user to choose which of those files they would like to modify/process
*@param the vector list of filenames read in when the user runs the executable and first loads audio files
*@return the integer representative of the respective file
*/
	int userChoosingFile(std::vector <std::string>  &audioFileNameVec);

/**
*Claire
*Has the user select a file name to save their new file as; ensures this new file name is not a duplicate
*@param the vector list of filenames read in to the program when the user runs the executable
*@return the string for the non-duplicate new file name
*/

	std::string newFile(std::vector <std::string>  &audioFileNameVec);
/**
*Claire
*Error message that appears when the user does not input any audio files when they first run the program. Warns the user, provides proper syntax, & ends the program
*/

	void badExecution();
/**
*Claire
*A placeholder for where the File I/O for the metadata would be in the program.
*/
	void unfinishedMetadata();
/**
*Claire
*A placeholder for where the File I/O for the CSV writer would be in the program.
*/
	void unfinishedCSV();
/**
*Claire
*A message telling the user that their CSV file has sucessfully been made and exportered
*/
	void CSVSuccess();
/**
*Claire
*A message to the user informing them that the program is ending.
*/	
	void exitMessage();

};

#endif //CLASS_USER_INTERFACE_H
