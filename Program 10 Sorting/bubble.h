/******************************************************************************
Function: Bubble Sort 
Summary:
Sort items in a list by grouping them in 2's and swapping when necessary
-------------------------------------------------------------------------------
Pseudo:
Create base class Bubble and template for class using T
add Constructor and print functions to public

create ints for swapped, looping, i and temp
while swapping is still done, run through loop
compare elements in list and swap when needed
repeat until no swaps
******************************************************************************/
#ifndef BUBBLE_H
#define BUBBLE_H

#include <iostream>
using namespace std;

template <class T>
class Bubble												//Create base class Bubble and template for class using T
{
public:														//add Constructor and print functions to public
		Bubble(T *, int);
		void print(T *, int);
	
};

template <class T>
Bubble<T>::Bubble(T *array, int size)						//create ints for swapped, looping, i and temp
{
	int swapped = 1, i = 0, looping = 1;
	T temp = 0;
	while(swapped)											//while swapping is still done, run through loop
	{

		swapped = 0;
		for(i = 1; i < size; i++)
		{
			if(array[i-1] > array[i])
			{
				temp =  array[i-1];
				array[i-1] = array[i];
				array[i] = temp;							//compare elements in list and swap when needed
				swapped = 1;
			}
		}
	}														//repeat until no swaps
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
void Bubble<T>::print(T *array, int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		cout << array[i] << ";\t" << endl;
	}
	
}
#endif