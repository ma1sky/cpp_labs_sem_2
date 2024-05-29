#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include "fio.h"
#include "letter.h"
#include "delivery.h"
int readData(letter*& m, int& size, const char* filename);
void saveLetters(letter* m, int counter, const char* filename);
void saveLetters(delivery* m, int counter, const char* filename);

int isValidInput(const char input[maxLen]);
#endif
