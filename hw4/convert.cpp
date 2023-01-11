//
// Created by zeyne on 23.12.2022.
//

#include "convert.h"
#include "TwoThreeFourNode.h"
#include <iostream>

using namespace std;

void convert::insert(int id, RedBlackNode* left, RedBlackNode* right, bool type)
{
    nodes[id].val = id;
    nodes[id].leftChildPtr = left;
    nodes[id].rightChildPtr = right;
    nodes[id].isRed = type;
}

void convert::inorderTraverse(RedBlackNode* root) {
    if (root == NULL) return;

    inorderTraverse(root->leftChildPtr);
    std::cout << root->val << " ";
    inorderTraverse(root->rightChildPtr);
}


void convert::inorderTraverse234(TwoThreeFourNode* root) {
    if (root == NULL) return;

    inorderTraverse234(root->leftChildPtr);

    if (root->lMidChildPtr) inorderTraverse234(root->lMidChildPtr);

    cout << root->middleItem << " ";

    inorderTraverse234(root->rightChildPtr);
}

void convert::insertItemHelper(string filename)
{
    std::ifstream infile(filename);

    infile >> numNodes >> root->val;
    for (int i = 0; i < numNodes; i++) {
        int id, type;
        RedBlackNode *left, *right;
        infile >> id >> left->val >> right->val >> type;
        insert(id, left, right, type);
    }
    infile.close();
}

convert::convert(string dictionaryFile) {
    insertItemHelper(dictionaryFile);
    nodes = NULL;
}

void convert::convertTree(){
    convertTo234Tree(root);
}

RedBlackNode* convert::convertTo234Tree(RedBlackNode* root) {

}
