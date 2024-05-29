#include <iostream>
#include "letter_utils.h"
#include "letter.h"
#include "delivery.h"

using namespace std;

int reallocMem(letter*& m, int& counter) {
    int size = int(counter * 1.5);
    letter* newM = new letter[size];
    for (int i = 0; i < counter; i++) {
        newM[i] = m[i];
    }
    delete[] m;
    m = newM;
    return size;
}

int reallocMemDeliv(delivery*& d, int& counter) {
    int size = int(counter * 1.5);
    delivery* newD = new delivery[size];
    for (int i = 0; i < counter; i++) {
        newD[i] = d[i];
    }
    delete[] d;
    d = newD;
    return size;
}

void expandArr(int*& arr, int amount) {
    int* newArr = new int[amount + 10];
    for (int i = 0; i < amount; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
}

int findByFIO(letter* m, fio find, int*& arr, int counter) {
    int amount = 0;
    for (int i = 0; i < counter; i++) {
        if (m[i].getFIO() == find) {
            expandArr(arr, amount);
            arr[amount] = i;
            amount++;
        }
    }
    return amount;
}

void printTableLetter() {
    cout << setw(20) << left << "\nFam"
        << setw(20) << left << "Name"
        << setw(20) << left << "Father"
        << setw(20) << left << "Address"
        << setw(20) << left << "Price"
        << setw(20) << left << "Day"
        << setw(20) << left << "Month"
        << setw(20) << left << "Year"
        << endl;
}

void printTableDeliv() {
    cout << setw(20) << left << "\nFam"
        << setw(20) << left << "Name"
        << setw(20) << left << "Father"
        << setw(20) << left << "Address"
        << setw(20) << left << "Price"
        << setw(20) << left << "Volume"
        << setw(20) << left << "Weigth"
        << endl;
}