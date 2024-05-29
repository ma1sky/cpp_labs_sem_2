#include <iostream>
#include <fstream>
#include "file_operations.h"
#include "fio.h"
#include "letter.h"
#include "letter_utils.h"
#include "date.h"

using namespace std;

int readDelivs(delivery*& d, int& size, const char* filename) {
    int counter = 0;
    float priceInput;
    char famInput[maxLen], nameInput[maxLen], fatherInput[maxLen], addressInput[maxLen];
    int famLen, nameLen, fatherLen, addressLen;
    date dateInput;
    int volumeInput, weightInput;

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
        file >> priceInput >>  volumeInput >> weightInput;

        if (counter == size) {
            size = reallocMemDeliv(d, counter);
        }

        d[counter].setFIO(famInput, nameInput, fatherInput);
        d[counter].setPrice(priceInput);
        d[counter].setAddr(addressInput);
        d[counter].setVolume(volumeInput);
        d[counter].setWeight(weightInput);
        counter++;
    }

    file.close();
    return counter;
}

int readLetters(letter*& m, int& size, const char* filename)
{
    int counter = 0;
    float priceInput;
    char famInput[maxLen], nameInput[maxLen], fatherInput[maxLen], addressInput[maxLen];
    int famLen, nameLen, fatherLen, addressLen;
    date dateInput;
    int day, month, year;

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
        file >> day >> month >> year;

        if (counter == size) {
            size = reallocMem(m, counter);
        }

        m[counter].setFIO(famInput, nameInput, fatherInput);
        m[counter].setPrice(priceInput);
        m[counter].setAddr(addressInput);
        m[counter].setDate({ day, month, year });
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

void saveDelivs(delivery* d, int counter, const char* filename)
{
    ofstream file;
    file.open(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << " for writing." << endl;
        return;
    }

    for (int i = 0; i < counter; i++) {
        d[i].save(file);
    }

    file.close();
}

bool isValidInput(const char input[maxLen]) {
    int i = 0;
    if (!(input[0] != '\0' && strlen(input) > 0)) {
        throw "Input is empty";
        return false;
    }
    if (strlen(input) > 20) {
        throw "Input must be less than 20 characters";
        return false;
    }
    while (input[i]) {
        if (!(isalpha(input[i]) && input[i] != ' ' && input[i] != '\t')) {
            throw "Input is not alphanumeric";
            return false;
        }
        i++;
    }
    return true;
}

bool isValidAddress(const char input[maxLen]) {
    int i = 0;
    if (!(input[0] != '\0' && strlen(input) > 0)) {
        throw "Input is empty";
        return false;
    }
    if (strlen(input) > 20) {
        throw "Input must be less than 20 characters";
        return false;
    }
    while (input[i]) {
        if (!(isalnum(input[i]) && input[i] != ' ' && input[i] != '\t')) {
            throw "Input is not alphanumeric";
            return false;
        }
        i++;
    }
    return true;
}