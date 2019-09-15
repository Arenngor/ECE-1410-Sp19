/******************************************************************************
Function:Skater.h

Inputs:
Outputs:
-------------------------------------------------------------------------------
Summary: Creates and defines Class: Skater and all of the functions within it
-------------------------------------------------------------------------------
Pseudo:
Set ifndef and define
Class Skater
Create string and float in order to keep names and scores
Pointers for linked list to move into next

Add the string and the float to the private section
Add pointer to next into private
Set endif

******************************************************************************/

#ifndef SKATER_H
#define SKATER_H
#include <string>

using namespace std;

class Skater{
public:
	Skater(string c, float s);
	string getCountry();
	float getScore();
	Skater *getNext();
	void setNext(Skater *p);
private:
	string country;
	float score;
	Skater *next;
	};
#endif
