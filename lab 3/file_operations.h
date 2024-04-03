#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include "fio.h"
#include "letter.h"

const int maxLen = 64;
int readData(clinic*& m, int& size, const char* filename);
void saveData(clinic*& m, int counter, const char* filename);
int isValidInput(const char input[maxLen]);
char* getString();
#endif
