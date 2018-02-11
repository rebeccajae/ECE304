#pragma once
#define CAPACITY 128

typedef char StackElement;
class Stack
{
	StackElement stackArray[CAPACITY];
	int stack_size;
public:
	Stack();
	bool empty();
	void push(StackElement item);
	StackElement pop();
	void display();
};