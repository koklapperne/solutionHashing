// Local headers
#include "linearprobing.h"

#include "textuserinterface.h"
// Standard library headers
#include <iostream>
#include <vector>
// Global data structures
// Test data
std::vector<person> testPersons;
// Hash table
// Maximum number of persons = 10
// Size of hash table + 30% = 15
person hashTable[15];
//
int linearProbing::populateTestPersons(){
	// 13-04-2022 10.38
	// Declarations
	int appAction;
	person newTestperson;
	// Initializations
	appAction = 0;
	// 0
	newTestperson.update("ABE", "Professor", 55);
	testPersons.push_back(newTestperson);
	// 1
	newTestperson.update("TIM", "Student", 21);
	testPersons.push_back(newTestperson);
	// 2
	newTestperson.update("ZOE", "Professor", 21);
	testPersons.push_back(newTestperson);
	// 3
	newTestperson.update("HAL", "Student", 21);
	testPersons.push_back(newTestperson);
	// 4
	newTestperson.update("SAL", "Student", 20);
	testPersons.push_back(newTestperson);
	// 5
	newTestperson.update("MIT", "Teacher", 35);
	testPersons.push_back(newTestperson);
	// 6
	newTestperson.update("ITM", "Student", 21);
	testPersons.push_back(newTestperson);
	// 7
	newTestperson.update("LEO", "Teacher", 32);
	testPersons.push_back(newTestperson);
	// 8
	newTestperson.update("ZED", "Student", 24);
	testPersons.push_back(newTestperson);
	// 9
	newTestperson.update("BEA", "Student", 21);
	testPersons.push_back(newTestperson);
	//
	appAction = TextUserInterface::writeSelectionHighlighter();
	std::cout << "Testdata structure populated" << std::endl;
	appAction = TextUserInterface::writeSelectionHighlighter();
	appAction = TextUserInterface::writeActionSeperator();
	return 0;
}
int linearProbing::initializeHashTable() {
	// 13-04-2022 10.48
	// Declarations
	int appAction;
	//
	appAction = TextUserInterface::writeSelectionHighlighter();
	std::cout << "Hash table initialized at declaration!" << std::endl;
	//
	appAction = TextUserInterface::writeSelectionHighlighter();
	appAction = TextUserInterface::writeActionSeperator();
	return 0;
}
int linearProbing::simpleHashFunction(std::string activeName) {
	// 17-04-2022 10.04
	int result;
	result = 0;
	// Travers name
	for (int j = 0; j < 3; j++) {
		result = result + int(activeName[j]);
	}
	// 
	// result = result / 10;
	result = result % 10;
	
	//
	return result;
}
int linearProbing::probe(int key, person probePerson) {
	// 17-04-2022 10.24
	// Declarations
	int i;
	// Initializations
	i=0;
	// If position is empty use it
	if (hashTable[key].returnName()=="***") {
		std::cout << " Position empty, use" << std::endl;
		hashTable[key] = probePerson;
	}
	else
	{
		// If position is not empty start a linear search for an empty position
		std::cout << " Position not empty, linear search" << std::endl;
		i = key;
		while (hashTable[i].returnName() != "***") {
			i++;

			if (key > 15){
				i = 0;
			}
		}
		std::cout << "New position found on: " << i << std::endl;
	}
	// 
	return 0;
}
int linearProbing::hashPersons() {
	// 13-04-2022 11.08
	// Declarations
	int appAction;
	int hashResult;
	int j;
	person activePerson;
	std::vector<person>::iterator i;
	// Initializations
	appAction = 0;
	j = 0;
	hashResult = 0;
	//
	appAction = TextUserInterface::writeSelectionHighlighter();
	for (i = testPersons.begin(); i < testPersons.end(); i++) {
		activePerson = *i;
		hashResult = simpleHashFunction(activePerson.returnName());
		if (j < 10) { std::cout << "0"; }
		//std::cout << j << " " << "Short name: " << activePerson.returnName() << " Result: " << hashResult << std::endl;
		std::cout << j << " " << "Short name: " << activePerson.returnName() << " Result: " << hashResult;
		j++;
		// Place in hash table
		appAction = probe(hashResult, activePerson);
	}
	//
	appAction = TextUserInterface::writeSelectionHighlighter();
	appAction = TextUserInterface::writeActionSeperator();
	return 0;
}
int linearProbing::printHashTable(){
	// 13-04-2022 11.13
	// Declarations
	
	int appAction;
	// Initializations
	appAction = 0;
	
	appAction = TextUserInterface::writeSelectionHighlighter();
	for (int i = 0; i < 15; i++) {
		if (i < 10) {
			std::cout << "0";
		}
		std::cout << i << " " << hashTable[i].returnName() << std::endl;
	}
	//
	appAction = TextUserInterface::writeSelectionHighlighter();
	appAction = TextUserInterface::writeActionSeperator();
	//
	return 0;
}
// Options
int linearProbing::showLinearProbingOptions() {
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
int linearProbing::handleLinearProbingOptions() {
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
			appAction = populateTestPersons();
			break;
		case 2:
			appAction = initializeHashTable();
			break;
		case 3:
			appAction = hashPersons();
			break;
		case 4:
			appAction = printHashTable();;
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