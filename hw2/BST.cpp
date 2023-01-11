//
// Created by zeyne on 1.11.2022.
//

#include "BST.h"
#include <iostream>
using namespace std;
#include <cstdlib>

BST::BST() {
    root = NULL;
}

// destructor
BST::~BST() {
    deleteTree(root);
}

void BST::deleteTree(TreeNode *&rootNode) {
    if (rootNode) {
        deleteTree(rootNode->leftChildPtr);
        deleteTree(rootNode->rightChildPtr);
        delete rootNode;
        rootNode = NULL;
    }
}

bool BST::isEmpty() {
    if (root) {
        return false;
    }
    return true;
}

void BST::insert(int key) {
    insertItem(root, key);
}

void BST::deleteKey(int key) {
    deleteItem(root, key);
}

int BST::getHeight() {
    return getHeightHelper(root);
}

double BST::medianOfBST() {
    int index = 0;
    createAsArray(arr, index, root); //O(n)
    int length = getNumberOfNodesOfTree(root); //O(n)
    if ((length % 2) == 1) { //O(1)
        return (double) (arr[length / 2]);
    } else {
        return (double) ((arr[length / 2] + arr[(length / 2) - 1])) / 2;
    }
}

void BST::rangeSearch(int a, int b) {
    rengeHelper(root, a, b);
}

void BST::preorderTraverse() {
    preorder(root);
}

// A method for printing the tree in the inorder
void BST::inorderTraverse() {
    inorder(root);
}

// A method for printing the tree in the postorder
void BST::postorderTraverse() {
    postorder(root);
}

void BST::searchTreeRetrieve(int searchKey,
                             int &treeItem) {
    retrieveItem(searchKey, root, treeItem);
}

TreeNode *BST::retrieveItem(const int &keyItem, TreeNode *&rootNode, int &treeItem) {
    if (!rootNode) {
        return NULL;
    } else {
        if (keyItem == rootNode->item) {
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

void BST::insertItem(TreeNode *&treePtr, const int &item) {
    if (treePtr == NULL) {
        treePtr = new TreeNode(item, NULL, NULL);
    }
    else if (item < treePtr->item) {
        insertItem(treePtr->leftChildPtr, item);
    }
    else {
        insertItem(treePtr->rightChildPtr, item);
    }
}

void BST::deleteItem(TreeNode *&treePtr, int searchKey) {
    if (searchKey == treePtr->item)
        deleteNodeItem(treePtr);

        // Else search for the deletion position
    else if (searchKey < treePtr->item)
        deleteItem(treePtr->leftChildPtr, searchKey);
    else
        deleteItem(treePtr->rightChildPtr, searchKey);

}

void BST::deleteNodeItem(TreeNode *&nodePtr) {
    TreeNode *delPtr;
    int replacementItem;


    // (1)  Test for a leaf
    if ( (nodePtr->leftChildPtr == NULL) &&
         (nodePtr->rightChildPtr == NULL) ) {
        delete nodePtr;
        nodePtr = NULL;
    }


        // (2)  Test for no left child
    else if (nodePtr->leftChildPtr == NULL){
        delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = NULL;
        delete delPtr;
    }

        // (3)  Test for no right child
    else if (nodePtr->rightChildPtr == NULL) {
        // ...
        // Left as an exercise
    }


        // (4)  There are two children:
        //      Retrieve and delete the inorder successor
    else {
        processLeftmost(nodePtr->rightChildPtr, replacementItem);
        nodePtr->item = replacementItem;
    }

}

void BST::processLeftmost(TreeNode *&nodePtr, int &item) {
    if (nodePtr->leftChildPtr == NULL) {
        item = nodePtr->item;
        TreeNode *delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = NULL;
        delete delPtr;
    }
    else
        processLeftmost(nodePtr->leftChildPtr, item);

}

int BST::getHeightHelper(TreeNode *rootNode) {
    int rightH = 0;
    int leftH = 0;

    if(rootNode->leftChildPtr!= NULL) {
        leftH = getHeightHelper(rootNode->leftChildPtr);
    }
    if(rootNode->rightChildPtr != NULL) {
        rightH = getHeightHelper(rootNode->rightChildPtr);
    }
    if(leftH > rightH){
        return leftH + 1;
    }
    else{
        return rightH + 1;
    }
}

void BST::preorder(TreeNode *treePtr) {
    if (treePtr != NULL) {
        cout << treePtr->item << " ";
        preorder(treePtr->leftChildPtr);
        preorder(treePtr->rightChildPtr);
    }
}

void BST::inorder(TreeNode *treePtr) {
    if (treePtr != NULL) {
        inorder(treePtr->leftChildPtr);
        cout << treePtr->item << " ";
        inorder(treePtr->rightChildPtr);
    }
}

int BST::getNumberOfNodesOfTree(TreeNode *&node) {
    if (node != NULL) {
        //look through left, right and add top
        return 1 + getNumberOfNodesOfTree(node->leftChildPtr) + getNumberOfNodesOfTree(node->rightChildPtr);
    }
    else{
        return 0;
    }
}

void BST::postorder(TreeNode *treePtr) {
    if (treePtr != NULL) {
        postorder(treePtr->leftChildPtr);
        postorder(treePtr->rightChildPtr);
        cout << treePtr->item << " ";
    }
}

/*
 * Basically the same with inorder traverse but this function writes an array
 */
void BST::createAsArray(int *treeArray, int &idx, TreeNode *&node) {
    if (node == NULL) {
        return;
    }
    createAsArray(treeArray, idx, node->leftChildPtr);
    treeArray[idx++] = node->item;
    createAsArray(treeArray, idx, node->rightChildPtr);
}

void BST::rengeHelper(TreeNode *root, int a, int b) {
    if (root == NULL) {
        return;
    }
    if (root->item <= b && root->item >= a) {
        cout << root->item << " ";
    }
    if (root->item > a) {
        rengeHelper(root->leftChildPtr, a, b);
    }
    rengeHelper(root->rightChildPtr, a, b);
}
