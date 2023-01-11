//
// Created by zeyne on 4.12.2022.
//
#ifndef UNTITLED_DICTIONARYSEARCHTREE_H
#define UNTITLED_DICTIONARYSEARCHTREE_H
#include <iostream>
using namespace std;
#include <cstdlib>
#include "Node.h"
/**
* Title: Search Tree
* Author: Zeynep Doğa Dellal
* ID: 22002572
* Section: 1
* Assignment: 3
*/
class DictionarySearchTree {
public:
    Node* root;
    int numOfNodes;

    //Constructor that constructs the dictionary from the input file
    DictionarySearchTree(string dictionaryFile);

    //Destructor
    virtual ~DictionarySearchTree();

    //Inserts the given word into the dictionary
    virtual void insert(string word);

    //Searches the given word in the dictionary, and returns the number
    //of comparisons made and whether the word is found or not
    virtual void search(string word, int& numComparisons, bool& found) const;

    //Searches all words in the query file in the dictionary, and
    //summarizes the results in the output file
    virtual void search(string queryFile, string outputFile) const;

    virtual void destroyTree(Node*& treePtr);

    virtual void insertItemHelper(Node*& treePtr, const string& item, bool& success);
};

#endif //UNTITLED_DICTIONARYSEARCHTREE_H