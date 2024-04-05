#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include "fio.h"
#include "letter.h"
const int maxLen = 64;
int readData(letter*& m, int& size, const char* filename);
void saveData(letter* m, int counter, const char* filename);
int isValidInput(const char input[maxLen]);
#endif
