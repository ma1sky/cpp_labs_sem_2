#include "letter_utils.h"

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

void printTableLetter() {
    cout << setw(20) << left << "\nFamily"
        << setw(20) << left << "Name"
        << setw(20) << left << "Father"
        << setw(20) << left << "Address"
        << setw(20) << left << "Price"
        << endl;
}

fio& createFIO() {
    char famInput[maxLen], nameInput[maxLen], fatherInput[maxLen];
    do {
        cout << '\n' << "Enter family name: ";
        cin.getline(famInput, maxLen);
    } while (!isValidInput(famInput));

    do {
        cout << '\n' << "Enter name: ";
        cin.getline(nameInput, maxLen);
    } while (!isValidInput(nameInput));

    do {
        cout << '\n' << "Enter father name: ";
        cin.getline(fatherInput, maxLen);
    } while (!isValidInput(fatherInput));
    fio* FIO = new fio(famInput, nameInput, fatherInput);
    return *FIO;
}

letter& createLetter() {
    char addrInput[maxLen];
    float priceInput;
    fio FIO = createFIO();

    do {
        cout << '\n' << "Enter addres: ";
        cin.getline(addrInput, maxLen);
    } while (!isValidInput(addrInput));

    do {
        cout << '\n' << "Enter price: ";
        cin >> priceInput;
        if (cin.fail() || priceInput <= 0) {
            cout << "Price must be a positive number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (cin.fail() || priceInput <= 0);

    letter* message = new letter(FIO, priceInput, addrInput);
    return *message;
}