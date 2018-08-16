#pragma once

#include <string>
#include <fstream>

using namespace std;

class Product {
public:
	Product(int barcode, double price, string name, double tax, double discount);
	Product();

	void setBardcode(int barcode) { this->barcode = barcode; };
	void setPrice(double price) { this->price = price; };
	void setName(string name) { this->name = name; };
	void setTax(double tax) { this->tax = tax; };
	void setDiscount(double discount) { this->discount = discount; };

	int getBardcode() { return barcode; };
	double getprice() { return price; };
	string getName() { return name; };
	double getTax() { return tax; };
	double getDiscount() { return discount; };

	// Outputs data to the file
	void update(ofstream &fout);
protected:
	int barcode;
	double price, tax, discount;
	string name;
};