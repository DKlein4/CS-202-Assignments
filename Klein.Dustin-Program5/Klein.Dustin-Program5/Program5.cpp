#include <iostream>
#include <fstream>

#include <string>

#include "Employee.h"
#include "HourlyEmployee.h"
#include "MonthlyEmployee.h"

using namespace std;

void main() {
	// Open the files
	ifstream fin;
	ofstream fout;

	fin.open("input.txt");
	fout.open("output.txt");

	// Make sure the files opened correctly
	if (fin.fail() || fout.fail()) {
		cout << "Error opening files";
		exit(1);
	}

	// Store 100 employees
	Employee *emp[100];

	// Set all the pointers to null
	for (int i = 0; i < 100; i++)
		emp[i] = NULL;

	// Temp variables
	string employeeType;
	int count = 0;

	// Loop through the input file
	while (fin.good()) {
		fin >> employeeType;

		cout << "employee type in main: " << employeeType << endl;

		// If hourly employee
		if (employeeType == "H") {
			emp[count] = new HourlyEmployee();
			emp[count]->readData(fin);
			emp[count]->writeData(fout);
		}
		// If Monthly Employee
		else if (employeeType == "M") {
			emp[count] = new MonthlyEmployee();
			emp[count]->readData(fin);
			emp[count]->writeData(fout);
		}
		count++;
	}

	int numHourly = 0;
	int numMonthly = 0;

	// Find the number of each worker
	for (int i = 0; i < 100; i++) {
		if (emp[i]->getType() == "Hourly Employee")
			numHourly++;
		else if (emp[i]->getType() == "Monthly Employee")
			numMonthly++;
	}

	// Output the results
	cout << "Hourly Employees: " << numHourly << endl;
	cout << "Monthly Employees: " << numMonthly << endl;

	// Close the files
	fin.close();
	fout.close();
}