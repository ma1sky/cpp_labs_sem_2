#pragma once
#include "common.h"
class delivery : public common {
private:
	float weight;
	float volume;
	static int count;
public:
	delivery();
	delivery(float weight, float volume, fio FIO, char* address, float price);
	delivery(delivery& other);
	~delivery() override;

	float getWeight();
	float getVolume();

	void setWeight(float weigth);
	void setVolume(float volume);
	ofstream& save(ofstream& file);
	delivery& operator=(const delivery& other);
	friend ostream& operator<<(ostream& os, delivery d);
};