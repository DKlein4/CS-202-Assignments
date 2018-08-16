#include <iostream>
#include <fstream>
#include <string>
#include "Product.h";

Product::Product(int barcode, double price, string name, double tax, double discount) {
	if (barcode < 0)
		this->barcode = 0;
	else
		this->barcode = barcode;

	this->price = price;
	this->name = name;
	this->tax = tax;
	this->discount = discount;
}

Product::Product() {
	barcode = 0;
	price = 0;
	name = "";
	tax = 0;
	discount = 0;
}

void Product::update(ofstream &fout) {

}