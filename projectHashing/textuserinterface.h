#pragma once
// Standard library headers
#include <string>
namespace TextUserInterface {
	// 05-04-2022 14.00
	int writeActionSeperator();
	int writeSelectionHighlighter();
	int writeAppInformation(std::string appTitle, std::string appVersion);
	int writeSubFunctionalityInformation(std::string appTitle, std::string appVersion);
	int writeSelectedOption(std::string selectedOption);
	int writeAppNoOption();
	int preventConsoleClose();
	int pauseApplication();
	int handleBlanks();
	int handleColors();
}