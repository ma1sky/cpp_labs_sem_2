#include "file_operations.h"
#include "clinic_utils.h"
#include <iostream>
#include <fstream>
#include "clinic.h"

using namespace std;
const int maxLen = 64;
int readData(clinic*& m, int& size, const char* filename) {
    int counter = 0;
    int specInput;
    char famInput[maxLen], nameInput[maxLen];
    int famLen, nameLen;

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
        file >> specInput;

        if (counter == size) {
            size = reallocMem(m, counter);
        }

        m[counter].setFam(famInput);
        m[counter].setName(nameInput);
        m[counter].setSpec(specInput);

        counter++;
    }

    file.close();
    return counter;
}

void saveData(clinic*& m, int counter, const char* filename) {
    ofstream file;
    file.open(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << " for writing." << endl;
        return;
    }

    for (int i = 0; i < counter; i++) {
        file << strlen(m[i].getFam()) << ' ' << m[i].getFam() << ' ' << strlen(m[i].getName()) << ' ' << m[i].getName() << ' ' << m[i].getSpec() << ' ';
    }

    file.close();
}
