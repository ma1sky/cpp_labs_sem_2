#ifndef LETTER_H
#define LETTER_H
#include "fio.h"
#include <iostream>
#include <ostream>
#include <iomanip>

class letter {
private:
    fio FIO;
    char* address;
    static int count;

public:
    float price;
    letter();
    letter(const fio& FIO, const float price, const char* address);
    letter(const letter& other);
    ~letter();

    float getPrice();
    char* getAddr();
    fio getFIO();

    void setFIO(const char* fam, const char* name, const char* father);
    void setFIO(fio FIO);
    void setPrice(const float price);
    void setAddr(const char* addres);

    static int getCount();
    letter& operator=(const letter& other);
    bool operator==(const letter& other);
    bool operator<(const letter& other) const;

    bool operator>(const letter& other) const;

    friend ostream& operator<<(ostream& os, letter m);
    friend void sort(letter*& arr, int count);
};


#endif