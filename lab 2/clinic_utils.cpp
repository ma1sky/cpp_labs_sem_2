#include <iostream>
#include "clinic_utils.h"
#include "clinic.h"

using namespace std;

void printData(clinic* medic, int counter) {
    for (int i = 0; i < counter; i++) {
        medic[i].printMedic();
    }
}

int reallocMem(clinic*& m, int& counter) {
    int size = counter + 2;
    clinic* newM = new clinic[size];
    for (int i = 0; i < counter; i++) {
        newM[i] = m[i];
    }
    delete[] m;
    m = newM;
    return size;
}

void expandArr(int*& arr, int amount) {
    int* newArr = new int[amount + 1];
    for (int i = 0; i < amount; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
}

int findBySpec(clinic* m, int*& arr, int counter, int exSpec) {
    int amount = 0;
    for (int i = 0; i < counter; i++) {
        if (m->isSpec(exSpec)) {
            expandArr(arr, amount);
            arr[amount] = i;
            amount++;
        }
    }
    return amount;
}

int findByName(clinic* m, int*& arr, int counter, char* fam, char* name) {
    int amount = 0;
    for (int i = 0; i < counter; i++) {
        if (m[i].isMedic(fam, name)) {
            expandArr(arr, amount);
            arr[amount] = i;
            amount++;
        }
    }
    return amount;
}