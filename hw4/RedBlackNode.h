//
// Created by zeyne on 23.12.2022.
//

#ifndef UNTITLED_REDBLACKNODE_H
#define UNTITLED_REDBLACKNODE_H
#include <iostream>
using namespace std;
#include <cstdlib>

enum Color {RED, BLACK};

class RedBlackNode {
public:
    int val;
    bool isRed;
    RedBlackNode *leftChildPtr, *rightChildPtr;
    Color     leftColor, rightColor;
    RedBlackNode* parent;
    int getKey();

    RedBlackNode(const int nodeItem, RedBlackNode* left = NULL, RedBlackNode* right = NULL, bool red = false);
    RedBlackNode(const int nodeItem);
};
#endif //UNTITLED_REDBLACKNODE_H
