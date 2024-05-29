#include "date.h"

date::date() : day(0), year(0), month(0) {}

date::date(int day, int year, int month) : day(day), year(year), month(month) {}

date::date(const date& other) {
	this->day = other.day;
	this->year = other.year;
	this->month = other.month;
}

int date::getDay() { return this->day; }
int date::getYear() { return this->year; }
int date::getMonth() { return this->month; }

void date::setDay(int day) { this->day = day; }
void date::setYear(int year) { this->year = year; }
void date::setMonth(int month) { this->month = month; }

date& date::operator=(const date& other) {
	this->setDay(other.day);
	this->setMonth(other.month);
	this->setYear(other.year);
	return *this;
}

ostream& operator<<(ostream& os, date info)
{
	os << setw(20) << info.getDay()
		<< setw(20) << info.getMonth()
		<< setw(20) << info.getYear();
	return os;
}

istream& operator>>(istream& os, date& info) {
	int day, month, year;
	os >> day >> month >> year;
	date temp(day, month, year);
	info = temp;
	return os;
}

void date::save(ofstream& file) {
	file << this->getDay() << ' ' << this->getMonth() << ' ' << this->getYear();
}

bool date::operator==(date& other) {
	return (this->year == other.year && this->month == other.month && this->day == other.day) ? true : false;
}

bool date::operator<=(int num) {
	return (this->year <= num && this->month <= num && this->day <= num) ? true : false;
}

bool date::operator<(date& other) {
	if (this->year < other.year) {
		return true;
	}
	else if (this->year == other.year && this->month < other.month) {
		return true;
	}
	else if (this->year == other.year && this->month == other.month && this->day < other.day) {
		return true;
	}
	else {
		return false;
	}
}

bool date::operator>(date& other) {
	if (this->year > other.year) {
		return true;
	}
	else if (this->year == other.year && this->month > other.month) {
		return true;
	}
	else if (this->year == other.year && this->month == other.month && this->day > other.day) {
		return true;
	}
	else {
		return false;
	}
}