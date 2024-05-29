#include "letter.h"

using namespace std;

int letter::count = 0;

letter::letter() : common() {}

letter::letter(const fio& FIO, const float price, const char* address, date delivDate) : delivDate(delivDate), common(FIO, price, address)
{ count++; }

letter::letter(const letter& other) : common(other.FIO, other.price, other.address), delivDate(other.delivDate)
{ count++; }

letter::~letter() {
    count--;
}

date letter::getDate() { return this->delivDate; }

void letter::setDate(const date& delivDate) { this->delivDate = delivDate; }

ofstream& letter::save(ofstream& file) {
    common::save(file);
    this->delivDate.save(file);
    return file;
}

ostream& operator<<(ostream& os, letter m) {
    os << setw(20) << left << m.FIO
        << setw(20) << left << m.getAddr()
        << setw(20) << left << m.getPrice()
        << setw(20) << left << m.getDate();
    return os;
}

int letter::getCount() { return count; }

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