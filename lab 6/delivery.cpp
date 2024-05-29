#include "delivery.h"

int delivery::count = 0;

delivery::delivery() : common(), weight(0), volume(0)
{ count++; }

delivery::delivery(float weight, float volume, fio FIO, char* address, float price) :
	common(FIO, price, address),
    volume(volume), weight(weight)
{ count++; }

delivery::delivery(delivery& other) : 
	common(other.getFIO(), other.getPrice(), other.getAddr()),
	weight(other.getWeight()), volume(other.getVolume())
{ count++; }

delivery::~delivery() {
	count--;
}

float delivery::getWeight() { return this->weight; }
float delivery::getVolume() { return this->volume; }

void delivery::setWeight(float weight) { this->weight = weight; }
void delivery::setVolume(float volume) { this->volume = volume; }

delivery& delivery::operator=(const delivery& other) {
    if (this != &other) {
        delete[] this->address;

        this->FIO = other.FIO;
        this->price = other.price;
        this->weight = other.weight;
        this->volume = other.volume;
        this->address = _strdup(other.address);
    }
    return *this;
}

ostream& operator<<(ostream& os, delivery d) {
    os << setw(20) << left << d.FIO
        << setw(20) << left << d.getAddr()
        << setw(20) << left << d.getPrice()
        << setw(20) << left << d.getVolume()
        << setw(20) << left << d.getWeight();
    return os;
}

ofstream& delivery::save(ofstream& file) {
    common::save(file);
    file << this->getVolume() << ' '
        << this->getWeight();
	return file;
}