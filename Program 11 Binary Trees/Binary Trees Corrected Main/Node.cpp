/******************************************************************************
Function:Node.cpp
Inputs:
Outputs:
Summary:Creates base node function
-------------------------------------------------------------------------------
Pseudo:
Sets val to value and then left and right to start at NULL
******************************************************************************/
#include "node.h"
#include <iostream>
using namespace std;

Node::Node(int value)
{
	val = value;								//Sets val to value and then left and right to start at NULL
	left = NULL;
	right = NULL;

}