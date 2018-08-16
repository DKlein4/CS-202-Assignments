#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "Product.h";

class Electronics : public Product {
public:
	Electronics(int warranty, int barcode, double price, string name, double tax, double discount);
	Electronics();

	void setWarranty(int warranty) { this->warranty = warranty; };
	int getWarranty() { return warranty; };

	// Reads in one set of data from an input file
	bool ReadData(ifstream &fin);
	// Prints out the necessary info for an electronic item
	void update(ofstream &fout);
private:
	int warranty;
};