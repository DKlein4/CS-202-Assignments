#pragma once
#include "Employee.h"

class MonthlyEmployee : public Employee {
private:
	int rank;
public:
	MonthlyEmployee(string n, string i, int r);
	MonthlyEmployee();

	int getRank() const;
	void setRank(int r);

	// Returns the type of the employee
	virtual string getType() const;
	// Reads in all the necessary data
	virtual bool ReadData(istream& in);
	// Writes out all of the data
	virtual bool WriteData(ostream& out) const;
};