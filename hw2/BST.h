//
// Created by zeyne on 1.11.2022.
//

#ifndef UNTITLED_BST_H
#define UNTITLED_BST_H
#include <iostream>
using namespace std;
#include <cstdlib>
#include "TreeNode.h"


class BST {
public:
    BST();
    BST(const BST& tree);
    ~BST();
    void insert(int key); // 5 points
    void deleteKey(int key); // 10 points
    int getHeight(); // 5 points
    double medianOfBST();
    void rangeSearch(int a, int b);
    bool isEmpty();
    void preorder(TreeNode* treePtr);
    void inorder(TreeNode* treePtr);
    void postorder(TreeNode* treePtr);
    void preorderTraverse();
    void inorderTraverse();
    void postorderTraverse();
    void deleteTree(TreeNode *&rootNode);
    int getNumberOfNodesOfTree(TreeNode *&node);

protected:
    TreeNode* root;
    int height;
    int numOfNodes;
    int * arr;

    TreeNode* retrieveItem(const int &keyItem, TreeNode *&rootNode,int& treeItem);
    void searchTreeRetrieve(int searchKey, int& treeItem);
    void insertItem(TreeNode * &treePtr,const int& item);
    void deleteItem(TreeNode * &treePtr, int searchKey);
    void deleteNodeItem(TreeNode * &nodePtr);
    void processLeftmost(TreeNode * &nodePtr, int& item);
    int getHeightHelper(TreeNode *rootNode);
    void createAsArray(int *treeArray, int &idx, TreeNode *&node);

    void rengeHelper(TreeNode *root, int a, int b);
};


#endif //UNTITLED_BST_H
