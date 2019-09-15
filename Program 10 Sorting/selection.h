/******************************************************************************
Function: Selection sort 
Summary:
Build list, and identify smallest unsorted item and then proceed to swap it with the first proper item
-------------------------------------------------------------------------------
Pseudo:
Create base class Selection and add constrctor and print to public
create ints, i, j, imin and temp
build list
set the min = to j
identify lowest values and swap
repeat until no swaps
******************************************************************************/

#ifndef SELECTION_H
#define SELECTION_H

#include <iostream>
using namespace std;

template <class T>
class Selection														//Create base class Selection and add constrctor and print to public
{
public:
		Selection(T *, int);
		void print(T *, int);
};

template <class T>
Selection<T>::Selection(T *array, int size)
{																	//create ints, i, j, imin and temp
	int i, j, imin;
	T temp = 0;
	for (j = 0; j < size - 1; j++)									//build list
	{
		imin = j;													//set the min = to j
		for (i = j + 1; i < size; i++) 
		{
			if (array[i] < array[imin]) 
			{
				imin = i;											//set min back to i
			}
		}

		if (imin != j) 
		{
			temp = array[j];										//identify lowest values and swap
			array[j] = array[imin];
			array[imin] = temp;
		}															//repeat until no swaps
	}
}


/******************************************************************************
Function: Print
Summary:
print the array and its values
-------------------------------------------------------------------------------
Pseudo:
print array with tabs between values for comparing purposes
******************************************************************************/
template <class T>
void Selection<T>::print(T *array, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		cout << array[i] << ";\t" << endl;
	}

}
#endif
