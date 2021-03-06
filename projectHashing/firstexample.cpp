// Local headers
#include "firstexample.h"
#include "textuserinterface.h"
// Standard library headers
#include <iostream>
#include <vector>
// Global data structures
// Test data
std::vector<std::string> shortUniqueNames;
// Hash table
std::string simpleHashTable[300];
// Function implimentations
int findInHashTable () {
	// 09-04-2022 17.45
	int appAction;
	std::string threeLetterName;
	std::string result;
	int hashValue;
	//
	appAction = 0;
	threeLetterName = "###";
	result = "***";
	hashValue = 0;
	//
	appAction = TextUserInterface::writeSelectionHighlighter();
	std::cout << "Enter three letter name: ";
	std::cin >> threeLetterName;
	//
	hashValue = simpleHashFunction(threeLetterName);
	if (hashValue > 299) {
		std::cout << "Out of range" << std::endl;
		result = "###";
	}
	else {
		result = simpleHashTable[hashValue];
	}
	//
	if (result == "***") {
		std::cout << "Not found" << std::endl;
	}
	else {
		std::cout << "Name found on position: " << hashValue << std::endl;
	}
	//
	appAction = TextUserInterface::writeSelectionHighlighter();
	appAction = TextUserInterface::writeActionSeperator();
	return 0;
}
int printHashTable() {
	// 08-04-2022 09.59
	int appAction;
	appAction = 0;
	appAction = TextUserInterface::writeSelectionHighlighter();
	for (int i = 0; i < 300; i++) {
		if (i < 10) { std::cout << "0"; }
		if (i < 100) { std::cout << "0"; }
		std::cout << i << ":" << simpleHashTable[i] << std::endl;
	}
	//
	appAction = TextUserInterface::writeSelectionHighlighter();
	appAction = TextUserInterface::writeActionSeperator();
	return 0;
}
int simpleHashFunction(std::string activeName) {
	// 08-04-2022 09.39
	int result;
	result = 0;
	// Travers name
	for (int j = 0; j < 3; j++) {
		result = result + int(activeName[j]);
	}
	//
	return result;
}
int hashShortUniqueNames() {
	// 08-04-2022 09.02
	int appAction;
	int hashResult;
	std::string activeName;
	appAction = 0;
	hashResult = 0;
	activeName = "*";
	appAction = TextUserInterface::writeSelectionHighlighter();
	std::vector<std::string>::iterator i;
	for (i = shortUniqueNames.begin(); i < shortUniqueNames.end(); i++) {
		activeName = *i;
		hashResult = simpleHashFunction(activeName);
		std::cout << "Short name: " << activeName << " Result: " << hashResult << std::endl;
		// Place in hash table
		simpleHashTable[hashResult] = activeName;
	}
	//
	appAction = TextUserInterface::writeSelectionHighlighter();
	appAction = TextUserInterface::writeActionSeperator();
	return 0;
}
int initializeSimpleHashTable() {
	// 17-04-2022 09.34
	// Declarations
	int appAction;
	// Initializations
	appAction = 0;
	for (int i = 0; i < 300; i++) {
		simpleHashTable[i] = "***";
	}
	//
	appAction = TextUserInterface::writeSelectionHighlighter();
	std::cout << "Hash table initialized" << std::endl;
	appAction = TextUserInterface::writeSelectionHighlighter();
	appAction = TextUserInterface::writeActionSeperator();
	return 0;
}
int populateShortUniqueNames() {
	// 07-04-2022 11.28
	// Declarations
	int appAction;
	// Initializations
	appAction = 0;
	shortUniqueNames.push_back("Bea");
	shortUniqueNames.push_back("Clo");
	shortUniqueNames.push_back("Tim");
	shortUniqueNames.push_back("Hal");
	shortUniqueNames.push_back("Ned");
	shortUniqueNames.push_back("Zoe");
	shortUniqueNames.push_back("Ted");
	shortUniqueNames.push_back("Ada");
	shortUniqueNames.push_back("Sal");
	shortUniqueNames.push_back("Zed");
	//
	appAction = TextUserInterface::writeSelectionHighlighter();
	std::cout << "Testdata structure populated" << std::endl;
	appAction = TextUserInterface::writeSelectionHighlighter();
	appAction = TextUserInterface::writeActionSeperator();
	return 0;
}
// Options
int showFirstExampleOptions() {
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
int handleFirstExampleOptions() {
	// 08-04-2022 08.54
	int appAction = 0;
	int choise = 99;
	bool stop = false;
	// Operations 
	while (stop == false) {
		appAction = TextUserInterface::writeSubFunctionalityInformation("--First example--", "V.00.01");
		appAction = showFirstExampleOptions();
		appAction = TextUserInterface::writeActionSeperator();
		std::cout << "Enter choise: ";
		std::cin >> choise;
		// Handle text user interface
		appAction = TextUserInterface::writeActionSeperator();
		// Handle user input
		switch (choise) {
		case 1:
			appAction = populateShortUniqueNames();
			break;
		case 2:
			appAction = initializeSimpleHashTable();
			break;
		case 3:
			appAction = hashShortUniqueNames();
			break;
		case 4:
			appAction = printHashTable();
			break;
		case 5:
			appAction = findInHashTable();
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