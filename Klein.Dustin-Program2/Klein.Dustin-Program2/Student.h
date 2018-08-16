#pragma once

#include <string>

using namespace std;

class Student {
private:
	int studentID;
	string firstName, lastName;
public:
	Student(int ID, string fName, string lName);
	Student();

	string getFirstName();
	string getLastName();
	int getStudentID();

	void setFirstName(string fName);
	void setLastName(string lName);
	void setStudentID(int ID);

	string fullName();
	// Returns the full name in the format: 'LastName, FirstName'

	bool readData(istream &fin);
	// PreCondition: Info file with the students' information
	// PostCondition: Tries to read in the data of a student, if succesfull returns true otherwise returns false

	double findAverage(int q1, int q2, int mid, int fin);
	// PreCondition: The two quizes, midterm, and final of the student
	// PostCondition: Returns the wieghted average of those grades
};