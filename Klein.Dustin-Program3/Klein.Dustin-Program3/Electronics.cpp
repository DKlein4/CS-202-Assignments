#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "Electronics.h";

Electronics::Electronics(int warranty, int barcode, double price, string name, double tax, double discount) {
	Product(barcode, price, name, tax, discount);

	this->warranty = warranty;
}

Electronics::Electronics() {
	Product();

	warranty = 0;
}

bool Electronics::ReadData(ifstream &fin) {
	if (fin >> barcode >> name >> price)
		return true;
	else
		return false;
}

void Electronics::update(ofstream &fout) {

	fout << name << " with Barcode: " << barcode << " and price: " << price << endl;
	
	if (price < 200) {
		warranty = 1;
		fout << "Will have a " << warranty << " year warranty, and price after taxes = " << price + price*.09 << endl;
	}
	else if ((price >= 200) && (price <= 1000)) {
		warranty = 3;
		fout << "Will have a " << warranty << " year warranty, and price after taxes = " << price + price*.09 << endl;
		price += price*0.09;

		fout << name << " has 2 options for payment:" << endl;
		fout << "\t1- Cash full price" << endl;
		fout << "\t2-Pay over 12 months with a 1% interest of the price." << endl;
		double annuity = (price * (1.01)) / 12;
		fout << "\tSo you will need to pay " << annuity << " monthly" << endl;
	}
	else {
		warranty = 5;
		fout << "Will have a " << warranty << " year warranty, and price after taxes = " << price + price*.09 << endl;
		price += price*0.09;

		fout << name << " has 2 options for payment:" << endl;
		fout << "\t1- Cash full price" << endl;
		fout << "\t2-Pay over 24 months with a 1% interest of the price." << endl;
		double annuity = (price * pow(1.01, 2)) / 24;
		fout << "\tSo you will need to pay " << annuity << " monthly" << endl;
	}
	fout << "------------------------------------------------------------------------------" << endl;
}