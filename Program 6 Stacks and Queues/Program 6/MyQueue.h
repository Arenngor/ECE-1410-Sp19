/******************************************************************************
Function:Queue header
Inputs:
Outputs:
-------------------------------------------------------------------------------
Summary:Creates class for queue along with essential variables and functions

Pseudo:
Create functions peek, pop, push, clear, full, empty, and class for MyQueue.
Then create an int to use for size, and an array to keep the values in along with int head and tail
******************************************************************************/

#ifndef MYQUEUE_H
#define MYQUEUE_H


#include <iostream>
using namespace std;

template <class Q>
class MyQueue
{
public:																		//Create functions peek, pop, push, clear, full, empty, and class for MyQueue.
	Q peek();
	Q pop();
	void push(Q value);
	void clear();
	int size();
	int full();
	int empty();
	static int n;
	MyQueue();
private:																	//Then create an int to use for size, and an array to keep the values in along with int head and tail
	Q qar[10];
	int head;
	int tail;
};

template <class Q>
int MyQueue<Q>::n = 0;

/******************************************************************************
Function:MyQueue
Inputs:
Outputs:
-------------------------------------------------------------------------------
Summary: Initializes head and tail

Pseudo:
Set head equal to 0 to initialize it
Set tail to 1 to initialize it
******************************************************************************/

template <class Q>
MyQueue<Q>::MyQueue()
{
	head = 0;																//Set head equal to 0 to initialize it
	tail = 1;																//Set tail to 1 to initialize it
}

/******************************************************************************
Function:pop
Inputs:
Outputs:
-------------------------------------------------------------------------------
Summary: Pops the last piece of the queue off

Pseudo:
Check if cempty, if so, throw error

Else
Incriment tail after setting it to value, if tail is full, set back to 0
Decrement size
Return the temp value
******************************************************************************/

template <class Q>
Q MyQueue<Q>::pop()
{
	if (empty())															//Check if cempty, if so, throw error
	{
		cout << "Exception: Tried to pop from an empty queue!" << endl;
		return 0;
	}
	else
	{																		//Else, Incriment tail after setting it to value, if tail is full, set back to 0
		Q temp = qar[tail];
		tail++;
		if (tail = 10)
		{
			tail = 0;

		}
		n--;																//Decrement size
		return temp;														//Return the temp value
	}
}

/******************************************************************************
Function:push
Inputs:
Outputs:
-------------------------------------------------------------------------------
Summary:Adds a new value into the queue

Pseudo:
Check if full, if so, throw error
Else
Increment size, set head equal to the value and then incriment head
******************************************************************************/

template <class Q>
void MyQueue<Q>::push(Q value)
{
	if (full())															//Check if full, if so, throw error
	{
		cout << "Exception: Tried to push to a full queue!" << endl;
	}
	else
	{																	//Else, Increment size, set head equal to the value and then increment head

		head++;
		if (head == 10)
		{
			head = 0;
		}
		qar[head] = value;
		n++;
	}
}

/******************************************************************************
Function:clear
Inputs:
Outputs:
-------------------------------------------------------------------------------
Summary:Clear all values of queue

Pseudo:
Reset values of headm tail and n to their lowest points in order to delete all values
******************************************************************************/

template <class Q>
void MyQueue<Q>::clear()
{
	head = 0;															//Set head back to 0 tol clear its values
	tail = 1;															//Reset tail to the starting position
	n = 0;																//Reset size
}

/******************************************************************************
Function:Size
Inputs:
Outputs:
-------------------------------------------------------------------------------
Summary:Returns the variable n which keeps track of size

Pseudo:
Return n
******************************************************************************/

template <class Q>
int MyQueue<Q>::size()
{
	return n;															//Returns size, as n
}

/******************************************************************************
Function:Full
Inputs:
Outputs:
-------------------------------------------------------------------------------
Summary:Check if queue is full

Pseudo:
Check if queue is full at 10, if so return true
else
Return 0 for false
******************************************************************************/

template <class Q>
int MyQueue<Q>::full()
{
	if (n == 10)														//Check if queue is full at 10, if so return true
	{
		return 1;
	}
	else
	{																	//Returns 0 is not full
		return 0;
	}
}

/******************************************************************************
Function:empty
Inputs:
Outputs:
-------------------------------------------------------------------------------
Summary:Checks if queue empty

Pseudo:
If size is 0, return true, else return false
******************************************************************************/

template <class Q>
int MyQueue<Q>::empty()
{
	if (n == 0)															//If size is 0, then return true 
	{
		return 1;
	}
	else
	{																	//Else, return false
		return 0;
	}
}

/******************************************************************************
Function:Peek
Inputs:
Outputs:
-------------------------------------------------------------------------------
Summary:Checks what next slot is in queue

Pseudo:
If empty is true, throw error
Else, return the value at tail
******************************************************************************/

template <class Q>
Q MyQueue<Q>::peek()
{
	if (empty())														//If empty is true, throw error
	{
		cout << "Exception: Tried to peek at an empty queue!" << endl;
		return 0;
	}
	else
	{																	//Else, return the value at tail
		return qar[tail];
	}
}
#endif