#include "Student.h"
#include <iostream>
#include <string>

using namespace std;

Student::Student()
{
	ID = 0;
	numCourses = 0;
	firstName = "";
	lastName = "";
	courses = new Course[listSize];
}

Student::Student(int iID, string first, string last)
{
	ID = iID;
	numCourses = 0;
	firstName = first;
	lastName = last;
	courses = new Course[listSize];
}

Student::Student(Student & obj)
{
	ID = obj.getID();
	firstName = obj.getFirstName();
	lastName = obj.getLastName();
}

Student::~Student()
{
	delete[] courses;
	courses = NULL;
}

void Student::setID(int iID)
{
	ID = iID;
}

void Student::setFirstName(string first)
{
	firstName = first;
}

void Student::setLastName(string last)
{
	lastName = last;
}

int Student::getID()
{
	return ID;
}

int Student::getNumCourses()
{
	return numCourses;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

bool Student::isEnrolled(const string & CourseName)
{
	for (int i = 0; i < listSize; i++) {
		if (courses[i].name == CourseName && courses[i].grade == -1.0) {
			return true;
		}
	}

	return false;
}

bool Student::enroll(const Course &C, int index) 
{
	courses[index] = C;
	return courses[index].grade == -1.0;
}

bool Student::recordGrade(const Course &C)
{
	for (int i = 0; i < listSize; i++) {
		if (courses[i].name == C.name && (C.grade) >= 0 && (C.grade) <= 4) {
			cout << "Grade updated for " << ID << endl;
			courses[i].grade = C.grade;
			cout << "Course now inside the sudent: " << courses[i];
			return true;
		}
	}
	cout << "Grade not updated for " << ID << endl;
	return false;
}

int Student::hoursCompleted()
{
	int sum = 0;
	for (int i = 0; i < listSize; i++) {
		sum += courses[i].creditHours;
	}
	return sum;
}

float Student::GPA()
{
	int hours = 0;
	float gradePoints = 0;
	
	for (int i = 0; i < listSize; i++) {
		if (courses[i].grade != -1.0) {
			hours += courses[i].creditHours;
			gradePoints += courses[i].grade * courses[i].creditHours;
		}
	}
	return gradePoints / hours;
}

ostream & operator << (ostream & output, Course & course)
{
	output << course.name << "\t" << course.creditHours << "\t" << course.grade << endl;

	return output;
}

istream & operator >> (istream & input, Course & course)
{
	input >> course.name >> course.creditHours >> course.grade;

	return input;
}

ostream & operator << (ostream & output, Student & student)
{
	output << student.getID() << " " << student.getFirstName() << " " << student.getLastName() << endl;
	output << student.numCourses << endl;

	for (int i = 0; i < student.numCourses; i++) {
		output << student.courses[i];
		//cout << "Tried to output data for " << student.courses[i];
	}

	return output;
}

istream & operator >> (istream & input, Student & student)
{
	int id;
	string first, last;
	Course course;

	input >> id >> first >> last;
	student.setID(id);
	student.setFirstName(first);
	student.setLastName(last);
	input >> student.numCourses;

	for (int i = 0; i < student.numCourses; i++) {
		input >> course;
		student.enroll(course, i);
		//cout << "In input: " << course << " added to the student's class array" << endl;
	}

	return input;
}
