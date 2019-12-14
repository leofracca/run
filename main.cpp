/* This program allows you to manage your times when you run.
* It asks you if you divide your run in sectors and then the times for each one.
* That's it.
* Then the program does the rest.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "dateTimeCheck.h"
#include "support.h"

int main() {

	std::string name;
	
	std::cout << "Digit the name of the file: ";
	std::getline(std::cin, name);

	std::ofstream Times(name, std::ios::app);
	if (!Times) {
		std::cerr << "File could not be opened" << std::endl;
		exit(1);
	}

	Time time;
	Date date;

	do {
		int n_sectors = sectors();

		/////// TIME ///////
		time.timeCreation(time, n_sectors, Times);

		/////// DATE ///////
		date.dateCreation(date, Times);

		drawLine(Times);
	}
	while(newEntry());
	
	return 0;
}
