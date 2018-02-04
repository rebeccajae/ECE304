#include <iostream>
using namespace std;
#include "node.h"
#include "DL_list.h"

DL_list::DL_list()
{
    head_node= new Node(0);
	first=head_node;
}

bool DL_list::empty()
{
    bool emptyornot=0;
    if (first->next==NULL){
        emptyornot=true;
    }
    return emptyornot;
}

void DL_list::insert(Node *newnode, Node *pred) {
    newnode->next = pred->next;
    pred->next = newnode;
    newnode->prev = pred;
    if (newnode->next != NULL) {
        pred->next->prev = newnode;
    }

}

void DL_list::erase(Node *pred) {
    Node *current;
    current = pred->next;
    pred->next = current->next;
    if (current->next != NULL) {
        current->next->prev = pred;
    }
}

void DL_list::display()
{
    Node * current;
    if (first->next!=NULL){
        current=first->next;
        while (current->next!=NULL)
        {
            cout<<current->data<<"  ";
            current=current->next;
        }
     cout<<current->data<<"\n";
    }
}

DL_list * DL_list::copy()
{
    DL_list *newList = new DL_list();
    Node * newListPrev = newList->head_node;
    Node * currentListNext = this->head_node->next;

    while(currentListNext != NULL){
        Node * newTempNode = new Node(currentListNext->data);
        newList->insert(newTempNode, newListPrev);
        newListPrev = newTempNode;
        currentListNext = currentListNext->next;
    }

    return newList;
}

int DL_list::listSize() {
    int size = 0;
    Node * nextNode = this->first->next;
    while(nextNode != NULL){
        size++;
        nextNode = nextNode->next;
    }
    return size;

}

double DL_list::calc_mean() {
    double sum = 0.0;
    double size = 0;
    Node * nextNode = this->first->next;
    while(nextNode != NULL){
        sum += nextNode->data;
        size++;
        nextNode = nextNode->next;
    }

    return sum/size;
}

void DL_list::search_delete(int score) {
    Node * nextNode = this->head_node->next;
    while(nextNode != NULL){
        if(nextNode->data == score){
            this->erase(nextNode->prev);
        }
        nextNode = nextNode->next;
    }
}


 