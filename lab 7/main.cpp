#include "main.h"

int main() {
    const char* filename = "DataBase.txt";
    bool flag = false;
    fio findFIO;
    int delIndex;
    deque<letter> letters;
    deque<letter>::iterator it;
    deque<letter> lettersByFIO;
    readData(letters, filename);
    int choice;

    do {
        cout << "Choose option" << endl;
        cout << "1. Add new letter in back" << endl;
        cout << "2. Add new letter in front" << endl;
        cout << "3. Delete element" << endl;
        cout << "4. Print data" << endl;
        cout << "5. Find letter by FIO" << endl;
        cout << "6. Sort by price" << endl;
        cout << "7. Sort by family name" << endl;
        cout << "8. Delete database" << endl;
        cout << "9. Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;

        if (cin.fail() || choice < 0 || choice > 9) {
            cout << "Invalid input. Please enter a valid choice." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) {
        case 1:
            letters.push_back(createLetter());

            printTableLetter();
            for (const letter& message : letters) {
                cout << message << endl;
            }
            break;
        case 2:
            letters.push_front(createLetter());

            printTableLetter();
            for (const letter& message : letters) {
                cout << message << endl;
            }
            break;
        case 3:
            do {
                cout << '\n' << "Enter number of object: ";
                cin >> delIndex;
                if (cin.fail() || delIndex > letters.size() || delIndex <= 0) {
                    cout << "Incorrect input" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            } while (cin.fail() || delIndex > letters.size() || delIndex <= 0);
            it = letters.begin() + delIndex - 1;
            letters.erase(it);

            printTableLetter();
            for (const letter& message : letters) {
                cout << message << endl;
            }
            break;
        case 4:
            printTableLetter();
            for (const letter& message: letters) {
                cout << message << endl;
            }
            break;
        case 5:
            do {
                findFIO = createFIO();
                for (it = letters.begin(); it != letters.end(); it++) {
                    if (it->getFIO() == findFIO) {
                        lettersByFIO.push_back(*it);
                    }
                }
                void printTableLetter();
                for (letter message : lettersByFIO) {
                    cout << message << endl;
                }
            } while (flag != 0);
            break;
        case 6:
            sort(letters.begin(), letters.end(), less<letter>());

            printTableLetter();
            for (const letter& message : letters) {
                cout << message << endl;
            }
            break;
        case 7:
            sort(letters.begin(), letters.end(), greater<letter>());

            printTableLetter();
            for (const letter& message : letters) {
                cout << message << endl;
            }
            break;
        case 8://киллерфича
            for (it = letters.begin(); it != letters.end(); it++) {
                letters.erase(it);
            }
            cout << "Database removed" << endl; 
            break;
        case 9:
            saveData(letters, filename);
            letters.clear();
            return 0;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
            break;
        }

    } while (choice != 9);

    return 0;
}