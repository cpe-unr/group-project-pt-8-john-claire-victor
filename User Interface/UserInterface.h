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

class UserInterface //: public: Processor
{
private:
	int userSelection;
	int userSelection2;
public:
	UserInterface(void);
	~UserInterface(void);

	int getUserSelection(void);
	void setUserSelection(int newSel);

	int getUserSelection2(void);
	void setUserSelection2(int newSel2);

	void displayMenu(void);
	int mainSelection(int userSelection);

	void displayTypesMenu(void);
	int typeSelection(int userSelection2);
};

#endif //CLASS_USER_INTERFACE_H