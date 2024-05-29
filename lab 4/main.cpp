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
#include "date.h"
#include "delivery.h"
#include "common.h"

using namespace std;
const char* letterFile = "lettersDataBase.txt";
const char* deliveryFile = "deliveryDataBase.txt";

int main() {

    int counterM = 0;
    int counterD = 0;
    int sizeD = 20;
    int sizeM = 20;
    bool flag = false;
    letter* m = new letter[sizeM];
    delivery* d = new delivery[sizeM];
    fio find;
    date dateInput;

    counterM = readData(m, sizeM, letterFile);
    float priceInput, volumeInput, weightInput;
    int* arr;
    int amount, choice;

    char famInput[maxLen], nameInput[maxLen], fatherInput[maxLen], addrInput[maxLen];

    do {
        cout << "\nChoose option\n";
        cout << "1. Add new letter\n";
        cout << "2. Print letters\n";
        cout << "3. Find letter by FIO\n";
        cout << "4. Sort letters by price\n";
        cout << "5. Add new delivery\n";
        cout << "6. Print deliveries\n";
        cout << "7. Exit\n";
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

            do {
                cout << '\n' << "Enter delivery date: ";
                cin >> dateInput;
                if (cin.fail() || dateInput <= 0) {
                    cout << "Date must be a positive number." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            } while (cin.fail() || dateInput <= 0);

            if (counterM == sizeM) {
                sizeM = reallocMem(m, counterM);
            }

            m[counterM].setFIO(famInput, nameInput, fatherInput);
            m[counterM].setPrice(priceInput);
            m[counterM].setAddr(addrInput);
            m[counterM].setDate(dateInput);

            counterM++;
            break;
        case 2:
            printTableLetter();
            for (int i = 0; i < counterM; i++) {
                cout << m[i];
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

                printTableLetter();
                amount = findByFIO(m, find, arr, counterM);
                if (amount != 0) {
                    for (int i = 0; i < amount; i++) {
                        cout << m[arr[i]];
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
            sort(m, counterM);
            printTableLetter();
            for (int i = 0; i < counterM; i++) {
                cout << m[i];
            }
            break;

        case 5:
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

            do {
                cout << '\n' << "Enter volume: ";
                cin >> volumeInput;
                if (cin.fail() || volumeInput <= 0) {
                    cout << "Volume must be a positive number." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            } while (cin.fail() || volumeInput <= 0);

            do {
                cout << '\n' << "Enter weight: ";
                cin >> weightInput;
                if (cin.fail() || weightInput <= 0) {
                    cout << "Weight must be a positive number." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            } while (cin.fail() || weightInput <= 0);

            if (counterD == sizeD) {
                sizeD = reallocMemDeliv(d, counterD);
            }

            d[counterD].setFIO(famInput, nameInput, fatherInput);
            d[counterD].setPrice(priceInput);
            d[counterD].setAddr(addrInput);
            d[counterD].setWeight(weightInput);
            d[counterD].setVolume(volumeInput);

            counterD++;
            break;
        case 6:
            printTableDeliv();
            for (int i = 0; i < counterM; i++) {
                cout << d[i];
            }
            break;
        case 7:
            saveData(m, counterM, letterFile);
            delete[] m;
            return 0;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
            break;
        }

    } while (choice != 5);
}