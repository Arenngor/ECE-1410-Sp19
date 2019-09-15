/************************************************************************************************
Rowan Antonuccio
ECE 1410
Project 3 'SUDOKU'


Sudoku.h
Inputs:
Outputs:
-------------------------------------------------------------------------------------------------
Define and ifndef for SUDOKU_H

Create class sudoku
Creates a 9x9 grid for the puzzleboard
debug to check for proper grid placement
parameters for the trycoordinate function
Recursion to solve the current box
Verifies that solution is correct
Print

function to place values
functionm to get values
Solving function which will use bool to determine if solveable or not
End
**************************************************************************************************/


#ifndef SUDOKU_H
#define SUDOKU_H

class sudoku 
{
private:
	short int board[9][9];																		//Creates a 9x9 grid for the puzzleboard
	bool debug;																					//debug to check for proper grid placement
	void trycoords(int x_cord, int y_cord);														//parameters for the trycoordinate function
	bool solve(int x_cord, int y_cord);															//Recursion to solve the current box
	bool verify(int x_cord, int y_cord);														//Verifies that solution is correct

public:
	sudoku();																					//Constructor
	void print();																				//Print function
	void setval(int x_cord, int y_cord, int value);												//Function to place a new board value
	int getBoardValue(int x_cord, int y_cord);													//Gets new value from board
	bool solve();																				//Solves the puzzle and will return true
};

#endif
