#include <iostream>
#include "Student.h"

Student::Student(int ID, string fName, string lName) {
	if (ID > 0)
		studentID = ID;
	else
		studentID = -1;

	firstName = fName;
	lastName = lName;
}

Student::Student() {
	studentID = -1;
	firstName = "";
	lastName = "";
}

string Student::getFirstName() {
	return firstName;
}
string Student::getLastName() {
	return lastName;
}
int Student::getStudentID() {
	return studentID;
}

void Student::setFirstName(string fName) {
	firstName = fName;
}
void Student::setLastName(string lName) {
	lastName = lName;
}
void Student::setStudentID(int ID) {
	studentID = ID;
}

string Student::fullName() {
	return lastName + ", " + firstName;
}

bool Student::readData(istream &fin) {
	fin >> studentID >> firstName >> lastName;
	return (studentID != -1) && (firstName != "") && (lastName != "");
}

double Student::findAverage(int q1, int q2, int mid, int fin) {
	double quizAverage = ((q1 + q2) / 2) * 10;

	return (quizAverage*0.25) + (mid * 0.25) + (fin * 0.5);
}
