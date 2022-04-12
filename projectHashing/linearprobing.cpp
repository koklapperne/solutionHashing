// Local headers
#include "linearprobing.h"
#include "person.h"
#include "textuserinterface.h"
// Standard library headers
#include <iostream>
#include <vector>
#include <string>
// Global data structures
// Test data
// std::vector<person> testPersons;
// Hash table
// Maximum number of persons = 10
// Size of hash table + 30% = 15
// person simpleHashTable[15];
// Options
int populateTestPersons(){
	// 12-04-2022 11.28
	
	//
	return 0;
}
int showLinearProbingOptions() {
	// 08-04-2022 08.54
	int appAction = 0;
	std::cout << "1. Populate test data structure" << std::endl;
	std::cout << "2. Initialize hash table" << std::endl;
	std::cout << "3. Hash" << std::endl;
	std::cout << "4. Print hash table" << std::endl;
	std::cout << "5. Find in hash table" << std::endl;
	std::cout << "6. #" << std::endl;
	std::cout << "7. #" << std::endl;
	std::cout << "8. #" << std::endl;
	std::cout << "9. #" << std::endl;
	std::cout << "0. Exit" << std::endl;
	//
	return 0;
}
int handleLinearProbingOptions() {
	// 08-04-2022 08.54
	// Colission resolution: Open addressing->Linear probing
	int appAction = 0;
	int choise = 99;
	bool stop = false;
	// Operations 
	while (stop == false) {
		appAction = TextUserInterface::writeSubFunctionalityInformation("--Linear Probing--", "V.00.01");
		appAction = showLinearProbingOptions();
		appAction = TextUserInterface::writeActionSeperator();
		std::cout << "Enter choise: ";
		std::cin >> choise;
		// Handle text user interface
		appAction = TextUserInterface::writeActionSeperator();
		// Handle user input
		switch (choise) {
		case 1:
			appAction = TextUserInterface::writeAppNoOption();
			break;
		case 2:
			appAction = TextUserInterface::writeAppNoOption();
			break;
		case 3:
			appAction = TextUserInterface::writeAppNoOption();
			break;
		case 4:
			appAction = TextUserInterface::writeAppNoOption();
			break;
		case 5:
			appAction = TextUserInterface::writeAppNoOption();
			break;
		case 6:
			appAction = TextUserInterface::writeAppNoOption();
			break;
		case 7:
			appAction = TextUserInterface::writeAppNoOption();
			break;
		case 8:
			appAction = TextUserInterface::writeAppNoOption();
			break;
		case 9:
			appAction = TextUserInterface::writeAppNoOption();
			break;
		case 0:
			stop = true;
			break;
		default:
			stop = true;
			break;

		}
	}
	//
	return 0;
}