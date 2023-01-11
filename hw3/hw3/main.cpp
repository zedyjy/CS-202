//
// Created by zeyne on 4.12.2022.
//
#include "DictionarySearchTree.h"
#include "DictionaryBST.h"
#include "DictionaryAVLTree.h"
#include "Dictionary23Tree.h"

int main() {
    DictionaryBST* bst = new DictionaryBST("C:\\Users\\zeyne\\Dropbox\\My PC (LAPTOP-UIF680BP)\\Desktop/dictionary.txt");
    bst->inorderTraverse();

    DictionarySearchTree* myTrees[ 1 ];
    myTrees[ 0 ] = new DictionaryBST( "C:\\Users\\zeyne\\Dropbox\\My PC (LAPTOP-UIF680BP)\\Desktop/dictionary.txt" );
    //myTrees[ 1 ] = new DictionaryAVLTree( "dictionary.txt" );
    //myTrees[ 2 ] = new Dictionary23Tree( "dictionary.txt" );
    string outFiles[ 3 ] = { "C:\\Users\\zeyne\\Dropbox\\My PC (LAPTOP-UIF680BP)\\Desktop/dictionary.txt" , "outAVLTree.txt", "out23Tree.txt" };
    int i;
    myTrees[ 0 ]->search( "query.txt", outFiles[ 0 ] );
    /*
    for ( i = 0; i < 3; i++ ) {
        myTrees[ i ]->search( "query.txt", outFiles[ i ] );
    }
    for ( i = 0; i < 3; i++ ) {
        delete myTrees[ i ];
    }*/
    return 0;
}