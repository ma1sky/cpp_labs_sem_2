#ifndef LETTER_H
#define LETTER_H
#include "fio.h"

class letter {
private:
    fio FIO;
    float price;
    char* address;
    static int count;

public:
    letter();
    letter(const fio& FIO, const float price, const char* address);
    letter(const letter& other);
    ~letter();
    /*
    char* getFam();
    char* getName();
    char* getFather();
    */
    float getPrice();
    char* getAddr();
    fio getFIO();

    void setFIO(const char* fam, const char* name, const char* father);
    void setPrice(const float price);
    void setAddr(const char* addres);

    void printLetter();

    static int getCount();
    letter& operator=(const letter& other);
    bool operator==(const letter& other);
    friend ostream& operator<<(ostream& os, letter& m);
};


#endif


