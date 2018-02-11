#include <iostream>

using namespace std;

#include "Stack.h"
#define CAPACITY 128

Stack::Stack()
{
	stack_size = 0;
}
bool Stack::empty()
{
	return (stack_size == 0);
}
void Stack::push(StackElement item)
{
	stackArray[stack_size] = item;
	stack_size++;
}
StackElement Stack::pop()
{
	if (empty())
	{
		cout << "Stack is empty" << endl;
		return 0;
	}
	else
	{
		stack_size--;
		return stackArray[stack_size];
	}		
}
void Stack::display()
{
	for (int i = stack_size - 1; i > 0; i--)
	{
		cout << stackArray[i] << " ";
	}
}