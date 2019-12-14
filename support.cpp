//#include <iostream>
#include "support.h"

int sectors() {
	static char sector;
	static int n_sectors;

	std::cout << "Did you divide your run in sectors? [y/n]: ";
	std::cin >> sector;

	// if the answer is YES, how many they are?
	if(sector == 'y' || sector == 'Y') {
		n_sectors = numberOfSectors(n_sectors);
		return n_sectors;
	}

	else if(sector == 'n' || sector == 'N')
		return 0;
		
	else
		std::cout << "You can answer only 'y' or 'n'\n";

	return sectors();
}

int numberOfSectors(int n_sectors) {
	do {
		std::cout << "How many? ";
		std::cin >> n_sectors;
		if(n_sectors <= 0)
			printf("The number of the sectors must be greater than 0.\n");
	}
	while(n_sectors <= 0);

	return n_sectors;
}

void drawLine(std::ofstream &Times) {
	Times << "--------------------------------------------------------------\n";
}

bool newEntry() {
	static char answer;

	std::cout << "Do you want continue? [y/n]: ";
	std::cin >> answer;

	if(answer == 'y' || answer == 'Y')
		return true;

	else if(answer == 'n' || answer == 'N')
		return false;
			
	else
		std::cout << "You can answer only 'y' or 'n'\n";

	return newEntry();
}
