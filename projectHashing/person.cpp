#include "person.h"
// Data member function definitions
// Conctructors
person::person() {
	// 12-04-2022 13.47
	// Default constructor
	m_shortUniqueName = "***";
	m_occupation = "*";
	m_age = 0;
}
// Updating
int person::update(std::string newName, std::string newOccupation, int newAge) {
	// 12-04-2022 14.13
	m_shortUniqueName = newName;
	m_occupation = newOccupation;
	m_age = newAge;
	//
	return 0;
}
// Returning
std::string person::returnName() {
	// 13-04-2022 11.16
	std::string result;
	result = "*";
	if (m_shortUniqueName != "") {
		result = m_shortUniqueName;
	}
	//
	return result;
}

std::string person::returnOccupation() {
	// 13-04-2022 11.16
	std::string result;
	result = "*";
	if (m_occupation != "") {
		result = m_occupation;
	}
	//
	return result;
}

int person::returnAge() {
	// 13-04-2022 11.16
	int result;
	result = 0;
	if (m_age > 0) {
		result = m_age;
	}
	//
	return result;
}