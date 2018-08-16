#pragma once
#include <string>

using namespace std;

class Employee {
protected:
	string name;
	string ID;
public:
	string getName() const;
	string getID() const;

	void setName(const string n);
	void setID(const string i) ;

	// Returns the type of the employee
	virtual string getType() const;
	// Reads in all the necessary data
	virtual bool readData(istream& input);
	// Writes out all of the data
	virtual bool writeData(ostream& output) const;
};