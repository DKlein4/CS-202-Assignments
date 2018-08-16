#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "Product.h";

class Food: public Product {
public:
	Food(string date_produced, int number_of_days, int barcode, double price, string name, double tax, double discount);
	Food();

	void setDateProduced(string date_produced) { this->date_produced = date_produced; };
	void setNumberOfDays(int number_of_days) { this->number_of_days = number_of_days; };

	string getDateProduced() { return date_produced; };
	int getNumberOfDays() { return number_of_days; };

	// Reads in one set of data from an input file
	bool ReadData(ifstream &fin);
	// Prints out the necessary info for a food item
	void update(ofstream &fout);
private:
	string date_produced;
	int number_of_days;
};