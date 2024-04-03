#include <iostream>
#include "letter_utils.h"
#include "letter.h"

using namespace std;

void printData(letter* m, int counter) {
    for (int i = 0; i < counter; i++) {
        m[i].printLetter();
    }
}

int reallocMem(letter*& m, int& counter) {
    int size = counter * 1.5;
    letter* newM = new letter[size];
    for (int i = 0; i < counter; i++) {
        newM[i] = m[i];
    }
    delete[] m;
    m = newM;
    return size;
}

void expandArr(int*& arr, int amount) {
    int* newArr = new int[amount * 1.5];
    for (int i = 0; i < amount; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
}