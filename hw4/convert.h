//
// Created by zeyne on 23.12.2022.
//

#ifndef UNTITLED_CONVERT_H
#define UNTITLED_CONVERT_H
#include <fstream>
using namespace std;
#include <cstdlib>
#include "RedBlackNode.h"
#include "TwoThreeFourNode.h"
#include <iostream>
const int MAX_NODES = 100;
class convert {
public:
    virtual void insertItemHelper(string filename);
    convert(string dictionaryFile);
    virtual void insert(int id, RedBlackNode* left, RedBlackNode* right, bool type);

    virtual void inorderTraverse(RedBlackNode* root);
    int numNodes;
    RedBlackNode* root;
    RedBlackNode* convertTo234Tree(RedBlackNode* root);
    void convertTree();
    void inorderTraverse234(TwoThreeFourNode* root);
private:
    RedBlackNode *nodes;
};


#endif //UNTITLED_CONVERT_H
