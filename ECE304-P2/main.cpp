#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>

#include "node.h"
#include "DL_list.h"


#define NUMBER_ITEMS 30

int main() {
    srand(time(0));
    Node* nodes[NUMBER_ITEMS];
    for (int i = 0; i < NUMBER_ITEMS; ++i) {
        nodes[i] = new Node(rand() % 71 + 30); //Same score gen from the first lab.
    }
    DL_list *list = new DL_list();
    list->insert(nodes[0], list->head_node);
    for (int i = 1; i < NUMBER_ITEMS; ++i) {
        list->insert(nodes[i], nodes[i-1]);
    }
    std::cout << "list->display(): ";
    list->display();
    std::cout << "list->listSize(): " << list->listSize() << std::endl;
    DL_list* copied_list = list->copy();
    int removeScore = 0;
    std::cout << "Score to delete: ";
    std::cin >> removeScore;
    copied_list->search_delete(removeScore);
    std::cout << "list->listSize(): " << list->listSize() << std::endl;
    std::cout << "copied_list->listSize(): " << copied_list->listSize() << std::endl;
    std::cout << "list->calc_mean(): " << list->calc_mean() << std::endl;
    std::cout << "copied_list->calc_mean(): " << copied_list->calc_mean() << std::endl;
    return 0;
}