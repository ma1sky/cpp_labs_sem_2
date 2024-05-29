#ifndef COMMON_H
#define COMMON_H
#include "fio.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
using namespace std;


class common {
protected:
    fio FIO;
    char* address;
    float price;

public:
    common();
    common(const fio& FIO, const float price, const char* address);
    common(const common& other);
    virtual ~common();

    float getPrice();
    char* getAddr();
    fio getFIO();

    void setFIO(const char* fam, const char* name, const char* father);
    void setFIO(const fio FIO);
    void setPrice(const float price);
    void setAddr(const char* addres);

    common& operator=(const common& other);
    bool operator==(const common& other);
    bool operator<(const common& other);

    virtual ofstream& save(ofstream& file);
};


#endif