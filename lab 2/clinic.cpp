#include "clinic.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

const int maxLen = 64;
int clinic::count = 0;

clinic::clinic() {
    this->specialty = 0;
    this->fam = nullptr;
    this->name = nullptr;
    count++;
}

clinic::clinic(int specialty, const char* fam, const char* name) {
    this->specialty = specialty;
    this->fam = _strdup(fam);
    this->name = _strdup(name);
    count++;
}

clinic::clinic(const clinic& other) {
    this->fam = _strdup(other.fam);
    this->name = _strdup(other.name);
    this->specialty = other.specialty;
    count++;
}

clinic::~clinic() {
    delete[] this->fam;
    delete[] this->name;
    count--;
}

int clinic::getSpec() {
    return this->specialty;
}

char* clinic::getFam() {
    return _strdup(this->fam);
}

char* clinic::getName() {
    return _strdup(this->name);
}

void clinic::setFam(const char* fam) {
    delete[] this->fam;
    this->fam = _strdup(fam);
}

void clinic::setName(const char* name) {
    delete[] this->name;
    this->name = _strdup(name);
}

void clinic::setSpec(const int specialty) {
    this->specialty = specialty;
}

void clinic::printMedic() {
    cout << setw(20) << left << this->getFam() 
        << setw(20) << left << this->getName() 
        << setw(10) << left << this->getSpec() 
        << '\n';
}

int clinic::getCount() {
    return count;
}

clinic& clinic::operator=(const clinic& other) {
    if (this != &other) {
        delete[] fam;
        delete[] name;

        specialty = other.specialty;
        fam = _strdup(other.fam);
        name = _strdup(other.name);
    }
    return *this;
}

bool clinic::isSpec(int spec) {
    return this->getSpec() == spec;
}

bool clinic::isMedic(char* fam, char* name) {
    return strcmp(this->getFam(), fam) == 0 && strcmp(this->getName(), name) == 0;
}