#include "person.h"
// Data member function definitions
person::person() {
	// 12-04-2022 13.47
	// Default constructor
	m_shortUniqueName = "*";
	m_occupation = "*";
	m_age = 0;
}
int person::update(std::string newName, std::string newOccupation, int newAge) {
	// 12-04-2022 14.13
	m_shortUniqueName = newName;
	m_occupation = newOccupation;
	m_age = newAge;
	//
	return 0;
}