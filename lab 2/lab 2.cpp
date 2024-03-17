#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
using namespace std;

const char* filename = "DataBase.txt";
const int maxLen = 16;

class clinic {
private:
    char* fam;
    char* name;
    int specialty;
    static int count;

public:
    clinic() : fam(nullptr), name(nullptr), specialty(-1) {
        count++;
    }

    clinic(const char* fam, const char* name, int specialty)
        : specialty(specialty), fam(nullptr), name(nullptr) {
        setFam(fam);
        setName(name);
        count++;
    }

    ~clinic() {
        delete[] fam;
        delete[] name;
        count--;
    }



    const char* getFam() const {
        return fam;
    }

    void setFam(const char* fam) {
        if (this->fam != nullptr){
            delete[] this->fam;
        }
        this->fam = new char[strlen(fam) + 1];
        strcpy(this->fam, fam);
    }

    const char* getName() const {
        return name;
    }

    void setName(const char* name) {
        if (this->name != nullptr) {
            delete[] this->name;
        }
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    int getSpec() const {
        return specialty;
    }

    void setSpec(int specialty) {
        this->specialty = specialty;
    }

    void printMedic() {
        cout << this->fam << this->name << this->specialty;
    }
    static int getCount() {
        return count;
    }
    
};
int clinic::count = 0;


void addNew(clinic*& m, int& counter, const char* famIn, const char* nameIn, int specIn) {
    clinic* newMed = new clinic[counter + 1];
    for (int i = 0; i < counter; i++) {
        newMed[i] = m[i];
    }
    newMed[counter] = clinic(famIn, nameIn, specIn);
    delete[] m;
    m = newMed;
    counter++;
}

int main() {

    clinic* medic = new clinic[5];
    cout << medic->getCount();
    int specIn;
    int choice = -1;
    int counter = 0;
    char famInput[maxLen], nameInput[maxLen];
    char* famIn;
    char* nameIn;
    

    do {
        cout << "\nChoose option\n";
        cout << "1. Add new medic\n";
        cout << "2. Print data\n";
        cout << "3. Find doctor by name and surname\n";
        cout << "4. Find doctor by specialty\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice){
        case 1:
            cout << "\n" << "Enter family name, name, and specialty: ";
            cin >> famInput >> nameInput >> specIn;
            famIn = _strdup(famInput);
            nameIn = _strdup(nameInput);
            addNew(medic, counter, famIn, nameIn, specIn);
            for (int i = 0; i < counter; i++) {
                medic[i].printMedic();
            }
            break;
        case 2:

        case 3:

        case 4:

        case 0:
            return 0;
        }
    } while (choice != 0);

    return 0;
}
