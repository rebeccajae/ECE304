#pragma once
#include <iostream>
using namespace std;
#include "node.h"

Node::Node(int d)
{
    data=d;
    prev=NULL;
    next=NULL;
}

