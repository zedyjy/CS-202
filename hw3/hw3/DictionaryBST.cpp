//
// Created by zeyne on 4.12.2022.
//


#include "DictionaryBST.h"
#include "Node.h"

#include <iostream>
#include <fstream>
#include <string>

/**
* Title: BST Tree
* Author: Zeynep Doğa Dellal
* ID: 22002572
* Section: 1
* Assignment: 3
 * Explanation: BST class as we did in the previous homeworks
*/

DictionaryBST::DictionaryBST(string dictionaryFile) : DictionarySearchTree(dictionaryFile) {
    root = NULL;
    numOfNodes = 0;
    string word;
    fstream file;
    file.open( dictionaryFile.c_str(), ios_base::in); //open the input file

    while (file.eof() == false) {//read until file is finished
        getline(file, word, '\n');//read text from input file
        insert(word);
    }

    file.close(); //close the input file
}

// destructor
DictionaryBST::~DictionaryBST() {
    deleteTree(root);
}

void DictionaryBST::deleteTree(Node *&rootNode) {
    if (rootNode) {
        deleteTree(rootNode->leftChildPtr);
        deleteTree(rootNode->rightChildPtr);
        delete rootNode;
        rootNode = NULL;
    }
}

bool DictionaryBST::isEmpty() {
    if (root) {
        return false;
    }
    return true;
}

void DictionaryBST::insert(string key) {
    insertItem(root, key);
}

void DictionaryBST::deleteKey(string key) {
    deleteItem(root, key);
}

Node *DictionaryBST::retrieveItem(const string &keyItem, Node *&rootNode, string &treeItem) {
    if (!rootNode) {
        return NULL;
    } else {
        if (keyItem == rootNode->getKey()) {
            treeItem = rootNode->item;
            return rootNode;
        }
        else if (keyItem < rootNode->item) {
            retrieveItem(keyItem, rootNode->leftChildPtr, treeItem);
        }
        else {
            retrieveItem(keyItem, rootNode->rightChildPtr, treeItem);
        }
    }
    return NULL;
}

void DictionaryBST::insertItem(Node *&treePtr, const string &item) {
    if (treePtr == NULL) {
        treePtr = new Node(item, NULL, NULL);
    }
    else if (item < treePtr->item) {
        insertItem(treePtr->leftChildPtr, item);
    }
    else {
        insertItem(treePtr->rightChildPtr, item);
    }
}


void DictionaryBST::deleteItem(Node *&treePtr, string searchKey) {
    if (searchKey == treePtr->item) {
        deleteNodeItem(treePtr);
    }
    else if (searchKey < treePtr->item) { // if it is smaller than root it goes to left
        deleteItem(treePtr->leftChildPtr, searchKey);
    }
    else {
        deleteItem(treePtr->rightChildPtr, searchKey);
    }
}

void DictionaryBST::deleteNodeItem(Node *&nodePtr) {
    Node *delPtr;
    string replacementItem;

    if ((nodePtr->leftChildPtr == NULL) && (nodePtr->rightChildPtr == NULL)) {
        delete nodePtr;
        nodePtr = NULL;
    }
    else if (nodePtr->leftChildPtr == NULL) {
        delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = NULL;
        delete delPtr;
    }
    else if (nodePtr->rightChildPtr == NULL) {
        delPtr = nodePtr;
        nodePtr = nodePtr->leftChildPtr;
        delPtr->leftChildPtr = NULL;
        delete delPtr;
    }
    else {
        processLeftmost(nodePtr->rightChildPtr, replacementItem);
        nodePtr->item = replacementItem;
    }
}

void DictionaryBST::processLeftmost(Node *&nodePtr, string &item) {
    if (nodePtr->leftChildPtr == NULL) {
        item = nodePtr->item;
        Node *delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = NULL; // defense
        delete delPtr;
    } else
        processLeftmost(nodePtr->leftChildPtr, item);
}
void DictionaryBST::inorderTraverse() {
    inorder(root);
}
void DictionaryBST::inorder(Node *treePtr) {
    if (treePtr != NULL) {
        inorder(treePtr->leftChildPtr);
        cout << treePtr->item << " ";
        inorder(treePtr->rightChildPtr);
    }
}