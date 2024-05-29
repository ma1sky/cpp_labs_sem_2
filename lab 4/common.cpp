#include "common.h"
using namespace std;

const int maxLen = 64;

common::common() {
    this->FIO = { nullptr, nullptr, nullptr };
    this->price = 0;
    this->address = nullptr;
}

common::common(const fio& FIO, const float price, const char* address) : FIO(FIO), price(price), address(_strdup(address)){}

common::common(const common& other) : FIO(other.FIO), price(other.price), address(other.address) {}

common::~common() { delete[] this->address; }

fio common::getFIO() { return this->FIO; }

char* common::getAddr() { return _strdup(this->address); }

float common::getPrice() { return this->price; }

void common::setFIO(const char* fam, const char* name, const char* father) {
    this->FIO.setFam(fam);
    this->FIO.setName(name);
    this->FIO.setFather(father);
}

void common::setFIO(const fio FIO) { this->FIO = FIO; }

void common::setPrice(const float price) { this->price = price; }

void common::setAddr(const char* address) {
    delete[] this->address;
    this->address = _strdup(address);
}

common& common::operator=(const common& other) {
    if (this != &other) {
        delete[] this->address;

        this->FIO = other.FIO;
        this->price = other.price;
        this->address = _strdup(other.address);
    }
    return *this;
}

bool common::operator==(const common& other) {
    return (this->FIO == other.FIO && this->price == other.price && strcmp(this->address, other.address) == 0) ? true : false;
}

bool common::operator<(const common& other) { 
    return (this->price < other.price) ? true : false; 
}

ofstream& common::save(ofstream& file) {
    file << "/";
    this->getFIO().save(file);
    file << strlen(this->getAddr());
    file << this->getAddr()
        << this->getPrice();
    return file;
}
