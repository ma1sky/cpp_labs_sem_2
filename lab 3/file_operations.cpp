#include <iostream>
#include <fstream>
#include "file_operations.h"
#include "fio.h"
#include "letter.h"
#include "letter_utils.h"

using namespace std;
const int maxLen = 64;

int readData(letter*& m, int& size, const char* filename) {
    int counter = 0;
    int priceInput;
    char famInput[maxLen], nameInput[maxLen], fatherInput[maxLen], addressInput[maxLen];
    int famLen, nameLen, fatherLen, addressLen;

    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << " for reading." << endl;
        return 0;
    }

    while (file >> famLen) {
        file.get();
        file.get(famInput, famLen + 1);
        file >> nameLen;
        file.get();
        file.get(nameInput, nameLen + 1);
        file >> fatherLen;
        file.get();
        file.get(fatherInput, fatherLen + 1);
        file >> addressLen;
        file.get();
        file.get(addressInput, addressLen);
        file >> priceInput;


        if (counter == size) {
            size = reallocMem(m, counter);
        }

        m[counter].setFIO(famInput, nameInput, fatherInput);
        m[counter].setPrice(priceInput);
        m[counter].setAddr(addressInput);

        counter++;
    }

    file.close();
    return counter;
}

void saveData(letter*& m, int counter, const char* filename) {
    ofstream file;
    file.open(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << " for writing." << endl;
        return;
    }

    for (int i = 0; i < counter; i++) {
        file << strlen(m[i].getFIO().getFam()) << ' ' 
            << m[i].getFIO().getFam() << ' ' 
            << strlen(m[i].getFIO().getName()) << ' ' 
            << m[i].getFIO().getName() << ' ' 
            << strlen(m[i].getFIO().getFather()) << ' ' 
            << m[i].getFIO().getFather() << ' '
            << strlen(m[i].getAddr()) << ' '
            << m[i].getAddr() << ' '
            << m[i].getPrice() << ' ';
    }

    file.close();
}

int isValidInput(const char input[64]) {
    int i = 0;
    if (!(input[0] != '\0' && strlen(input) > 0)) {
        cout << "Invalid input, try again." << endl;
        return 0;
    }
    while (input[i]) {
        if (!(isalpha(input[i]) && input[i] != ' ' && input[i] != '\t')) {
            cout << "Invalid input, try again." << endl;
            return 0;
        }
        i++;
    }
    return 1;
}