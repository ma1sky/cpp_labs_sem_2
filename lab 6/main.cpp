#define _CRT_SECURE_NO_WARNINGS
#include "main.h"

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
    delivery* d = new delivery[sizeD]; 
    fio find;
    date dateInput;

    counterM = readLetters(m, sizeM, letterFile);
    counterD = readDelivs(d, sizeD, deliveryFile);

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
        

        try {
            cin >> choice;
            if (choice < 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw "Number must be more than 0";
            }
            if (choice == 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw "Number most be not equal 0";
            }
            if (choice > 7) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw "Number must be less than 7";
            }
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw "Invalid input. Please enter a valid choice.";
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        catch (const char* err) {
            cout << err << endl;
        }

    
        switch (choice) {
        case 1:

            do {
                try {
                cout << '\n' << "Enter family name: ";
                cin.getline(famInput, maxLen);
                flag = isValidInput(famInput);
                }
                catch (const char* err) { cout << err << endl; }
            } while (!flag);

            do {
                try {
                    cout << '\n' << "Enter name: ";
                    cin.getline(nameInput, maxLen);
                    flag = isValidInput(nameInput);
                }
                catch (const char* err) { cout << err << endl; }
            } while (!flag);

            do {
                try {
                    cout << '\n' << "Enter father name: ";
                    cin.getline(fatherInput, maxLen);
                    flag = isValidInput(fatherInput);
                }
                catch (const char* err) { cout << err << endl; }
            } while (!flag);

            do {
                try {
                    cout << '\n' << "Enter addres: ";
                    cin.getline(addrInput, maxLen);
                    flag = isValidAddress(addrInput);
                }
                catch (const char* err) { cout << err << endl; }
            } while (!flag);

            do {
                try {
                    cout << '\n' << "Enter price: ";
                    cin >> priceInput;
                    if (cin.fail() || priceInput <= 0) {
                        throw "Price must be a positive number";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                catch (const char* err) { cout << err << endl; }
            } while (cin.fail() || priceInput <= 0);

            do {
                try {
                    cout << '\n' << "Enter delivery date: ";
                    cin >> dateInput;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                catch (const char* err){
                    cout << err << endl;
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
                    try {
                        cout << '\n' << "Enter family name: ";
                        cin.getline(famInput, maxLen);
                        flag = isValidInput(famInput);
                    }
                    catch (const char* err) { cout << err << endl; }
                } while (!flag);

                do {
                    try {
                        cout << '\n' << "Enter name: ";
                        cin.getline(nameInput, maxLen);
                        flag = isValidInput(nameInput);
                    }
                    catch (const char* err) { cout << err << endl; }
                } while (!flag);

                do {
                    try {
                        cout << '\n' << "Enter father name: ";
                        cin.getline(fatherInput, maxLen);
                        flag = isValidInput(fatherInput);
                    }
                    catch (const char* err) { cout << err << endl; }
                } while (!flag);

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
                    break;
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
                try {
                    cout << '\n' << "Enter family name: ";
                    cin.getline(famInput, maxLen);
                    flag = isValidInput(famInput);
                }
                catch (const char* err) { cout << err << endl; }
            } while (!flag);

            do {
                try {
                    cout << '\n' << "Enter name: ";
                    cin.getline(nameInput, maxLen);
                    flag = isValidInput(nameInput);
                }
                catch (const char* err) { cout << err << endl; }
            } while (!flag);

            do {
                try {
                    cout << '\n' << "Enter father name: ";
                    cin.getline(fatherInput, maxLen);
                    flag = isValidInput(fatherInput);
                }
                catch (const char* err) { cout << err << endl; }
            } while (!flag);

            do {
                try {
                    cout << '\n' << "Enter addres: ";
                    cin.getline(addrInput, maxLen);
                    flag = isValidAddress(addrInput);
                }
                catch (const char* err) { cout << err << endl; }
            } while (!flag);

            do {
                try {
                    cout << '\n' << "Enter price: ";
                    cin >> priceInput;
                    if (cin.fail() || priceInput <= 0) {
                        throw "Price must be a positive number";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                catch (const char* err) { cout << err << endl; }
            } while (cin.fail() || priceInput <= 0);

            do {
                try {
                    cout << '\n' << "Enter volume: ";
                    cin >> volumeInput;
                    if (cin.fail() || volumeInput <= 0) {
                        throw "Volume must be a positive number";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                catch (const char* err) { cout << err << endl; }
            } while (cin.fail() || volumeInput <= 0);

            do {
                try {
                    cout << '\n' << "Weight volume: ";
                    cin >> weightInput;
                    if (cin.fail() || weightInput <= 0) {
                        throw "Weight must be a positive number";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                catch (const char* err) { cout << err << endl; }
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
            for (int i = 0; i < counterD; i++) {
                cout << d[i];
            }
            break;
        case 7:
            saveLetters(m, counterM, letterFile);
            saveDelivs(d, counterD, deliveryFile);
            delete[] m;
            delete[] d;
            return 0;
            break;
        default:
            break;
        }
        
    } while (choice != 7);

}