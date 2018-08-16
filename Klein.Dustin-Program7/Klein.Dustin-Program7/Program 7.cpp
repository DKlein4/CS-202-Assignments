#include <string>	
#include <iostream>

#include "Queue.h"

using namespace std;

Queue newCars;
Queue oldCars;
Queue luxuryCars;

// Prints the main screen
void printMain();
// Prints the New Cars Screen
void printNewCars();
// Prints the Old Cars Screen
void printOldCars();
// Prints the Luxury Cars Screen
void printLuxuryCars();

void main() {
	printMain();
}

void printMain() {
	cout << "Welcome to Mercedes" << endl;
	cout << "1. New Cars" << endl;
	cout << "2. Old and Historical Cars" << endl;
	cout << "3. Luxury Cars" << endl;
	cout << "4. Exit" << endl;
	cout << "Please enter your choice: ";

	int choice;
	cin >> choice;

	system("CLS");

	if (choice == 1)
		printNewCars();
	else if (choice == 2)
		printOldCars();
	else if (choice == 3)
		printLuxuryCars();
	else if (choice == 4)
		exit(1);
}


void printNewCars() {
	cout << "Welcome to exhibition: New Cars" << endl;
	cout << "1. Add Car" << endl;
	cout << "2. Add VIP Car" << endl;
	cout << "3. Take Car to Auction" << endl;
	cout << "4. Cancel Car" << endl;
	cout << "5. List all currently queued cars" << endl;
	cout << "6. Exit back to the main menu" << endl;
	cout << "Please enter your choice: ";

	int choice;
	cin >> choice;

	system("CLS");


	if (choice == 1) {
		string name, model;
		int plate;

		cout << "Enter the name of the car: ";
		cin >> name;
		cout << "Enter the model of the car: ";
		cin >> model;
		cout << "Enter the plate number of the car: ";
		cin >> plate;

		newCars.addCar(name, model, plate);

		system("CLS");

		printNewCars();
	}
	else if (choice == 2) {
		string name, model;
		int plate;

		cout << "Enter the name of the car: ";
		cin >> name;
		cout << "Enter the model of the car: ";
		cin >> model;
		cout << "Enter the plate number of the car: ";
		cin >> plate;

		newCars.addCarVIP(name, model, plate);

		system("CLS");

		printNewCars();
	}
	else if (choice == 3) {
		newCars.removeForAuction();
		printNewCars();
	}
	else if (choice == 4) {
		string name, model;
		int plate;

		cout << "Enter the name of the car: ";
		cin >> name;
		cout << "Enter the model of the car: ";
		cin >> model;
		cout << "Enter the plate number of the car: ";
		cin >> plate;

		newCars.cancelCar(name, model, plate);

		system("CLS");

		printNewCars();
	}
	else if (choice == 5) {
		newCars.print();
		printNewCars();
	}
	else if (choice == 6) {
		printMain();
	}
}

void printOldCars() {
	cout << "Welcome to exhibition: Old Cars" << endl;
	cout << "1. Add Car" << endl;
	cout << "2. Add VIP Car" << endl;
	cout << "3. Take Car to Auction" << endl;
	cout << "4. Cancel Car" << endl;
	cout << "5. List all currently queued cars" << endl;
	cout << "6. Exit back to the main menu" << endl;
	cout << "Please enter your choice: ";

	int choice;
	cin >> choice;

	system("CLS");


	if (choice == 1) {
		string name, model;
		int plate;

		cout << "Enter the name of the car: ";
		cin >> name;
		cout << "Enter the model of the car: ";
		cin >> model;
		cout << "Enter the plate number of the car: ";
		cin >> plate;

		oldCars.addCar(name, model, plate);

		system("CLS");

		printOldCars();
	}
	else if (choice == 2) {
		string name, model;
		int plate;

		cout << "Enter the name of the car: ";
		cin >> name;
		cout << "Enter the model of the car: ";
		cin >> model;
		cout << "Enter the plate number of the car: ";
		cin >> plate;

		oldCars.addCarVIP(name, model, plate);

		system("CLS");

		printOldCars();
	}
	else if (choice == 3) {
		oldCars.removeForAuction();
		printOldCars();
	}
	else if (choice == 4) {
		string name, model;
		int plate;

		cout << "Enter the name of the car: ";
		cin >> name;
		cout << "Enter the model of the car: ";
		cin >> model;
		cout << "Enter the plate number of the car: ";
		cin >> plate;

		oldCars.cancelCar(name, model, plate);

		system("CLS");

		printOldCars();
	}
	else if (choice == 5) {
		oldCars.print();
		printOldCars();
	}
	else if (choice == 6) {
		printMain();
	}
}

void printLuxuryCars() {
	cout << "Welcome to exhibition: Luxury Cars" << endl;
	cout << "1. Add Car" << endl;
	cout << "2. Add VIP Car" << endl;
	cout << "3. Take Car to Auction" << endl;
	cout << "4. Cancel Car" << endl;
	cout << "5. List all currently queued cars" << endl;
	cout << "6. Exit back to the main menu" << endl;
	cout << "Please enter your choice: ";

	int choice;
	cin >> choice;

	system("CLS");


	if (choice == 1) {
		string name, model;
		int plate;

		cout << "Enter the name of the car: ";
		cin >> name;
		cout << "Enter the model of the car: ";
		cin >> model;
		cout << "Enter the plate number of the car: ";
		cin >> plate;

		luxuryCars.addCar(name, model, plate);

		system("CLS");

		printLuxuryCars();
	}
	else if (choice == 2) {
		string name, model;
		int plate;

		cout << "Enter the name of the car: ";
		cin >> name;
		cout << "Enter the model of the car: ";
		cin >> model;
		cout << "Enter the plate number of the car: ";
		cin >> plate;

		luxuryCars.addCarVIP(name, model, plate);

		system("CLS");

		printLuxuryCars();
	}
	else if (choice == 3) {
		luxuryCars.removeForAuction();
		printLuxuryCars();
	}
	else if (choice == 4) {
		string name, model;
		int plate;

		cout << "Enter the name of the car: ";
		cin >> name;
		cout << "Enter the model of the car: ";
		cin >> model;
		cout << "Enter the plate number of the car: ";
		cin >> plate;

		luxuryCars.cancelCar(name, model, plate);

		system("CLS");

		printLuxuryCars();
	}
	else if (choice == 5) {
		luxuryCars.print();
		printLuxuryCars();
	}
	else if (choice == 6) {
		printMain();
	}
}