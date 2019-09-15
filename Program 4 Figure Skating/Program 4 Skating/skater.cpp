/******************************************************************************
Function:Skater

Inputs:c, s
Outputs:
-------------------------------------------------------------------------------
Summary: Sets the country and the score equal to the input values from the string and float by using temp values.
Then procedes in linked list

-------------------------------------------------------------------------------
Pseudo:
Set country = to c
Set score = to s
Set *next to NULL
******************************************************************************/

#include "skater.h"
#include <iostream>
using namespace std;

Skater::Skater(string c, float s)
{
	country = c;															//Set country = to c
	score = s;																//Set score = to s
	Skater *next = NULL;													//Set *next to NULL
}


/******************************************************************************
Function:getCountry

Inputs:
Outputs:
-------------------------------------------------------------------------------
Summary: Uses the value from country that was entered in Skater in order to be called from the string.


-------------------------------------------------------------------------------
Pseudo:
Return Country value from Skater

******************************************************************************/

string Skater::getCountry()
{
	return country;															//Return Country value from Skater
}

/******************************************************************************
Function:getScore

Inputs:
Outputs:
-------------------------------------------------------------------------------
Summary: Uses the score value from Skater to be called from list.


-------------------------------------------------------------------------------
Pseudo:
Return score value from Skater

******************************************************************************/

float Skater::getScore()
{
	return score;															//Return score value from Skater
}


/******************************************************************************
Function:getNext

Inputs:
Outputs:
-------------------------------------------------------------------------------
Summary:
Uses pointer from Skater to get the next value from list, then returns as next.


-------------------------------------------------------------------------------
Pseudo:
return value for next from list
******************************************************************************/

Skater * Skater::getNext()
{
	return next;															//return value for next from list
}

/******************************************************************************
Function:setNext

Inputs:
Outputs:
-------------------------------------------------------------------------------
Summary:
Uses *p to find the next location in the list, then sets next = p

-------------------------------------------------------------------------------
Pseudo:
Set next = to p from list
******************************************************************************/

void Skater::setNext(Skater *p)
{
	next = p;																//Set next = to p from list
}