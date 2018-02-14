#pragma once
#include <iostream>
using namespace std;
#include "node.h"

class DL_list
{
public:
	Node * first;
	Node * head_node;
	DL_list();
	bool empty();
	void insert(Node *newnode, Node * pred);
	void erase(Node *pred);
	void display();
	DL_list * copy();
	int listSize();
    double calc_mean();
    void search_delete(int score);
	void swap(Node* param);
};