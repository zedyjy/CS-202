//
// Created by zeyne on 23.12.2022.
//
#include <iostream>
using namespace std;
#include <cstdlib>
#include "RedBlackNode.h"

RedBlackNode::RedBlackNode(const int nodeItem, RedBlackNode* left, RedBlackNode* right,bool red )
{
    val = nodeItem;
    leftChildPtr = left;
    rightChildPtr = right;
    isRed = red;
}

int RedBlackNode::getKey()
{
    return val;
}

RedBlackNode::RedBlackNode(const int nodeItem) {
    val = nodeItem;
}
