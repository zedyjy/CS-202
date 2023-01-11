//
// Created by zeyne on 1.11.2022.
//

#ifndef UNTITLED_TREENODE_H
#define UNTITLED_TREENODE_H
#include <iostream>
using namespace std;
#include <cstdlib>

class TreeNode { 	// a node in the tree
private:
    TreeNode() { }
    TreeNode(const int& nodeItem,TreeNode *left = 0,
             TreeNode *right = 0)
            : item(nodeItem), leftChildPtr(left), rightChildPtr(right){ }


    int item; 		// a data item in the tree
    TreeNode *leftChildPtr;	// pointers to children
    TreeNode *rightChildPtr;


    // friend class - can access private parts
    friend class BST;
};


#endif //UNTITLED_TREENODE_H
