#include "Student.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void main() {
	// Open the files
	ifstream cfin, sfin;
	ofstream sfout, gfout;

	cfin.open("courses.txt");
	sfin.open("students.txt");
	sfout.open("New Students.txt");
	gfout.open("GPA.txt");


	// Check that the files opened correctly
	if (cfin.fail() || sfin.fail() || sfout.fail() || gfout.fail()) {
		cout << "Error opening the files";
		exit(1);
	}


	//Array to hold all of the students
	Student *students = new Student[1000];
	int index = 0;

	// Read in all the students into the array
	while (sfin.good()) {
		sfin >> students[index];

		index++;
	}
		

	// Variables used to update grades
	int id;
	Course temp;
	bool validID = false;

	// Go trough the course file and update all of the valid grades
	while (cfin.good())
	{
		// Read in the id and course
		cfin >> id >> temp;

		// Check if the id is valid
		for (int i = 0; i < index; i++) {
			if (students[i].getID() == id) {
				cout << "Match found for id " << id << endl;
				validID = true;

				// Check if they are enrolled in the class
				if (students[i].isEnrolled(temp.name)) {
					cout << id << " is enrolled in " << temp.name << endl;
					students[i].recordGrade(temp);
				}
				else {
					cout << id << " is not enrolled in " << temp.name << endl;
				}
			}
		}

		// If not output warning message
		if (!validID) {
			cout << id << " was not valid with any student" << endl;
		}
		cout << endl;
	}


	// Output the students to the new file
	for (int i = 0; i < index; i++) {
		sfout << students[i];
	}


	// Output the GPA file
	for (int i = 0; i < index - 1; i++) {
		gfout << students[i].getLastName() << ", " << students[i].getFirstName() << "\t" << students[i].GPA() << endl;
	}


	// Close the files
	cfin.close();
	sfin.close();
	sfout.close();
	gfout.close();
}