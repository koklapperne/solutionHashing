#pragma once
// Standard libray headers
#include <string>
class person{
public:
	// Constructors
	person();
	// Updating
	int update(std::string newName, std::string newOccupation, int newAge);
	// Returning
	std::string returnName();
	std::string returnOccupation();
	int returnAge();
private:
	// Data members
	// This will be they key!
	std::string m_shortUniqueName;
	// Other private data members
	std::string m_occupation;
	int m_age;



};

