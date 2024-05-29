#ifndef CLINIC_UTILS_H
#define CLINIC_UTILS_H
#include "clinic.h"

void printData(clinic* medic, int counter);
int reallocMem(clinic*& m, int& counter);
void expandArr(int*& arr, int amount);
int findBySpec(clinic* m, int*& arr, int counter, int exSpec);
int findByName(clinic* m, int*& arr, int counter, char* fam, char* name);

#endif