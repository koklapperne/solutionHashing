// Local headers
#include "quadraticprobing.h"
#include "textuserinterface.h"
// Standard library headers
//
#include "textuserinterface.h"
// Standard library headers
#include <iostream>
#include <vector>
// Global data structures
// Test data
std::vector<person> quadraticTestPersons;
// Hash table
// Maximum number of persons = 10
// Size of hash table: Maximum number of persons*10 = 100
person quadraticHashTable[100];
//
int quadraticProbing::populateTestPersons() {
	// 13-04-2022 10.38
	// Declarations
	int appAction;
	person newTestperson;
	// Initializations
	appAction = 0;
	// 0
	newTestperson.update("ABE", "Professor", 55);
	quadraticTestPersons.push_back(newTestperson);
	// 1
	newTestperson.update("TIM", "Student", 21);
	quadraticTestPersons.push_back(newTestperson);
	// 2
	newTestperson.update("ZOE", "Professor", 21);
	quadraticTestPersons.push_back(newTestperson);
	// 3
	newTestperson.update("HAL", "Student", 21);
	quadraticTestPersons.push_back(newTestperson);
	// 4
	newTestperson.update("SAL", "Student", 20);
	quadraticTestPersons.push_back(newTestperson);
	// 5
	newTestperson.update("MIT", "Teacher", 35);
	quadraticTestPersons.push_back(newTestperson);
	// 6
	newTestperson.update("ITM", "Student", 21);
	quadraticTestPersons.push_back(newTestperson);
	// 7
	newTestperson.update("LEO", "Teacher", 32);
	quadraticTestPersons.push_back(newTestperson);
	// 8
	newTestperson.update("ZED", "Student", 24);
	quadraticTestPersons.push_back(newTestperson);
	// 9
	newTestperson.update("BEA", "Student", 21);
	quadraticTestPersons.push_back(newTestperson);
	//
	appAction = TextUserInterface::writeSelectionHighlighter();
	std::cout << "Testdata structure populated" << std::endl;
	appAction = TextUserInterface::writeSelectionHighlighter();
	appAction = TextUserInterface::writeActionSeperator();
	return 0;
}
int quadraticProbing::initializeHashTable() {
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
int quadraticProbing::simpleHashFunction(std::string activeName) {
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
int quadraticProbing::probe(int key, person probePerson) {
	// 20-04-2022 09.08
	// Declarations
	int i;
	int j;
	int startKey;
	bool stopSearch;
	// Initializations
	i = 0;
	j = 0;
	startKey = 0;
	stopSearch = false;
	// If position is empty use it
	if (quadraticHashTable[key].returnName() == "***") {
		std::cout << " Position empty, use" << std::endl;
		quadraticHashTable[key] = probePerson;
	}
	else
	{
		// If position is not empty start a linear search for an empty position
		std::cout << " Position not empty, quadratic search" << std::endl;
		i = key;
		startKey = key;
		// Linear search of the rest of the array
		while (stopSearch == false) {
			i = i++;
			// Quadratic increment of the probe index
			// This is a start, but is not quite corect!
			j = (i * i);
			if (quadraticHashTable[j].returnName() == "***") {
				stopSearch = true;
				std::cout << "New position found on: " << j << std::endl;
				quadraticHashTable[j] = probePerson;
			}
			// Start from the beginning
			if (j > 100) { 
				std::cout << "Start from the beginning" << std::endl;
				i = 0;
				j = 0;
			}
			// Stop if whole array have been searched
			if (i == startKey) {
				stopSearch = true;
				std::cout << "No position found" << std::endl;
			}
		}

	}
	// 
	return 0;
}
int quadraticProbing::search(std::string activeName) {
	// 19-04-2022 08.03
	// Declarations
	int appAction;
	int i;
	int hashResult;
	int startKey;
	bool stopSearch;
	// Initializations
	appAction = 0;
	i = 0;
	hashResult = 0;
	startKey = 0;
	stopSearch = false;
	//
	hashResult = simpleHashFunction(activeName);
	startKey = hashResult;
	i = startKey;
	// Check position determined by hash function
	if (quadraticHashTable[hashResult].returnName() == activeName) {
		std::cout << "Succes! Person found on original position: " << hashResult << std::endl;
		stopSearch = true;
	}
	// If person is not on original position position start a linear search
	else {
		while (stopSearch == false) {
			i++;
			if (quadraticHashTable[i].returnName() == activeName) {
				stopSearch = true;
				std::cout << " Person found on position: " << i << std::endl;

			}
			// Start from the beginning
			if (i > 15) {
				i = 0;
			}
			// Stop if whole array have been searched, does not work! re think!
			if (i == startKey) {
				stopSearch = true;
				std::cout << "Person not found" << std::endl;
			}

		}
	}
	//
	return 0;
}
int quadraticProbing::searchPerson() {
	// 19-04-2022 08.36
	// Declarations
	int appAction;
	std::string findName;
	// Initializations
	appAction = 0;
	findName = "***";
	//
	appAction = TextUserInterface::writeSelectionHighlighter();
	std::cout << "Enter name: ";
	std::cin >> findName;
	appAction = search(findName);
	//
	appAction = TextUserInterface::writeSelectionHighlighter();
	appAction = TextUserInterface::writeActionSeperator();
	return 0;
}
int quadraticProbing::hashPersons() {
	// 20-04-2022 08.57
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
	for (i = quadraticTestPersons.begin(); i < quadraticTestPersons.end(); i++) {
		activePerson = *i;
		hashResult = simpleHashFunction(activePerson.returnName());
		if (j < 10) { std::cout << "0"; }
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
int quadraticProbing::printHashTable() {
	// 20-04-2022 08.30
	// Declarations
	int appAction;
	// Initializations
	appAction = 0;
	//
	appAction = TextUserInterface::writeSelectionHighlighter();
	for (int i = 0; i < 100; i++) {
		
		if (i < 10) {
			std::cout << "0";
		}
		std::cout << i << " " << quadraticHashTable[i].returnName() << std::endl;
	}
	//
	appAction = TextUserInterface::writeSelectionHighlighter();
	appAction = TextUserInterface::writeActionSeperator();
	//
	return 0;
}
// Options
int quadraticProbing::showQuadraticProbingOptions() {
	// 20-04-2022 07.40
	int appAction = 0;
	std::cout << "1. Populate test data structure" << std::endl;
	std::cout << "2. Initialize hash table" << std::endl;
	std::cout << "3. Hash" << std::endl;
	std::cout << "4. Search" << std::endl;
	std::cout << "5. Print hash table" << std::endl;
	std::cout << "6. #" << std::endl;
	std::cout << "7. #" << std::endl;
	std::cout << "8. #" << std::endl;
	std::cout << "9. #" << std::endl;
	std::cout << "0. Exit" << std::endl;
	//
	return 0;
}
int quadraticProbing::handleQuadraticProbingOptions() {
	// 20-04-2022 07.40
	// Colission resolution: Open addressing->Linear probing
	int appAction = 0;
	int choise = 99;
	bool stop = false;
	// Operations 
	while (stop == false) {
		appAction = TextUserInterface::writeSubFunctionalityInformation("--Quadratic Probing--", "V.00.01");
		appAction = showQuadraticProbingOptions();
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
			appAction = searchPerson();
			break;
		case 5:
			appAction = printHashTable();
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