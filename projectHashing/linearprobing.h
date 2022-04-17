#pragma once
// Local headers
#include "person.h"
// Standard library headers
#include <string>
// Function declarations
namespace linearProbing{
	int populateTestPersons();
	int initializeHashTable();
	int simpleHashFunction(std::string activeName);
	int probe(int key, person probePerson);
	int hashPersons();
	int printHashTable();
//
	int showLinearProbingOptions();
	int handleLinearProbingOptions();
}