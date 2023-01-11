//
// Created by zeyne on 1.11.2022.
//
#include <iostream>
using namespace std;
#include "BST.h"
#include "TreeNode.h"
#include "analysis.h"

using namespace std;

int main() {
    cout << "=== Creating the tree ===" << endl;
    BST tree;
    tree.insert(30);
    tree.insert(40);
    tree.insert(35);
    tree.insert( 20);
    tree.insert(50);
    tree.insert(45);
    tree.insert(10);
    tree.insert(25);
    tree.insert(5);
    tree.insert(15);

    tree.inorderTraverse();

    cout << "Height of the given BST is: " << tree.getHeight()<<endl;

    tree.inorderTraverse();

    tree.deleteKey(35);
    tree.deleteKey(40);
    tree.inorderTraverse();

    cout << "Median of the given BST is: " << tree.medianOfBST() << endl;
    tree.inorderTraverse();

    cout<< "Numbers between 5 and 43 are: ";
    tree.rangeSearch(5,43);
    cout<<endl;
    tree.inorderTraverse();


    analysis analysis;
    analysis.heightAnalysis();
}
