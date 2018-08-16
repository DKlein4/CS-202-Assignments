#include <iostream>
#include <fstream>
#include <string>
#include "Food.h";

Food::Food(string date_produced, int number_of_days, int barcode, double price, string name, double tax, double discount) {

	Product(barcode, price, name, tax, discount);

	this->date_produced = date_produced;
	this->number_of_days = number_of_days;
}

Food::Food() {
	Product();

	date_produced = "";
	number_of_days = 0;
}

bool Food::ReadData(ifstream &fin) {
	if (fin >> barcode >> name >> price >> date_produced >> number_of_days)
		return true;
	else
		return false;
}

void Food::update(ofstream &fout) {

	fout << name << " with Barcode:" << barcode << ":" << endl;
	fout << "It's Price = " << price << " and was produced on " << date_produced << endl;

	if (number_of_days < 10) {
		discount = 1;
		fout << name << " not on sale" << endl;
	}
	else if ((number_of_days >= 10) && (number_of_days <= 14)) {
		discount = 0.8;
		fout << name << " has 20% off, final price is " << price*discount << endl;
	}
	else if ((number_of_days >= 15) && (number_of_days <= 29)) {
		discount = 0.5;
		fout << name << " has 50% off, final price is " << price*discount << endl;
	}
	else {
		discount = 0.2;
		fout << name << " has 80% off, final price is " << price*discount << endl;
	}
	fout << "------------------------------------------------------------------------------" << endl;
}