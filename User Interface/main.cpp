/*
  ===================================================================
  Project Name: Semester Project
  Author: Victor A. Percival
  Date: 04/24/21
  Filename: main.cpp
  ===================================================================
*/

#include <iostream>
#include "UserInterface.h"

void menuSelection(void);
void typeSelection(void);

int selection;
int selection2;

void menuSelection(void)
{
	UserInterface switchuser;

	switch(selection) // Uncomment functions when ready to be implemented
	{
		case 1:
			switchuser.displayTypesMenu();
			typeSelection();
			break;
		case 2:
			switchuser.displayTypesMenu();
			typeSelection();
			break;
		case 3:
			//Processor::playbackAudio();
			std::cout << "Placeholder 3" << std::endl;
			break;
		case 4:
			//Processor::exportCSV();
			std::cout << "Placeholder 4" << std::endl;
		case 0:
			exit;
			break;
	}
}

void typeSelection(void)
{
	UserInterface typeuser;

	selection2 = typeuser.typeSelection(0);

	switch(selection2)
	{
		case 1:
			std::cout << "Placeholder 1" << std::endl;
			break;
		case 2:
			std::cout << "Placeholder 2" << std::endl;
			break;
		case 3:
			std::cout << "Placeholder 3" << std::endl;
			break;
		case 4:
			std::cout << "Placeholder 4" << std::endl;
			break;
		case 5:
			std::cout << "Placeholder 5" << std::endl;
			break;
		case 6:
			std::cout << "Placeholder 6" << std::endl;
			break;
		case 7:
			std::cout << "Placeholder 7" << std::endl;
			break;
		case 8:
			std::cout << "Placeholder 8" << std::endl;
			break;
		case 0:
			exit;
			break;
	}
}

int main(void)
{
	UserInterface mainuser;
	mainuser.displayMenu();
	selection = mainuser.mainSelection(0);

	menuSelection();

	system("PAUSE");
	return 0;
}

/*
 The way that that the user input from the menus will be only be able to be used in the main
 function, as what was required per the assignment instructions, is that an object
 should be created for the Processor class, and that object will be used to call the
 functions, such as analyze and display audio information.

 Example:

 #include "Processor.h"

 void typeSelection(void)
 {
	Processor processorobj;
	selection2 = typeuser.typeSelection(0);

	switch(selection2)
	{
		case 1:
			processorobj.displayInfo();
			break;
	   // And so on...
	}
  }

  This keeps these needed functions restricted within the main.cpp source file, thus 
  meeting the prescribed instructions given in the guidelines PDF.
*/