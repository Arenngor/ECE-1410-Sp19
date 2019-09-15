/******************************************************************************
Function:main
Inputs:char, int
Outputs:
Summary:Opens input file and then reads it, after that it will pass the values
into the output file for printing
-------------------------------------------------------------------------------
Pseudo:
open input file
open output file
check if files are good
loop
initialize char c and int value
call BTree
while not at end of file
get character and its value
if "a", then add value to tree
if "d", then delete value from tree
end loop
print to output file
close input file
close output file
call destructor
end
******************************************************************************/

#include "BTree.h"
#include "Node.h"

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	ifstream ifile;											//check if files are good
	ifile.open(argv[1]);
	ofstream ofile;
	ofile.open(argv[2]);									//open input and output files
	if (ifile.good() && ofile.good())
	{
		char c = 0;
		int value = 0;										//initialize char c and int value

		BTree b;											//call btree 
		while (!ifile.eof())								//while not at end of file
		{
			ifile >> c >> value;

			if (c == 'a')									//get character and its value, if "a", then add value to tree
			{
				b.AddNode(value);
			}
			if (c == 'd')									//if "d", then delete value from tree
			{
				b.DelNode(value);
			}
		}

		b.PrintTree(b.root, ofile);							//print to output file
		ifile.close();										//close input file, and close output
		ofile.close();
		b.delete_all(b.root);								//call destructor
	}
	return 0;
}