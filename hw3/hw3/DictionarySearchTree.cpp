//
// Created by zeyne on 4.12.2022.
//

#include <fstream>
#include "DictionarySearchTree.h"
#include "Node.h"
/**
* Title: Dictionary Search Tree
* Author: Zeynep Doğa Dellal
* ID: 22002572
* Section: 1
* Assignment: 3
*/
DictionarySearchTree::DictionarySearchTree(string dictionaryFile)
{
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

DictionarySearchTree::~DictionarySearchTree()
{
    destroyTree(root);
}

void DictionarySearchTree::insert(string word)
{
    bool success;
    insertItemHelper(root, word, success);
    if (success)
        numOfNodes++;
}

void DictionarySearchTree::search(string word, int& numComparisons, bool& found) const{

}

void DictionarySearchTree::search(string queryFile, string outputFile) const{
}

void DictionarySearchTree::destroyTree(Node*& treePtr)
{
    if (treePtr != NULL) {
        destroyTree(treePtr->leftChildPtr);
        destroyTree(treePtr->rightChildPtr);
        delete treePtr;
        treePtr = NULL;
    }
}

void DictionarySearchTree::insertItemHelper(Node*& treePtr, const string& item, bool& success)
{
    if(treePtr == NULL){
        treePtr = new Node(item, NULL, NULL);
        success = true;
        if (treePtr == NULL) {
            success = false;
        }
    }
    else if(item < treePtr->getKey()){
        insertItemHelper(treePtr->rightChildPtr, item, success);
    }
    else{
        insertItemHelper(treePtr->leftChildPtr, item, success);
    }
}