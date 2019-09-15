/******************************************************************************
Function:BTree.h
Inputs:
Outputs:
Summary:creates base class for Binary trees
-------------------------------------------------------------------------------
Pseudo:
Create root pointer, Base constructor, addnode, delnode, printtree and 
delete_all to public
******************************************************************************/
#ifndef BTREE_H
#define BTREE_H
#include "Node.h"
#include <iostream>
using namespace std;

class BTree
{
private:
	

public:												//Create root pointer, Base constructor, addnode, delnode, printtree and delete_all
	Node * root;
	BTree();
	void AddNode(int);
	int DelNode(int);
	void PrintTree(Node *, ofstream &);
	void delete_all(Node *);
};

#endif