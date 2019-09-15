/******************************************************************************
Function: Node.h
Inputs:
Outputs:
Summary: creates base class for node
-------------------------------------------------------------------------------
Pseudo:
Add int val, Node left and right pointers and Node to public
******************************************************************************/
#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

class Node
{

public:													//Add int val, Node left and right pointers and Node to public
	int val;
	Node *left, *right;
	Node(int);
};


#endif