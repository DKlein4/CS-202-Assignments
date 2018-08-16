#pragma once
#include "Employee.h"

class HourlyEmployee : public Employee {
private:
	char expert;
	double salary;
public:
	HourlyEmployee();

	char getExpertEmployee() const;
	double getSalary() const;

	bool setExpertEmployee(char exp);
	bool setSalary(double sal);

	// Returns the type of the employee
	virtual string getType() const;
	// Reads in all the necessary data
	virtual bool ReadData(istream& in);
	// Writes out all of the data
	virtual bool WriteData(ostream& out) const;
};