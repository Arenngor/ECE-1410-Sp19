/******************************************************************************
Function: Insertion sort 
Summary:
Build list per item added and sorts before placement
-------------------------------------------------------------------------------
Pseudo:
Create base class Insertion and add constrctor and print to public
creats ints i, j, temp
build list item by item running new values through the previous list
continue while array is proper size
swap new values with old values until properly sorted
increment i
******************************************************************************/

#ifndef INSERTION_H
#define INSERTION_H

#include <iostream>
using namespace std;

template <class T>												//create template
class Insertion
{
public:															//Create base class Insertion and add constrctor and print to public
	Insertion(T *, int);
	void print(T *, int);

};

template <class T>
Insertion<T>::Insertion(T *array, int size)
{
	int i = 1, j = 0;
	T temp = 0;
	while (i < size)											//run through list 
	{
		j = i;
		while (j > 0 && array[j - 1] > array[j])				//continue while array is proper size
		{
			temp = array[j];									//swap new values with old values until properly sorted
			array[j] = array[j - 1];
			array[j - 1] = temp;
			j--;
		}
		i++;													//increment i
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
void Insertion<T>::print(T *array, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		cout << array[i] << ";\t" << endl;
	}
}

#endif