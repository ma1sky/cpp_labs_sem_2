#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include <iostream>
#include <fstream>
#include <deque>
#include "letter_utils.h"
#include "fio.h"
#include "letter.h"

void readData(deque<letter>& letters, const char* filename);
void saveData(deque<letter> letters, const char* filename);
int isValidInput(const char input[maxLen]);
#endif
