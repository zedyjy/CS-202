//
// Created by zeyne on 4.12.2022.
//

#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H
#include <iostream>
using namespace std;
#include <cstdlib>
/**
* Title: Node
* Author: Zeynep Doğa Dellal
* ID: 22002572
* Section: 1
* Assignment: 3
*/
class Node {
public:

    Node(const string nodeItem, Node* left = NULL, Node* right = NULL);

    ~Node();

    string item;       // data portion
    Node* leftChildPtr;  // pointer to left child
    Node* rightChildPtr; // pointer to right child

    string getKey();

};
#endif //UNTITLED_NODE_H
