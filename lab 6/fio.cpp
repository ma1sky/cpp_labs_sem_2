#include "fio.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

const int maxLen = 64;
int fio::count = 0;

fio::fio() : name(nullptr), fam(nullptr), father(nullptr) { count++; }

fio::fio(const char* fam, const char* name, const char* father) {
    this->fam = _strdup(fam);
    this->name = _strdup(name);
    this->father = _strdup(father);
    count++;
}

fio::fio(const fio& other) {
    this->fam = _strdup(other.fam);
    this->name = _strdup(other.name);
    this->father = _strdup(other.father);
    count++;
}

fio::~fio() {
    delete[] this->fam;
    delete[] this->name;
    delete[] this->father;
    count--;
}

char* fio::getFam() { return _strdup(this->fam); }
char* fio::getName() { return _strdup(this->name); }
char* fio::getFather() { return _strdup(this->father); }
void fio::setFam(const char* fam) {
    delete[] this->fam;
    this->fam = _strdup(fam);
}
void fio::setName(const char* name) {
    delete[] this->name;
    this->name = _strdup(name);
}
void fio::setFather(const char* father) {
    delete[] this->father;
    this->father = _strdup(father);
}
int fio::getCount() { return count; }

fio& fio::operator=(const fio& other) {
    if (this != &other) {
        delete[] fam;
        delete[] name;
        delete[] father;

        fam = _strdup(other.fam);
        name = _strdup(other.name);
        father = _strdup(other.father);
    }
    return *this;
}

bool fio::operator==(const fio& other) {
    if (strcmp(this->fam, other.fam) == 0 && strcmp(this->name, other.name) == 0 && strcmp(this->father, other.father) == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

void fio::save(ofstream& file) {
    file << strlen(this->getFam())
        << this->getFam()
        << strlen(this->getName())
        << this->getName()
        << strlen(this->getFather())
        << this->getFather();
}

ostream& operator<<(ostream& os, fio info) {
    os << setw(20) << left << info.getFam()
        << setw(20) << left << info.getName()
        << setw(20) << left << info.getFather();
    return os;
}