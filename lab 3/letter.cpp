#include "letter.h"
#include "letter.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

const int maxLen = 64;
int letter::count = 0;

letter::letter() {
    this->FIO = {nullptr, nullptr, nullptr};
    this->price = 0;
    this->address = nullptr;
    count++;
}

letter::letter(const fio& FIO, const float price, const char* address) {
    this->FIO = FIO;
    this->price = price;
    this->address = _strdup(address);
    count++;
}

letter::letter(const letter& other) {
    this->FIO = other.FIO;
    this->price = other.price;
    this->address = other.address;
    count++;
}

letter::~letter() {
    delete[] this->address;
    count--;
}

fio letter::getFIO() {
    fio res = this->FIO;
    return res;
}

/*
char* letter::getFam() {
    return _strdup(this->FIO.getFam());
}

char* letter::getName() {
    return _strdup(this->FIO.getName());
}

char* letter::getFather() {
    return _strdup(this->FIO.getFather());
}
*/

char* letter::getAddr() {
    return _strdup(this->address);
}

float letter::getPrice() {
    return this->price;
}

void letter::setFIO(const char* fam, const char* name, const char* father) {
    this->FIO.setFam(fam);
    this->FIO.setName(name);
    this->FIO.setFather(father);
}

void letter::setFIO(fio FIO) {
    this->FIO = FIO;
}

void letter::setAddr(const char* address) {
    delete[] this->address;
    this->address = _strdup(address);
}

void letter::setPrice(const float price) {
    this->price = price;
}

void letter::printLetter() {
    cout << setw(20) << left << this->getAddr()
        << setw(20) << left << this->getPrice()
        << setw(20) << left << this->FIO.getFam()
        << setw(20) << left << this->FIO.getName()
        << setw(20) << left << this->FIO.getFather()
        << '\n';
}

int letter::getCount() {
    return count;
}

letter& letter::operator=(const letter& other) {
    if (this != &other) {
        delete[] this->address;

        this->FIO = other.FIO;
        this->price = other.price;
        this->address = _strdup(other.address);
    }
    return *this;
}

bool letter::operator==(const letter& other) {
    if (this->FIO == other.FIO && this->price == other.price && strcmp(this->address, other.address) == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

bool letter::operator<(const letter& other)
{
    if (this->price < other.price) {
        return 1;
    } else {
        return 0;
    }
}

//ostream& operator<<(ostream& os, letter& m)
//{
//    os << left << setw(20) << m.getFIO().getFam() << '\n'
//        << left << setw(20) << m.getFIO().getName() << '\n'
//        << left << setw(20) << m.getFIO().getFather() << '\n'
//        << left << setw(20) << m.getPrice() << '\n'
//        << left << setw(20) << m.getAddr() << endl;
//    return os;
//}

void sort(letter*& arr, int count) {
    bool swapped;
    for (int i = 0; i < count - 1; i++) {
        swapped = false;
        for (int j = 0; j < count - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}