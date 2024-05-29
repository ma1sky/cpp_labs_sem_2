#ifndef LETTER_UTILS_H
#define LETTER_UTILS_H
#include "letter.h"
#include "delivery.h"

int reallocMem(letter*& m, int& counter);
int reallocMemDeliv(delivery*& d, int& counter);

void expandArr(int*& arr, int amount);
int findByFIO(letter*m, fio find, int*& arr, int counter);
void printTableLetter();
void printTableDeliv();
#endif