#pragma once
#include "stdafx.h"
#include <iostream>
using namespace std;
#include "node.h"

Node::Node(char d)
{
    data=d;
    prev=NULL;
    next=NULL;
}

