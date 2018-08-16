// Dustin Klein
// 3/5/2017

#include <iostream>
#include <fstream>
#include <string>
#include "Electronics.h";
#include "Food.h";

using namespace std;

void AccessFood(ifstream &fin, ofstream &fout);
// PreCondition - Takes in an input and an output file to use
// PostCondition - Reads in the data from the input file and correctly outputs it to the output file
void AccessElectronics(ifstream &fin, ofstream &fout);
// PreCondition - Takes in an input and an output file to use
// PostCondition - Reads in the data from the input file and correctly outputs it to the output file

void main() {
	bool continuePlaying = true;

	while (continuePlaying) {

		// Open the files
		ifstream efin, ffin;
		efin.open("Electronics.txt");
		ffin.open("Food.txt");

		ofstream fout;
		fout.open("Output.txt");

		// Check if the files opened correctly
		if (efin.fail() || ffin.fail() || fout.fail()) {
			cout << "Error opening the files";
			exit(1);
		}

		// Print instructions and get user's choice 
		int choice = -1;

		cout << "Welcome to our supermarket" << endl;
		cout << "Which department do you want to check?" << endl;
		cout << "1- Food" << endl;
		cout << "2- Electronics" << endl;
		cout << "3- Both" << endl;
		cout << "4- Exit" << endl;
		cout << "Enter your choice: " << endl;
		cin >> choice;

		// Make the correct action depending on the user's choice
		if (choice == 1)
			AccessFood(ffin, fout);
		else if (choice == 2)
			AccessElectronics(efin, fout);
		else if (choice == 3) {
			AccessFood(ffin, fout);
			AccessElectronics(efin, fout);
		}
		else
			exit(1);

		cout << "------------------------------------------------" << endl;

		// Check if the user would like to go again
		char continueChoice;

		cout << "Back to main menu? [y: yes | n: no]: ";
		cin >> continueChoice;

		continuePlaying = (continueChoice == 'y' || continueChoice == 'Y');

		// Close the files
		efin.close();
		ffin.close();
		fout.close();
	}
}

void AccessFood(ifstream &fin, ofstream &fout) {
	fout << "--------------------------------Food Inventory--------------------------------" << endl;
	Food food;

	while (food.ReadData(fin)) {
		food.update(fout);
	}
}

void AccessElectronics(ifstream &fin, ofstream &fout) {
	fout << "-----------------------------Electronics Inventory----------------------------" << endl;
	Electronics electronics;

	while (electronics.ReadData(fin)) {
		electronics.update(fout);
	}
}

