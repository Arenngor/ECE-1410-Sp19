#include "BTree.h"
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

/******************************************************************************
Function:BTree
Inputs:
Outputs:
Summary:initializes root
-------------------------------------------------------------------------------
Pseudo:
set root to NULL to start tree
******************************************************************************/
BTree::BTree()
{
	root = NULL;										//set root to NULL to start tree
}

/******************************************************************************
Function:Addnode
Inputs:value
Outputs:
Summary:adds node to tree from input file
-------------------------------------------------------------------------------
Pseudo:
Calls pointers from node
set cur to root and prev to NULL
if cur is NULL
set it to the new node
then set root to cur
while cur and val are not value
if val is greater than value , add to left side of the tree
else add to right side of tree
******************************************************************************/
void BTree::AddNode(int value)
{
	Node *cur;											//Calls pointers from node
	Node *prev = NULL;
	
	cur = root;											//set cur to root and prev to NULL
	prev = NULL;
	
	if (cur == NULL)									//if cur is NULL
	{
		cur = new Node(value);
		root = cur;										//set it to the new node and root to cur
	}

	while (cur && cur->val != value)					//while cur and val are not value
	{
		if (cur->val > value)							//if val is greater than value , add to left side of the tree
		{
			prev = cur;
			cur = cur->left;
			if (cur == NULL)
			{
				cur = new Node(value);
				prev->left = cur;
			}
		}
		else											//else add to right side of tree
		{
			prev = cur;
			cur = cur->right;
			if (cur == NULL)
			{
				cur = new Node(value);
				prev->right = cur;
			}
		}
	}
	
	
}

/******************************************************************************
Function:DelNode
Inputs:value
Outputs:
Summary:deletes a node from the tree when called, has variants for each case of deletion
-------------------------------------------------------------------------------
Pseudo:
Adds pointers for cur, prev and x
set cur to root and prev to NULL
initialize check and temp
while cur and val are not value
set prev = cur
if val is less than value, add to left tree
else add to right

check for NULL cur

if node has no children
delete node

if node has right children
set root to right child
else set to left child
then delete node

if node has left children
set root to left child
else set to right child
delete node

if node has children on each side
follow once to the right
then left all the way
then use temp to hold node value and delete node
******************************************************************************/
int BTree::DelNode(int value)
{
	Node *cur, *prev, *x;													//Adds pointers for cur, prev and x
	cur = root;
	prev = NULL;															//set cur to root and prev to NULL
	int check = 0;
	int temp = 0;															//initialize check and temp

	while (cur && cur->val != value)										//while cur and val are not value
	{
		prev = cur;
		if (cur->val > value)
		{
			cur = cur->left;												//if val is less than value, add to left tree

		}
		else
		{
			cur = cur->right;												//else add to right
		}
	}
	if (cur == NULL)														//check for NULL cur

	{
		check = 1;
	}

	if (cur && cur->left == NULL && cur->right == NULL && check == 0)		//if node has no children
	{
		if (value < prev->val)
		{
			prev->left = NULL;
		}
		else
		{
			prev->right = NULL;
		}
		delete(cur);														//delete node
		return 1;
	}

	if (cur && cur->left == NULL && cur->right != NULL && check == 0)		//if node has right children
	{
		if (prev == NULL)
		{
			root = cur->right;												//set root to right child
			delete(cur);
			return 1;
		}
		else if (value < prev->val)											//else set to left child
		{
			prev->left = cur->right;
		}
		else
		{
			prev->right = cur->right;
		}
		delete(cur);														//then delete node
		return 1;
	}

	if (cur && cur->left != NULL && cur->right == NULL && check == 0)		//if node has left children
	{

		if (prev == NULL)
		{
			root = cur->left;												//set root to left child
			delete(cur);
			return 1;

		}
		else if (value < prev->val)											//else set to right child
		{
			prev->left = cur->left;
		}
		else
		{
			prev->right = cur->left;
		}
		delete(cur);														//else delete node
		return 1;
	}

	if (cur && cur->left != NULL && cur->right != NULL && check == 0)		//if node has children on each side
	{
		x = cur;															//follow once to the right
		cur = cur->right;
		while (cur->left)
		{
			cur = cur->left;
		}
		temp = cur->val;													//use temp to hold original value
		DelNode(cur->val);
		x->val = temp;
		return 1;															//delete node
	}
}

/******************************************************************************
Function:PrintTree
Inputs:
Outputs:
Summary:Prints nodes
-------------------------------------------------------------------------------
Pseudo:
use node cur pointer and set it to name
if n isnt NULL
print val to the ofile and then print the log
******************************************************************************/
void BTree::PrintTree(Node *n, std::ofstream &ofile)
{
	Node *cur = n;
	if (n != NULL)															//use node cur pointer and set it to name
	{
		PrintTree(cur->left, ofile);
		ofile << cur->val << "\t" << log10(cur->val) << endl;				//print val to the ofile and then print the log
		PrintTree(cur->right, ofile);
	}
	return;
}

/******************************************************************************
Function:delete all
Inputs:
Outputs:
Summary:deletes all nodes
-------------------------------------------------------------------------------
Pseudo:use cur pointer 
delete left pointer nodes
delete right pointer nodes
delete root node
end

******************************************************************************/
void BTree::delete_all(Node * n)
{
	Node *cur = n;
	if (n != NULL)
	{
		delete_all(cur->left);												//delete left pointer nodes
		delete_all(cur->right);												//delete right pointer nodes
		delete n;
	}
	return;
}