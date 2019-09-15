/******************************************************************************
Function:addNode

Inputs:Country, Score
Outputs:
-------------------------------------------------------------------------------
Summary: uses current and previous to add nodes into the List and then move the current node to the next node in order to keep a valid location
-------------------------------------------------------------------------------
Pseudo:
Pointers for *p, *cur, *prev
set p equal to NEw skater value within list, then move through list to find next location. If cur isnt NULL and it is in the proper location, then get score. Then set prev = cur
setNext to cur
If prev is equal to NULL
set head = p
Else, use setnext to move in list

******************************************************************************/

#include "list.h"
#include "skater.h"
#include <iostream>
using namespace std;

void List::addNode(string country, float score)
{
	Skater *p, *cur, *prev;												//Pointers for *p, *cur, *prev

	p = new Skater(country, score);										//set p equal to NEw skater value within list, then move through list to find next location.
	for (cur = head, prev = NULL; 
		cur != NULL && p->getScore() < cur->getScore();					//If cur isnt NULL and it is in the proper location, then get score. Then set prev = cur
		prev = cur, cur = cur->getNext());

	p->setNext(cur);
	if (prev == NULL)													//If prev is equal to NULL
	{ 
		head = p;														//set head = p
	}
	else
	{ 
		prev->setNext(p);												//Else, use setnext to move in list
	}

}


/******************************************************************************
Function: printList

Inputs:
Outputs: Country and score
-------------------------------------------------------------------------------
Summary:
Set cur = head, and then print a title for case statement. THen while cur isnt NULL, print the country and scores for all user entries


-------------------------------------------------------------------------------
Pseudo:

******************************************************************************/

void List::printList()
{
	Skater *cur;
	cur = head;																		//set cur equal to head

	cout << "*** RANKINGS ***" << endl;												//Print title for menu
	while (cur != NULL)																//While Cur is not equal to NULL
	{
		cout << cur->getCountry() << "\t" << cur->getScore() << endl;				//Print all user entries of countries and scores from List
		cur = cur->getNext();
	}

}

/******************************************************************************
Function:List

Inputs:
Outputs:
-------------------------------------------------------------------------------
Summary:Creates the list and sets the head to NULL to begin


-------------------------------------------------------------------------------
Pseudo:
set head = to NULL
******************************************************************************/

List::List()
{
	head = NULL;																	//set head = to NULL
}

/******************************************************************************
Function:~List

Inputs:
Outputs:
-------------------------------------------------------------------------------
Summary:
Defines the appropriate way to move through the list

-------------------------------------------------------------------------------
Pseudo:
Check the pointers from Skater
Set prev equal to head
And then set cur equal to head->getNext to find proper location in list
While Cur is not NULL
Remove the prev value and set cur into its location, then set cur to getNext
******************************************************************************/

List::~List()
{
	Skater *cur, *prev;															//Check the pointers from Skater
	prev = head;																//Set prev equal to head
	cur = head->getNext();														//And then set cur equal to head->getNext to find proper location in list
	while (cur != NULL)															//While Cur is not NULL
	{
		delete prev;															//Remove the prev value and set cur into its location, then set cur to getNext
		prev = cur;
		cur = cur->getNext();
	}
}