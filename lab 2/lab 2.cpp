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
    clinic* medic = new clinic[size];

    counter = readData(medic, size, filename);

    int* arr;
    int exSpec, amount, spec;
    int choice = -1;

    char famInput[maxLen], nameInput[maxLen];

    do {
        cout << "\nChoose option\n";
        cout << "1. Add new medic\n";
        cout << "2. Print data\n";
        cout << "3. Find doctor by name and surname\n";
        cout << "4. Find doctor by specialty\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a valid choice." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1:
            cout << '\n' << "Enter family name: ";
            cin.ignore();
            cin.getline(famInput, maxLen);

            cout << '\n' << "Enter name: ";
            cin.getline(nameInput, maxLen);

            cout << '\n' << "Enter specialty: ";
            cin >> spec;

            if (spec <= 0) {
                cout << "Specialty must be a positive number." << endl;
                continue;
            }

            if (counter == size) {
                size = reallocMem(medic, counter);
            }

            medic[counter].setFam(famInput);
            medic[counter].setName(nameInput);
            medic[counter].setSpec(spec);

            counter++;
            break;
        case 2:
            printData(medic, counter);
            break;
        case 3:
            arr = new int[1];
            cout << "Enter fam: " << endl;
            cin.ignore();
            cin.getline(famInput, maxLen);

            cout << "Enter name: " << endl;
            cin.getline(nameInput, maxLen);

            amount = findByName(medic, arr, counter, famInput, nameInput);
            for (int i = 0; i < amount; i++) {
                printf("%s\t%s\t%d\n", medic[arr[i]].getFam(), medic[arr[i]].getName(), medic[arr[i]].getSpec());
            }
            delete[] arr;
            break;
        case 4:
            arr = new int[1];
            cout << "Enter specialty: " << endl;
            cin >> exSpec;

            if (exSpec <= 0) {
                cout << "Specialty must be a positive number." << endl;
                continue;
            }

            amount = findBySpec(medic, arr, counter, exSpec);
            printf("\nSurname\tName\tSpecialty\n");
            for (int i = 0; i < amount; i++) {
                printf("%s\t%s\t%d\n", medic[arr[i]].getFam(), medic[arr[i]].getName(), medic[arr[i]].getSpec());
            }
            delete[] arr;
            break;
        case 0:
            saveData(medic, counter, filename);
            delete[] medic;
            return 0;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }

    } while (choice != 0);

    return 0;
}
