#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include "fio.h"
#include "letter.h"
#include "delivery.h"
int readLetters(letter*& m, int& size, const char* filename);
int readDelivs(delivery*& d, int& size, const char* filename);
void saveLetters(letter* m, int counter, const char* filename);
void saveDelivs(delivery* d, int counter, const char* filename);

bool isValidInput(const char input[maxLen]);
bool isValidAddress(const char input[maxLen]);
#endif
