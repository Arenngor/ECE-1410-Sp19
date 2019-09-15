/******************************************************************************
Function: Quick sort 
Summary:

-------------------------------------------------------------------------------
Pseudo:
Create base class Quick and add partition, quicksort and print to public

******************************************************************************/

#ifndef QUICK_H
#define QUICK_H

template <class T>
class Quick																			//Create base class Quick and add partition, quicksort and print to public
{
public:
	Quick(T *, int);
	void print(T *, int);
	int partition(T *, int, int);
	void quicksort(T *, int, int, int);
};

/******************************************************************************
Function: quicksort
Summary:
properly calls for partitioning and for sorting to be done
-------------------------------------------------------------------------------
Pseudo:
Set p = to the partition value
call for sorting on the array from low to high

******************************************************************************/

template <class T>
void Quick<T>::quicksort(T *array, int high, int low, int p)
{
	if (low < high)
	{
		p = partition(array, high, low);											//Set p = to the partition value
		quicksort(array, p - 1, low, p);											//call for sorting on the array from low to high
		quicksort(array, high, p + 1, p);
	}
}

/******************************************************************************
Function: Partition
Summary:
Partitions array for item placement
-------------------------------------------------------------------------------
Pseudo:
Create ints i, j and temp
locate halfway point to find pivot
place element
repeat
******************************************************************************/

template <class T>
int Quick<T>::partition(T *array, int high, int low)
{
	int i = 0, j = 0;																//Create ints i, j and temp
	T temp = 0;
	T p = array[high];
	i = low - 1;
	for (j = low; j < high; j++)													//locate halfway point to find pivot
	{
		if (array[j] < p)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;														//place element
		}
		
	}
	temp = array[high];
	array[high] = array[i + 1];
	array[i + 1] = temp;
	return i + 1;																	//repeat
}
/******************************************************************************
Function: Quick
Summary:
locates needed values
-------------------------------------------------------------------------------
Pseudo:
locate the value of high and low
then call sorting on array

******************************************************************************/

template <class T>
Quick<T>::Quick(T *array, int size)
{
	int high = size - 1, low = 0, p = 0;											//locate the value of high and low
	quicksort(array, high, low, p);													//then call sorting on array

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
void Quick<T>::print(T *array, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		cout << array[i] << ";\t";
	}
}

#endif