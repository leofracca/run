#include "dateTimeCheck.h"

/////// TIME ///////
void Time::timeCreation(Time &time, int n_sectors, std::ofstream &Times) {
	int h, m, s;	// hours, minutes, seconds

	std::cout << "Insert the time" << std::endl;
	if(n_sectors == 0) {
		do {
			std::cout << "Hours: ";
			std::cin >> h;
			time.setHour(h);
		}
		while(h < 0);
			
		do {
			std::cout << "Minute: ";
			std::cin >> m;
			time.setMinute(m);
		}
		while(!(m >= 0 && m <= 59));

		do {
			std::cout << "Seconds: ";
			std::cin >> s;
			time.setSecond(s);
		}
		while(!(s >= 0 && s <= 59));

		Times << "Time: " << std::setfill('0') << std::setw(2) << time.getHour() << ":" <<
			std::setw(2) << time.getMinute() << ":" <<
			std::setw(2) << time.getSecond() << "\t\t\t\t";
	}
	else {
		for(int i = 1; i <= n_sectors; i++) {
			std::cout << "Sector number " << i << "\n";
			do {
				std::cout << "Hours: ";
				std::cin >> h;
				time.setHour(h);
			}
			while(h < 0);
				
			do {
				std::cout << "Minute: ";
				std::cin >> m;
				time.setMinute(m);
			}
			while(!(m >= 0 && m <= 59));

			do {
				std::cout << "Seconds: ";
				std::cin >> s;
				time.setSecond(s);
			}
			while(!(s >= 0 && s <= 59));

			Times << "Sector " << i << " time: " << std::setfill('0') << std::setw(2) << time.getHour() << ":" <<
					std::setw(2) << time.getMinute() << ":" <<
					std::setw(2) << time.getSecond();
			if(i == n_sectors)
				Times << "\t\t";
			else
				Times << "\n";
		}
	}
}

void Time::setHour(int h) {
	if(h >= 0)
		hour = h;
	else
		std::cout << "Hours cannot be negative\n";
}

void Time::setMinute(int m) {
	if(m >= 0 && m <= 59)
		minute = m;
	else
		std::cout << "Minutes was out of range\n";
}

void Time::setSecond(int s) {
	if(s >= 0 && s <= 59)
		second = s;
	else
		std::cout << "Seconds was out of range\n";
}

int Time::getHour() {
	return hour;
}

int Time::getMinute() {
	return minute;
}

int Time::getSecond() {
	return second;
}


/////// DATE ///////
void Date::dateCreation(Date &date, std::ofstream &Times) {
	int d, mo, y;	// day, month, year

	std::cout << "Insert the date" << std::endl;

	do {
		std::cout << "Year: ";
		std::cin >> y;
		date.setYear(y);
	}
	while(y < 0);

	do {
		std::cout << "Month: ";
		std::cin >> mo;
		date.setMonth(mo);
	}
	while(!(mo >= 1 && mo <= 12));
		
	do {
		std::cout << "Day: ";
		std::cin >> d;
		date.setDay(d);
	}
	while(d <= 0 || date.daysInMonth(y, mo) < d);

	Times << "Date: " << std::setfill('0') << std::setw(2) << date.getMonth() << "/" <<
		std::setw(2) << date.getDay() << "/" <<
		date.getYear() << std::endl;
}

void Date::setDay(int d) {
	if(d > 0 && (daysInMonth(getYear(), getMonth()) >= d))
		day = d;
	else
		std::cout << "Day is not in this month\n";
}

void Date::setMonth(int mo) {
	if(mo >= 1 && mo <= 12)
		month = mo;
	else
		std::cout << "Month was out of range\n";
}

void Date::setYear(int y) {
	if(y > 0)
		year = y;
	else
		std::cout << "Year cannot be negative\n";
}

int Date::getDay() {
	return day;
}

int Date::getMonth() {
	return month;
}

int Date::getYear() {
	return year;
}

int Date::daysInMonth(int year, int month) {
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return 31;

	else if(month == 4 || month == 6 || month == 9 || month == 11)
		return 30;

	else {
		if(isLeapYear(year))
			return 29;
		else
			return 28;
	}
}

bool Date::isLeapYear(int year) {
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		return true;

	return false;
}
