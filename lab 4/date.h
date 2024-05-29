#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <fstream>
#include <istream>
#include <iomanip>
#include <ostream>

using namespace std;

class date
{
private:
	int month;
	int day;
	int year;
public:
	date();
	date(int day, int year, int month);
	date(const date& other);
	
	int getDay();
	int getYear();
	int getMonth();

	void setDay(int day);
	void setYear(int year);
	void setMonth(int month);
	void save(ofstream& file);

	date& operator=(const date& other);
	bool operator<(date& other);
	bool operator>(date& other);
	bool operator==(date& other);
	bool operator<=(int num);

	friend ostream& operator<<(ostream& os, date info);
	friend istream& operator>>(istream& os, date& info);
};

#endif