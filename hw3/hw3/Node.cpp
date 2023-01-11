//
// Created by zeyne on 4.12.2022.
//
#include <iostream>
#include <string>
#include "Node.h"
/**
* Title: Node
* Author: Zeynep Doğa Dellal
* ID: 22002572
* Section: 1
* Assignment: 3
*/
Node::Node(const string nodeItem, Node* left, Node* right)
{
    item = nodeItem;
    leftChildPtr = left;
    rightChildPtr = right;
}

Node::~Node()
{
}

string Node::getKey()
{
    return item;
}
