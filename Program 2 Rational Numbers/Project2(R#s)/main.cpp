/*******************************************************************************************
Rowan Antonuccio
A02184507
Func Title: Main
Summary: Take in input values and prompt user with menu of options. 
Then select option and prompt new fraction entry for math to be completed.
Check for invalid entries and Print result
********************************************************************************************
Int main
	set flag
	Prompt user to enter values for numerator and denominator
	Take input values

	Try block to catch a zero in denominator
	If zero is found, Print error message and exit
	else if denominator is not 0, comtinue
	While loop to create menu
		Print menu options to screen 1 through 5
		intake choice if choice is not 0 and not greater than 4
		if greater than 4 or 0, exit
		Then prompt new numerator and denominator entry
		Try block again to catch for new zero entries
		If denominator is not 0
	Use case statements to compute the users selected input math, or exit
End
*******************************************************************************************/

#include "rational.h"
#include <iostream>
using namespace std;

int main()
{
	int n, d, choice, flag;													//set flag and n, d
	flag = 0;																//initialize flag

	cout << "Enter a numerator: ";											//Prompt user to enter value for numerator
	cin >> n;
	cout << endl << "Enter a denominator: ";								//Prompt user to enter value denominator
	cin >> d;
	cout << endl;


	try
	{																		//Try block to catch a zero in denominator
		if (d == 0)
			flag = 1;
		throw 1;
		cout << "d = " << d << endl;
	}
	catch (int err)
	{
		if (flag == 1)
			cout << "!!CANNOT HAVE 0 IN DENONINATOR!!" << endl;				//Set error message
		system("pause");													//If zero is found, Print error message and exit
	}



	Rational Number(n, d);													//else if denominator is not 0, comtinue
	if (d != 0)
	{
		Number.simp();
		Number.out();
	}

	while (flag != 1)														//While flag is not 1, therefor there is no 0
	{
		cout << "1. Add rationals" << endl;
		cout << "2. Subtract rationals" << endl;
		cout << "3. Multiply rationals" << endl;
		cout << "4. Divide rationals" << endl;
		cout << "5. Exit" << endl;											//Print menu options to screen 1 through 5
		cout << "Type a choice and press enter: ";							//Prompt choice entry
		cin >> choice;														//Input value for choice from user
		if (choice > 0 && choice >= 5)										//intake choice if choice is not 0 and not greater than 4
		{
			cout << "Selected Exit" << endl;
			system("pause");
			break;															//intake choice if choice is not 0 and not greater than 4
		}
		cout << "Enter a numerator: ";										//Prompt user to input new numerator
		cin >> n;															//input new value
		cout << endl << "Enter a denominator: ";							//Prompt user to enter new denominator
		cin >> d;															//input new value
		cout << endl;


		try
		{																	//Try block again to catch for new zero entries
			if (d == 0)
				flag = 1;
			throw 1;
			cout << "d = " << d << endl;
		}
		catch (int err)
		{
			if (flag == 1)
				cout << "!!CANNOT HAVE 0 IN DENONINATOR!!" << endl;			//Set error message
			system("pause");												//If zero is found, Print error message and exit
		}

		if (d != 0)															//if there is no 0 in denominator
		{
			switch (choice)													//Use case statements to compute the users selected input math, or exit
			{

			case 1:															//Case 1 add
				cout << "Selected Add rationals" << endl;
				Number.add(n, d);
				Number.out();
				break;
			case 2:															//Case 2 subtract
				cout << "Selected Subtract rationals" << endl;
				Number.sub(n, d);
				Number.out();
				break;
			case 3:															//Case 3 multiply
				cout << "Selected Multiply rationals" << endl;
				Number.mul(n, d);
				Number.out();
				break;
			case 4:															//Case 4 divide
				cout << "Selected Divide rationals" << endl;
				Number.div(n, d);
				Number.out();
				break;
			case 5:															//Case 5 exit, which is triggered if any value other then 1 through 4 is entered
				cout << "Selected Exit" << endl;
				break;
			}

		}
	}
	return 0;
}																			//end