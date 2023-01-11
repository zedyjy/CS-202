//
// Created by zeyne on 4.12.2022.
//
#ifndef UNTITLED_DICTIONARYBST_H
#define UNTITLED_DICTIONARYBST_H

using namespace std;
#include "DictionarySearchTree.h"
#include "Node.h"
#include <iostream>
/**
* Title: BST Tree
* Author: Zeynep Doğa Dellal
* ID: 22002572
* Section: 1
* Assignment: 3
 * Explanation: BST class as we did in the previous homeworks
*/
class DictionaryBST: public DictionarySearchTree{
    public:
        DictionaryBST(string dictionaryFile);
        DictionaryBST(const DictionaryBST& tree);
        ~DictionaryBST();
        void insert(string key); // 5 postrings
        void deleteKey(string key); // 10 postrings
        string getHeight(); // 5 postrings
        double medianOfDictionaryBST();
        void rangeSearch(string a, string b);
        bool isEmpty();
        void inorder(Node* treePtr);
        void inorderTraverse();
        void deleteTree(Node *&rootNode);
        string getNumberOfNodesOfTree(Node *&node);

    Node* retrieveItem(const string &keyItem, Node *&rootNode,string& treeItem);

protected:
        Node* root;
        string height;
        int numOfNodes;
        string * arr;

    void searchTreeRetrieve(string searchKey, string& treeItem);
        void insertItem(Node * &treePtr,const string& item);
        void deleteItem(Node * &treePtr, string searchKey);
        void deleteNodeItem(Node * &nodePtr);
        void processLeftmost(Node * &nodePtr, string& item);
        string getHeightHelper(Node *rootNode);
        void createAsArray(string *treeArray, string &idx, Node *&node);

        void rengeHelper(Node *root, string a, string b);
};
#endif UNTITLED_DICTIONARYBST_H
