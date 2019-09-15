/******************************************************************************
Function:Main

Inputs:c, s, n
Outputs: Printlist
-------------------------------------------------------------------------------
Summary:Create values for c, s, and n
Creates a menu for the user, and then uses case statements and n to sycle through cases


-------------------------------------------------------------------------------
Pseudo:
Create int n, and loop
Set loop = 1 to keep track of when to exit program
String c, and float s for score and country
Add list

While the loop is equal to 1
Print menu and ask for selection
Take input n for selection
Switch n
Case 1, for entering new Nation
Take input for name
Take input for score
then adds to list
then breaks
Proceeds to loop
Case 2
Prints list from List
Proceeds to loop
Case 0
Exits by setting loop = 0
Default, keeps track of improper inputs
End
******************************************************************************/

#include "list.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, loop = 1;																//Create int n, and loop
	string c;																		//Set loop = 1 to keep track of when to exit program
	float s;																		//String c, and float s for score and country
	List list;																		//Add list

	while(loop == 1)																//While the loop is equal to 1
	{
	cout << "*** MENU ***" << endl;													//Print menu and ask for selection
	cout << "1. Enter a new team and score" << endl;
	cout << "2. Print rankings" << endl;
	cout << "0. Exit" << endl;
	cout << "Selection: ";															//Take input n for selection
	cin >> n;
	cout << endl;

		switch (n)																	//Switch n
			{
			case 1:																	//Case 1, for entering new Nation
				cin.ignore();
				cout << "Enter Nation: ";
				getline(cin, c);													//Take input for name
				cout << endl << "Enter a Score: ";
				cin >> s;															//Take input for score
				cout << endl;
				list.addNode(c, s);													//add to list
				break;

			case 2:																	//Case to print
				list.printList();													//Prints list
				break;

			case 0:																	//Case 0 for exit
				loop = 0;															//Sets loop = 0 causing exit
				break;

			default:																//Use default to avoid unwanted values
				cout << "Invalid selection" << endl;
				break;

			}
	}
	return 0;																		//End
}