//
// Created by zeyne on 1.11.2022.
//

#include "analysis.h"
#include "BST.h"
#include <iostream>
using namespace std;
#include <cstdlib>
#include <iomanip>

void analysis::createRandomArrays(int *&arr1,  const int size) {
    srand(time(0));
    int random;
    for (int i = 0; i < size; i++) {
        random = rand();
        arr1[i] = random;
    }
}

void analysis::swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void analysis::shuffleArray(int *&arr, const int size){
    srand (time(NULL));
    for (int i = size - 1; i > 0; i--){
        int j = rand() % (i + 1);
        swap(arr[i], arr[j]);
    }
}

void analysis::heightAnalysis() {
    int* arr = new int[30000];
    createRandomArrays(arr, 30000);
    BST tree;
    cout<<"Part f - Analysis of BST height - part 1"<<endl;
    cout <<"----------------------------------------"<<endl;
    cout<<"Tree Size"<< setw(15) << "Tree Height"<< endl;
    cout <<"----------------------------------------"<<endl;
    for(int i = 0; i <= 30000; i++){
        tree.insert(arr[i]);
        if((i % 1500) == 0 && i<10500 && i!=0){
            cout <<i<<setw(16) << tree.getHeight() << endl;
        }
        else if((i % 1500) == 0 && i>=10500){
            cout <<i<<setw(15) << tree.getHeight() << endl;
        }
    }

    cout<<"Part f - Analysis of BST height - part 2"<<endl;
    cout <<"----------------------------------------"<<endl;
    cout<<"Tree Size"<< setw(15) << "Tree Height"<< endl;
    cout <<"----------------------------------------"<<endl;
    shuffleArray(arr,30000);
    for(int i = 30000; i > 0; i--){
        tree.deleteKey(arr[i]);
        if((i % 1500) == 0 && i<10500 && i!=0){
            cout <<i<<setw(16) << tree.getHeight() << endl;
        }
        else if((i % 1500) == 0 && i>=10500){
            cout <<i<<setw(15) << tree.getHeight() << endl;
        }
    }
    delete[] arr;
}
