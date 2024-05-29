#include <iostream>
#include <fstream>
#include "file_operations.h"
#include "fio.h"
#include "letter.h"
#include "letter_utils.h"

using namespace std;

int readData(letter*& m, int& size, const char* filename) {
    int counter = 0;
    float priceInput;
    char famInput[maxLen], nameInput[maxLen], fatherInput[maxLen], addressInput[maxLen];
    int famLen, nameLen, fatherLen, addressLen;

    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << " for reading." << endl;
        return 0;
    }

    while (file.get() == '/') {
        file >> famLen;
        file.get(famInput, famLen + 1);
        file >> nameLen;
        file.get(nameInput, nameLen + 1);
        file >> fatherLen;
        file.get(fatherInput, fatherLen + 1);
        file >> addressLen;
        file.get(addressInput, addressLen + 1);
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

void saveLetters(letter* m, int counter, const char* filename) {
    ofstream file;
    file.open(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << " for writing." << endl;
        return;
    }

    for (int i = 0; i < counter; i++) {
        m[i].save(file);
    }

    file.close();
}

int isValidInput(const char input[maxLen]) {
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