/***********************************************************************************
Rowan Antonuccio
MyComplex
Inputs:
Outputs:
------------------------------------------------------------------------------------
Summary:
Creates func for MyComplex and initializes

Pseudo:
set r and i equal to 0
************************************************************************************/

#include "MyComplex.h"
#include <iostream>
using namespace std;

MyComplex::MyComplex()
{
	r = 0;																			//sets r to 0
	i = 0;																			//sets i to 0

}

/***********************************************************************************
MyComplex
Inputs: float rp, ip
Outputs:
------------------------------------------------------------------------------------
Summary:
Creates r and i to use in the math functions
Pseudo:
Set r = rp, set i = ip
************************************************************************************/

MyComplex::MyComplex(float rp, float ip)
{
	r = rp;																			//set r equal to rp
	i = ip;																			//set i equal to ip

}

/***********************************************************************************
printMyComplex
Inputs:
Outputs:cout
------------------------------------------------------------------------------------
Summary:
Prints r "plus" i with "i" added onto the end
Pseudo:
Prints r + i"i" to the screen
************************************************************************************/

void MyComplex::printMyComplex()
{
	cout << r << " + " << i << "i" << endl;											//Prints r + i"i" to the screen

}

/***********************************************************************************
operator +
Inputs:
Outputs:temp
------------------------------------------------------------------------------------
Summary:
Uses temp values to compute addition for r and i
Pseudo:
Uses temp for MyComplex
Set temp r equal to r + param
Set temp i equal to i + param
Return temp to be printed
************************************************************************************/

MyComplex MyComplex::operator + (const MyComplex& param)
{
	MyComplex temp;																	//create temp variable
	temp.r = r + param.r;															//Uses temp values for r to compute math
	temp.i = i + param.i;															//Uses temp values for i to compute math
	return temp;																	//returns temp as answer to be printed

}

/***********************************************************************************
operator -
Inputs:
Outputs:temp
------------------------------------------------------------------------------------
Summary:
Uses temp values to compute subrtaction for r and i
Pseudo:
Uses temp for MyComplex
Set temp r equal to r - param
Set temp i equal to i - param
Return temp to be printed
************************************************************************************/

MyComplex MyComplex::operator - (const MyComplex& param)
{
	MyComplex temp;																	//Uses temp for MyComplex
	temp.r = r - param.r;															//Set temp r equal to r - param
	temp.i = i - param.i;															//Set temp i equal to i - param
	return temp;																	//Return temp to be printed

}

/***********************************************************************************
operator *
Inputs:
Outputs:
------------------------------------------------------------------------------------
Summary:
Uses temp values to compute multiplication for r and i
Pseudo:
Uses temp for MyComplex
Use temp r to multiply r with param r minus i with param i
Use temp r to multiply r with param i plus r with param i
Return temp to be printed
************************************************************************************/

MyComplex MyComplex::operator * (const MyComplex& param)
{
	MyComplex temp;																	//Uses temp for MyComplex
	temp.r = (r * param.r) - (i * param.i);											//Use temp r to multiply r with param r minus i with param i
	
	temp.i = (r * param.i) + (r * param.i);											//Use temp r to multiply r with param i plus r with param i
	
	return temp;																	//Return temp to be printed

}

/***********************************************************************************
operator =
Inputs:
Outputs:
------------------------------------------------------------------------------------
Summary:
Creates the equal function and returns *this
Pseudo:
set r = param.r
set i = param.i
return *this
************************************************************************************/

MyComplex& MyComplex::operator = (const MyComplex& param)
{
	r = param.r;																	//set r = param.r
	i = param.i;																	//set i = param.i
	return *this;																	//uses "this" to return the proper values

}