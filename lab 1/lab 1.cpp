#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct medic {
    char* fam;
    char* name;
    int specialty;
};

const char* filename = "DataBase.txt";
const int maxLen = 16;

int isValidMenuChoice(int choice) {
    if (choice < 0 || choice > 4) {
        return 0;
    }
    return 1;
}

int isValidInput(const char* input) {
    int i = 0;
    while (input[i]) {
        if (!isalnum(input[i]) && input[i] != ' ') {
            return 0;
        }
        i++;
    }
    return 1;
}

void saveData(FILE* fp, medic* m, const char* filename, int counter, int newEl) {
    fseek(fp, 0, SEEK_END);

    for (int i = counter - newEl; i < counter; i++) {
        size_t famLen = strlen(m[i].fam);
        size_t nameLen = strlen(m[i].name);
        fwrite(&famLen, sizeof(size_t), 1, fp);
        fwrite(m[i].fam, sizeof(char), famLen, fp);
        fwrite(&nameLen, sizeof(size_t), 1, fp);
        fwrite(m[i].name, sizeof(char), nameLen, fp);
        fwrite(&m[i].specialty, sizeof(int), 1, fp);
    }

    fclose(fp);
}


void freeMem(medic* m, int counter) {
    for (int i = 0; i < counter; i++) {
        delete[] m[i].fam;
        delete[] m[i].name;
    }
    delete[] m;
}

void addNew(medic*& m, int& counter, const char* famIn, const char* nameIn, int specIn) {
    medic* newM = new medic[counter + 1];
    for (int i = 0; i < counter; i++) {
        newM[i] = m[i];
    }
    delete[] m;
    newM[counter].fam = _strdup(famIn);
    newM[counter].name = _strdup(nameIn);
    newM[counter].specialty = specIn;
    m = newM;
    counter++;
}

void printMedics(medic* m, int counter) {
    printf("\nSurname\tName\tSpecialty\t\n");
    for (int i = 0; i < counter; i++) {
        printf("%s\t%s\t%d\n", m[i].fam, m[i].name, m[i].specialty);
    }
}

void expandArr(int*& arr, int amount) {
    int* newArr = new int[amount + 1];
    for (int i = 0; i < amount; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
}

int findByName(medic* m, int*& arr, int counter, char* famIn, char* nameIn) {
    int amount = 0;
    for (int i = 0; i < counter; i++) {
        if (strcmp(m[i].fam, famIn) == 0 && strcmp(m[i].name, nameIn) == 0) {
            expandArr(arr, amount);
            arr[amount] = i;
            amount++;
        }
    }
    return amount;
}

int findBySpec(medic* m, int*& arr, int counter, int exSpec) {
    int amount = 0;
    for (int i = 0; i < counter; i++) {
        if (m[i].specialty == exSpec) {
            expandArr(arr, amount);
            arr[amount] = i;
            amount++;
        }
    }
    return amount;
}

//void printByName(medic* m, int counter) {
//    char exName[maxLen];
//    char exFam[maxLen];
//
//    printf("Enter family name and name: ");
//    scanf("%15s %15s", exFam, exName);
//
//    if (!isValidInput(exFam) || !isValidInput(exName)) {
//        printf("Invalid input, try again.\n");
//    }
//    else {
//        printf("\nSurname\tName\tSpecialty\t\n");
//        for (int i = 0; i < counter; i++) {
//            if (strcmp(m[i].fam, exFam) == 0 && strcmp(m[i].name, exName) == 0) {
//                printf("%s\t%s\t%d\n", m[i].fam, m[i].name, m[i].specialty);
//            }
//        }
//    }
//}

//void printBySpec(medic* m, int counter) {
//    int exSpec;
//    printf("Enter specialty: ");
//    scanf("%d", &exSpec);
//    printf("\nSurname\tName\tSpecialty\t\n");
//    for (int i = 0; i < counter; i++) {
//        if (m[i].specialty == exSpec) {
//            printf("%s\t%s\t%d\n", m[i].fam, m[i].name, m[i].specialty);
//        }
//    }
//}

int main() {
    
    size_t famLen;
    size_t nameLen;

    char* famIn;
    char* nameIn;
    char famInput[maxLen];
    char nameInput[maxLen];

    int specIn;
    int newEl = 0;
    int choice = -1;
    int counter = 0;
    int exSpec = 0;
    int* arr = new int[1];
    int amount;

    FILE* fp = fopen(filename, "r+");
    if (fp == NULL) {
        printf("File doesn't exist. Creating new file...\n");
        fp = fopen(filename, "w+");
        if (fp == NULL) {
            perror("Error opening file");
            return 1;
        }
    }
    else {
        fseek(fp, 0, SEEK_SET);
    }

    medic* m = new medic[1];

    while (fread(&famLen, sizeof(size_t), 1, fp)) {
        famIn = new char[famLen + 1];
        fread(famIn, sizeof(char), famLen, fp);
        famIn[famLen] = '\0';
        fread(&nameLen, sizeof(size_t), 1, fp);
        nameIn = new char[nameLen + 1];
        fread(nameIn, sizeof(char), nameLen, fp);
        nameIn[nameLen] = '\0';
        fread(&specIn, sizeof(int), 1, fp);
        addNew(m, counter, famIn, nameIn, specIn);
        delete[] famIn;
        delete[] nameIn;
    }

    do {
        printf("\nChoose option\n");
        printf("1. Add new medic\n");
        printf("2. Print data\n");
        printf("3. Find doctor by name and surname\n");
        printf("4. Find doctor by specialty\n");
        printf("0. Exit\n");
        printf("Your choice: ");

        char choiceStr[10];
        scanf("%s", choiceStr);

        if (!isdigit(choiceStr[0])) {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        int choice = atoi(choiceStr);
        if (!isValidMenuChoice(choice)) {
            printf("Invalid choice. Please enter a number between 0 and 4.\n");
            continue;
        }

        switch (choice) {
        case 1:
            printf("Enter family name, name, and specialty: ");
            scanf("%s %s %d", famInput, nameInput, &specIn);
            if (!isValidInput(famInput) || !isValidInput(nameInput)) {
                printf("Invalid input, try again.\n");
                break;
            }
            famIn = _strdup(famInput);
            nameIn = _strdup(nameInput);
            addNew(m, counter, famIn, nameIn, specIn);
            delete[] famIn;
            delete[] nameIn;
            newEl++;
            break;
        case 2:
            printMedics(m, counter);
            break;
        case 3:
            printf("Enter family name, name: ");
            scanf("%s %s", famInput, nameInput);
            if (!isValidInput(famInput) || !isValidInput(nameInput)) {
                printf("Invalid input, try again.\n");
                break;
            }
            famIn = _strdup(famInput);
            nameIn = _strdup(nameInput);
            amount = findByName(m, arr, counter, famIn, nameIn);
            if (amount == 0) {
                printf("No doctors found");
                break;
            }
            printf("\nSurname\tName\tSpecialty\n");
            for (int i = 0; i < amount; i++) {
                printf("%s\t%s\t%d\n", m[arr[i]].fam, m[arr[i]].name, m[arr[i]].specialty);
            }
            delete[] famIn;
            delete[] nameIn;
            delete[] arr;
            break;
        case 4:
            printf("Enter specialty: ");
            if (scanf("%d", &exSpec) != 1 || exSpec < 0) {
                printf("Invalid input. Please enter a non-negative integer.\n");
                break;
            }

            arr = new int[counter];
            if (arr == nullptr) {
                printf("Memory allocation failed.\n");
                break;
            }

            amount = findBySpec(m, arr, counter, exSpec);
            if (amount == 0) {
                printf("No doctors found\n");
                delete[] arr;
                break;
            }

            printf("\nSurname\tName\tSpecialty\n");
            for (int i = 0; i < amount; i++) {
                printf("%s\t%s\t%d\n", m[arr[i]].fam, m[arr[i]].name, m[arr[i]].specialty);
            }
            delete[] arr;
            break;

        case 0:
            saveData(fp, m, filename, counter, newEl);
            freeMem(m, counter);
            exit(1);
            break;
        case -1:
            continue;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 0);
    return 0;
}