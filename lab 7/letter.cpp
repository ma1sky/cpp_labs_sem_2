#include "letter.h"

using namespace std;

const int maxLen = 64;
int letter::count = 0;

letter::letter() : price(0), address(nullptr), FIO(nullptr, nullptr, nullptr) { count++; }

letter::letter(const fio& FIO, const float price, const char* address) : FIO(FIO), price(price), address(_strdup(address)) { count++; }

letter::letter(const letter& other) : FIO(other.FIO), price(other.price), address(nullptr) {
    if (other.address != nullptr) {
        this->address = _strdup(other.address);
    }
    count++;
}

letter::~letter() {
    delete[] this->address;
    count--;
}

fio letter::getFIO() { return this->FIO; }

char* letter::getAddr() { return _strdup(this->address); }

float letter::getPrice() { return this->price; }

void letter::setFIO(const char* fam, const char* name, const char* father) {
    this->FIO.setFam(fam);
    this->FIO.setName(name);
    this->FIO.setFather(father);
}

void letter::setFIO(fio FIO) { this->FIO = FIO; }

void letter::setAddr(const char* address) {
    delete[] this->address;
    this->address = _strdup(address);
}

void letter::setPrice(const float price) {
    this->price = price;
}

ostream& operator<<(ostream& os, letter m) {
    os << setw(20) << left << m.getFIO()
        << setw(20) << left << m.getAddr()
        << setw(20) << left << m.getPrice();
    return os;
}

int letter::getCount() {
    return count;
}

letter& letter::operator=(const letter& other) {
    if (this != &other) {
        if (this->address != nullptr){
            delete[] this->address;
        }

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

bool letter::operator<(const letter& other) const
{
    return this->price < other.price;
}

bool letter::operator>(const letter& other) const 
{
    return this->FIO > other.FIO;
}

void sort(letter*& arr, int count) {
    bool swapped;
    letter buff;
    for (int i = 0; i < count - 1; i++) {
        swapped = false;
        for (int j = 0; j < count - i - 1; j++) {
            if (arr[j + 1] < arr[j]) {
                buff = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = buff;
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}