/************************************************************************************************
Rowan Antonuccio
ECE 1410
Project 3 'SUDOKU'


MAIN.cpp
Inputs: n
Outputs: board[9][9]
-------------------------------------------------------------------------------------------------
Begin
Create temp coordinate values and a counter value from input
Print title screen for sudoku solver
Print prompt to enter number of preset grid values
Take input from user
start do while loop
create random values for temp x y and val
set random grid coords to the random vals as long as there are only 81 positive grid values
print the beginning grid before computing
pause

then print the solution grid
or
print error if the puzzle is not solveable
pause
end

**************************************************************************************************/

#include <iostream>
#include "Sudoku.h"
#include <ctime>
#include <cstdlib>
using namespace std;

int main(int argc, char * const argv[]) 
{

	sudoku main;																								//Begin
	int n, tempx, tempy, tempvalue;																				//Create temp coordinate values and a counter value from input
	
	cout << "*-*-*-*-*-*-*-*-*-*-*" << "Welcome to SudokuSolver 2.0" << "*-*-*-*-*-*-*-*-*-*-*" << endl;		//Print title screen for sudoku solver
	cout << "Enter number of squares to prepopulate: ";															//Print prompt to enter number of preset grid values
	cin >> n;																									//Take input from user

	do
	{																											//start do while loop
		tempx =		(rand() % 9) + 1;
		tempy =		(rand() % 9) + 1;
		tempvalue = (rand() % 9) + 1;																			//create random values for temp x y and val
		main.setval(tempx, tempy, tempvalue);
		n--;
	} while (n > 0 && n <= 81);																					//set random grid coords to the random vals as long as there are only 81 positive grid values

	main.print();																								//print the beginning grid before computing
	std::cout << std::endl;
	system("pause");

	if (main.solve()) {																							//if solveable

		std::cout << "Here is the solved puzzle:" << std::endl;
		main.print();																							//then print the solution grid

	}
	else {																										//if not solveable
		std::cout << "This puzzle is not solvable, try again";													//print error message
	}

	std::cout << std::endl;
	system("pause");
	return 0;																									//end
}