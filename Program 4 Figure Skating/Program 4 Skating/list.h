/******************************************************************************
Function:List.h

Inputs:
Outputs:
-------------------------------------------------------------------------------
Summary: creates class for list, and then adds public and private functions to it

-------------------------------------------------------------------------------
Pseudo:
Class list

Add list()
Void addNode for adding locations in the List
Print list to print

Add the head to Private
******************************************************************************/

#ifndef LIST_H														//Set ifndef and define
#define LIST_H
#include "skater.h"
#include <string>
using namespace std;

class List															//Add list()
{
public:																//Create public
	List();															//Add list()
	void addNode(string country, float score);						//addNode Function
	void printList();												//Print list function to display results
	~List();

private:
	Skater *head;													//add the head to private class
};
#endif																//set endif

