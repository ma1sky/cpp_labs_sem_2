#ifndef LETTER_UTILS_H
#define LETTER_UTILS_H
#include "letter.h"

void printData(letter* medic, int counter);
int reallocMem(letter*& m, int& counter);
void expandArr(int*& arr, int amount);
int findByFIO(letter*m, fio find, int*& arr, int counter);

#endif