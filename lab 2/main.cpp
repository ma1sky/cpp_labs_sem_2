#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fstream>
#include <iomanip>
#include "clinic.h"
#include "clinic_utils.h"
#include "file_operations.h"

using namespace std;

const int maxLen = 64;

int main() {
    const char* filename = "DataBase.txt";
    int counter = 0;
    int size = 20;
    bool flag = false;
    clinic* medic = new clinic[size];

    counter = readData(medic, size, filename);

    int* arr;
    int exSpec, amount, spec;
    int choice;

    char famInput[maxLen], nameInput[maxLen];

    do {
        cout << "\nChoose option\n";
        cout << "1. Add new medic\n";
        cout << "2. Print data\n";
        cout << "3. Find doctor by name and surname\n";
        cout << "4. Find doctor by specialty\n";
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

            cout << '\n' << "Enter specialty: ";
            
            do {
                cin >> spec;
                if (cin.fail() || spec <= 0) {
                    cout << "Specialty must be a positive number." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            } while (cin.fail() || spec <= 0);

            if (counter == size) {
                size = reallocMem(medic, counter);
            }

            medic[counter].setFam(famInput);
            medic[counter].setName(nameInput);
            medic[counter].setSpec(spec);

            counter++;
            break;
        case 2:
            cout << "\nSurname\t\t" << "Name\t" << "Specialty\t" << endl;
            printData(medic, counter);
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

                cout << "\nSurname\t\t" << "Name\t" << "Specialty\t" << endl;
                amount = findByName(medic, arr, counter, famInput, nameInput);
                if (amount != 0) {
                    for (int i = 0; i < amount; i++) {
                        cout << setw(10) << medic[arr[i]].getFam() << medic[arr[i]].getName() << medic[arr[i]].getSpec();
                    }
                    flag = true;
                } else {
                    flag = false;
                }
                delete[] arr;
            } while (flag != 0);
            break;
        case 4:
            do {
                arr = new int[1];
                cout << "Enter specialty: " << endl;
                cin >> exSpec;

                if (exSpec <= 0) {
                    cout << "Specialty must be a positive number." << endl;
                    continue;
                }

                amount = findBySpec(medic, arr, counter, exSpec);
                if (amount != 0){
                cout << "\nSurname\t\t" << "Name\t" << "Specialty\t" << endl;
                    for (int i = 0; i < amount; i++) {
                        cout << setw(10) << medic[arr[i]].getFam() << medic[arr[i]].getName() << medic[arr[i]].getSpec();
                    }
                    flag = true;
                }
                else {
                    cout << "There is no doctors with such specialty, try other.\n";
                    flag = false;
                }
                delete[] arr;
            } while (flag != true);
            break;
        case 5:
            saveData(medic, counter, filename);
            delete[] medic;
            return 0;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
            break;
        }

    } while (choice != 5);

    return 0;
}
