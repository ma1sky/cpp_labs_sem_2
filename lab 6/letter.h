#ifndef LETTER_H
#define LETTER_H
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include "common.h"
#include "date.h"
#include "fio.h"

const int maxLen = 64;

class letter : public common {
private:
    date delivDate;
    static int count;

public:
    letter();
    letter(const fio& FIO, const float price, const char* address, const date delivDate);
    letter(const letter& other);
    ~letter() override;

    static int getCount();
    date getDate();
    void setDate(const date& deliveryDate);
    ofstream& save(ofstream& file);

    friend ostream& operator<<(ostream& os, letter m);
    friend void sort(letter*& arr, int count);
};
#endif