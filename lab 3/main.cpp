#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fstream>
#include <iomanip>
#include "fio.h"
#include "letter.h"
#include "letter_utils.h"
#include "file_operations.h"

using namespace std;

int main() {
    const char* filename = "DataBase.txt";
    int counter = 0;
    int size = 20;
    bool flag = false;
    letter* m = new letter[size];
    fio find;

    counter = readData(m, size, filename);
    float priceInput;
    int* arr;
    int amount;
    int choice;

    char famInput[maxLen], nameInput[maxLen], fatherInput[maxLen], addrInput[maxLen];

    do {
        cout << "\nChoose option\n";
        cout << "1. Add new letter\n";
        cout << "2. Print data\n";
        cout << "3. Find letter by FIO\n";
        cout << "4. Sort by price\n";
        cout << "5. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        if (cin.fail() || choice < 0 || choice > 5) {
            cout << "Invalid input. Please enter a valid choice." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) {
        case 1:
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

            if (counter == size) {
                size = reallocMem(m, counter);
            }

            m[counter].setFIO(famInput, nameInput, fatherInput);
            m[counter].setPrice(priceInput);
            m[counter].setAddr(addrInput);

            counter++;
            break;
        case 2:
            cout << setw(20) << left << "\nAddress"
                << setw(20) << left << "Price"
                << setw(20) << left << "Fam"
                << setw(20) << left << "Name"
                << setw(20) << left << "Father"
                << endl;
            for (int i = 0; i < counter; i++) {
                //cout << m[i];
                m[i].printLetter();
            }
            break;
        case 3:
            do {
                arr = new int[1];

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

                find.setFam(famInput);
                find.setFather(fatherInput);
                find.setName(nameInput);

                cout << setw(20) << left << "\nSurname" 
                    << setw(20) << left << "Name" 
                    << setw(20) << left << "Specialty" 
                    << endl;
                amount = findByFIO(m, find, arr, counter);
                if (amount != 0) {
                    for (int i = 0; i < amount; i++) {
                        m[arr[i]].printLetter();
                    }
                    flag = true;
                }
                else {
                    flag = false;
                }
                delete[] arr;
            } while (flag != 0);
            break;
        case 4:
            sort(m, counter);
            cout << setw(20) << left << "\nAddress"
                << setw(20) << left << "Price"
                << setw(20) << left << "Fam"
                << setw(20) << left << "Name"
                << setw(20) << left << "Father"
                << endl;
            for (int i = 0; i < counter; i++) {
                m[i].printLetter();
            }
            break;
        case 5:
            saveData(m, counter, filename);
            delete[] m;
            return 0;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
            break;
        }

    } while (choice != 5);

    return 0;
}