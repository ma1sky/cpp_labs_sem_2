#include "file_operations.h"

using namespace std;

void readData(deque<letter>& letters, const char* filename) {
    int counter = 0;
    float priceInput;
    char famInput[maxLen], nameInput[maxLen], fatherInput[maxLen], addressInput[maxLen];
    int famLen, nameLen, fatherLen, addressLen;

    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << " for reading." << endl;
    } else { 
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

            letters.push_back(letter(fio(famInput, nameInput, fatherInput), priceInput, addressInput));
        }

        file.close();
    }
    file.close();
}

void saveData(deque<letter> letters, const char* filename) {
    ofstream file;
    file.open(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << " for writing." << endl;
        return;
    }

    for (letter& message: letters) {
        file << "/"
            << strlen(message.getFIO().getFam())
            << message.getFIO().getFam()
            << strlen(message.getFIO().getName())
            << message.getFIO().getName()
            << strlen(message.getFIO().getFather())
            << message.getFIO().getFather()
            << strlen(message.getAddr())
            << message.getAddr()
            << message.getPrice();
    }

    file.close();
}