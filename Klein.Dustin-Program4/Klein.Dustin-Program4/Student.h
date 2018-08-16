#pragma once
#include <string>

using namespace std;

struct Course
{
	string name = "";
	int creditHours = 0;
	float grade = -1.0;

	friend ostream &operator << (ostream &output, Course & course);
	friend istream &operator >> (istream &input, Course & course);
};

class Student {
private:
	int ID, numCourses;
	int listSize = 100;
	string firstName, lastName;
	Course *courses;

public:
	// Constructors and destructor
	Student();
	Student(int iID, string first, string last);
	Student(Student &obj);
	~Student();

	// Overloaded operators
	friend ostream &operator << (ostream &output, Student &student);
	friend istream &operator >> (istream &input, Student & student);

	// Setters
	void setID(int iID);
	void setFirstName(string first);
	void setLastName(string last);

	// Getters
	int getID();
	int getNumCourses();
	string getFirstName();
	string getLastName();

	// Returns true if the student is enrolled in the course
	bool isEnrolled(const string &CourseName);
	// Adds the course to the student's courses
	bool enroll(const Course &C, int index);
	// Updates the grade on a course if it is valid
	bool recordGrade(const Course &C);
	// Returns the total hours taken
	int hoursCompleted();
	// Returns the GPA of all courses
	float GPA();
};

