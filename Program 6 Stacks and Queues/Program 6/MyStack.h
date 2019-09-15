/******************************************************************************
Function:Stack header
Inputs:
Outputs:
-------------------------------------------------------------------------------
Summary:Creates class for stack along with essential variables and functions


Pseudo:
Create functions peek, pop, push, clear, full, empty, and class for MyStack.
Then create an int to use for size, and an array to keep the values in along with int top.
******************************************************************************/
#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
using namespace std;

template <class S>
class MyStack
{
public:																	//Create functions peek, pop, push, clear, full, empty, and class for MyStack.
	S peek();
	S pop();
	void push(S value);
	void clear();
	int size();
	int full();
	int empty();
	static int n;
	MyStack();
private:																//Then create an int to use for size, and an array to keep the values in along with int top.
	S sar[10];
	int top;
};

template <class S>
int MyStack<S>::n = 0;

/******************************************************************************
Function:MyStack
Inputs:
Outputs:
-------------------------------------------------------------------------------
Summary: Initializes top

Pseudo:
Set top equal to 0 to initialize it
******************************************************************************/

template <class S>
MyStack<S>::MyStack()
{
	top = 0;																//initialize top
}

/******************************************************************************
Function:pop
Inputs:
Outputs:
-------------------------------------------------------------------------------
Summary: Pops the last piece of the stack off

Pseudo:
Check if cempty, if so, throw error

Else
Decrement top and n and then return the value of top.
******************************************************************************/

template <class S>
S MyStack<S>::pop()
{
	if (empty())															//Check if cempty, if so, throw error
	{
		cout << "Exception: Tried to pop from an empty stack!" << endl;
		return 0;
	}
	else
	{																		//Else, Decrement top and n and then return the value of top.
		top--;
		n--;
		return sar[top];
	}
}

/******************************************************************************
Function:push
Inputs:
Outputs:
-------------------------------------------------------------------------------
Summary:Adds a new value into the stack

Pseudo:
Check if full, if so, throw error
Else
Increment size, set top equal to the value and then incriment top
******************************************************************************/

template <class S>
void MyStack<S>::push(S value)
{
		
		if (full())															//Check if full, if so, throw error
		{
			cout << "Exception: Tried to push to a full stack!" << endl;
		}
		else
		{																	//Else, Increment size, set top equal to the value and then increment top
			n++;
			sar[top] = value;
			top++;
		}
}

/******************************************************************************
Function:clear
Inputs:
Outputs:
-------------------------------------------------------------------------------
Summary:Clears the stack

Pseudo:
Set top equal to 0 clearing all other values
******************************************************************************/

template <class S>
void MyStack<S>::clear()
{
	top = 0;																//Set top equal to 0 clearing all other values

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

template <class S>
int MyStack<S>::size()
{
	return n;																//Return size
}

/******************************************************************************
Function:Full
Inputs:
Outputs:
-------------------------------------------------------------------------------
Summary:Check if stack is full

Pseudo:
Check if stack is full at 10, if so return true
else
Return 0 for false
******************************************************************************/

template <class S>
int MyStack<S>::full()
{
	if (n == 10)															//Check if stack is full at 10, if so return true
	{
		return 1;
	}
	else
	{																		//Else, Return 0 for false
		return 0;
	}
}

/******************************************************************************
Function:empty
Inputs:
Outputs:
-------------------------------------------------------------------------------
Summary:Checks if stack is empty

Pseudo:
If size is 0, return true, else return false
******************************************************************************/

template <class S>
int MyStack<S>::empty()
{
	if (n == 0)																//If size is 0, return true
	{
		return 1;
	}
	else
	{																		//else return false
		return 0;
	}
}

/******************************************************************************
Function:Peek
Inputs:
Outputs:
-------------------------------------------------------------------------------
Summary:Checks what next slot is in stack

Pseudo:
If empty is true, throw error
Else, return the value at top-1
******************************************************************************/

template <class S>
S MyStack<S>::peek()
{
	if (empty())															//If empty is true, throw error
	{
		cout << "Exception: Tried to peek at an empty stack!" << endl;
		return 0;
	}
	else
	{																		//Else, return the value at top-1
		return sar[top - 1];
	}
}

#endif