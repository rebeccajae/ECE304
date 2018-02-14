// ECE304-M.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "node.h"
#include "DL_list.h"
#define SZ 4


int main()
{
	Node* nodes[SZ];
	//Create List and nodes (Part a)
	DL_list *list = new DL_list();
	nodes[0] = new Node('s');
	nodes[1] = new Node('p');
	nodes[2] = new Node('o');
	nodes[3] = new Node('t');
	//Insert them all into the list (Part b)
	list->insert(nodes[0], list->head_node);
	for (int i = 1; i < SZ; ++i) {
		list->insert(nodes[i], nodes[i - 1]);
	}
	list->display(); // Display S P O T (Part c)
	list->swap(nodes[2]); // Swap around node O (Part d)
	list->display(); // Display S T O P (Part e)
	list->erase(nodes[0]->prev); // Delete node s (Part f)
	list->swap(nodes[3]); // Call swap again, point to t node (Part g) - Should do nothing.
	list->display(); // Display T O P (Part h)
	return 0;
}

