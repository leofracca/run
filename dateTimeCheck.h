#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

class Time {
public:
	void timeCreation(Time &, int, std::ofstream &);
	void setHour(int);
	void setMinute(int);
	void setSecond(int);
	int getHour();
	int getMinute();
	int getSecond();

private:
	int hour;
	int minute;
	int second;
};

class Date {
public:
	void dateCreation(Date &, std::ofstream &);
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	int getDay();
	int getMonth();
	int getYear();

private:
	int daysInMonth(int day, int month);
	bool isLeapYear(int year);
	int day;
	int month;
	int year;
};
