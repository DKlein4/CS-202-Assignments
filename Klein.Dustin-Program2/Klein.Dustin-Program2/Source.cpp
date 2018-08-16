#include <fstream>
#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

void printIntro();
// PostCondition: Prints out the initial instructions

void printRoster(ifstream &info, Student students[20]);
// PreCondtion: Takes in the info file and the array of students to hold each students' information
// PostCondition: Prints each student's name and ID from the file with the correct output

void printRosterGrades(ifstream &info, ifstream &grades, Student students[20]);
// PreCondtion: Takes in the info and grades files and the array of students to hold each students' information
// PostCondition: Prints each student from the file along with their grades if they have any

void printRosterAverage(ifstream &info, ifstream &grades, Student students[20]);
// PreCondtion: Takes in the info and grades files and the array of students to hold each students' information
// PostCondition: Prints each student from the file along with their weighted average if they have any grades

void main() {

	int choice;
	Student students[20];
	bool continuePlaying = true;

	// Loop to replay if the user chooses
	while (continuePlaying) {

		// Open the files
		ifstream info;
		ifstream grades;
		info.open("INFO.txt");
		grades.open("Grades.txt");

		// Check if the files opened
		if (!info) {
			cout << "Error opening file" << endl;
			exit(1);
		}
		if (!grades) {
			cout << "Error opening file" << endl;
			exit(1);
		}

		// Print intro and get the user's choice
		printIntro();
		cin >> choice;

		// Choose the correct action depending on the user's choice
		if (choice == 1) {
			printRoster(info, students);
		}
		else if (choice == 2) {
			printRosterGrades(info, grades, students);
		}
		else if (choice == 3) {
			printRosterAverage(info, grades, students);
		}
		else if (choice == 4) {
			exit(1);
		}

		// Check if the user would like to go again
		char play;
		cout << endl << "Back to the main menu? [y:yes | n:no]: ";
		cin >> play;

		if (play != 'y' && play != 'Y') {
			continuePlaying = false;
		}
	}
	
	
	system("pause");
}

void printIntro() {
	cout << endl << "Welcome to the Weighted Average Application" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "Please make a selection:" << endl;
	cout << "(1) Print class roster" << endl;
	cout << "(2) Print class roster with their grades" << endl;
	cout << "(3) Print class roster with students' wighted total" << endl;
	cout << "(4) Exit" << endl;
	cout << "Enter your choice: ";
}

void printRoster(ifstream &info, Student students[20]) {
	int count = 0;
	int length = 0;

	// Read each student from the file
	while (info.good()) {
		if (students[count].readData(info)) {
			length++;
		}
		count++;
	}

	cout << endl << "Reading File....  The class has " << length << " students." << endl;

	// Print out the student's ID and full name
	for (int i = 0; i < length; i++) {
		cout << students[i].getStudentID() << "  " << students[i].fullName() << endl;
	}
}

void printRosterGrades(ifstream &info, ifstream &grades, Student students[20]) {
	int count = 0;
	int length = 0;

	// Read each student from the file
	while (info.good()) {
		if (students[count].readData(info)) {
			length++;
		}
		count++;
	}

	cout << endl << "Reading the grades file..." << endl;

	int tempID, q1, q2, mid, fin;
	
	// Read through the grades file
	for (int i = 0; i < length; i++) {
		grades >> tempID >> q1 >> q2 >> mid >> fin;
		
		// If a student has an ID on the grade sheet, print out the grades
		for (int j = 0; j < length; j++) {
			if (tempID == students[j].getStudentID()) {
				cout << students[j].fullName() << ": \t" << q1 << " " << q2 << " " << mid << " " << fin << endl;
			}
		}
		tempID = 0;
	}
}

void printRosterAverage(ifstream &info, ifstream &grades, Student students[20]) {
	int count = 0;
	int length = 0;
	int tempID, q1, q2, mid, fin;
	double average;

	// Read each student from the file
	while (info.good()) {
		if (students[count].readData(info)) {
			length++;
		}
		count++;
	}

	// Read through the grades file
	for (int i = 0; i < length; i++) {
		grades >> tempID >> q1 >> q2 >> mid >> fin;

		// If a student has an ID on the grade sheet, calculate their wieghted average and print it out
		for (int j = 0; j < length; j++) {
			if (tempID == students[j].getStudentID()) {
				average = students[j].findAverage(q1, q2, mid, fin);
				cout << "Weighted average score of " << students[j].fullName() << "\tis " << average << "\tout of 100%" << endl;
			}
		}
		tempID = 0;
	}
}