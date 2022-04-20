// Local headers
#include "textuserinterface.h"
#include "subfunctionality.h"
#include "firstexample.h"
#include "linearprobing.h"
#include "quadraticprobing.h"
// Standard library headers
#include <iostream>
// Application options
int showAppOptions() {
	// 20-04-2022 08.01
	int appAction = 0;
	std::cout << "1. First example" << std::endl;
	std::cout << "2. Linear probing" << std::endl;
	std::cout << "3. Qudratic probing" << std::endl;
	std::cout << "4. #" << std::endl;
	std::cout << "5. #" << std::endl;
	std::cout << "6. #" << std::endl;
	std::cout << "7. #" << std::endl;
	std::cout << "8. #" << std::endl;
	std::cout << "9. #" << std::endl;
	std::cout << "0. Exit" << std::endl;
	//
	return 0;
}
int handleAppOptions() {
	// 20-04-2022 08.01
	int appAction = 0;
	int choise = 99;
	bool stop = false;
	// Operations 
	appAction = TextUserInterface::writeActionSeperator();
	while (stop == false) {
		appAction = TextUserInterface::writeAppInformation("-- Hashing --", "V.00.01");
		appAction = showAppOptions();
		appAction = TextUserInterface::writeActionSeperator();
		std::cout << "Enter choise: ";
		std::cin >> choise;
		// Handle text user interface
		appAction = TextUserInterface::writeActionSeperator();
		// Handle user input
		switch (choise) {
		case 1:
			appAction = handleFirstExampleOptions();
			break;
		case 2:
			appAction = linearProbing::handleLinearProbingOptions();
			break;
		case 3:
			appAction = quadraticProbing::handleQuadraticProbingOptions();
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
// Application entry point
int main()
{
	// 05-04-2022 14.39
	// Declarations
	int appAction;
	// Initializations
	appAction = 0;
	// Assigning
	appAction = handleAppOptions();
	appAction = TextUserInterface::preventConsoleClose();
}
