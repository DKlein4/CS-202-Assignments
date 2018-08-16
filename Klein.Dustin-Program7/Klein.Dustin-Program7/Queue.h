#pragma once

#include <string>

using namespace std;

struct Car{
	Car();
	Car(string nName, string nModel, int nPlateNum, bool VIP, Car *link);

	void printCar();

	string name;
	string model;
	int plateNum;

	bool isVIP;

	Car *next;
};

class Queue {
public:
	Queue();
	int size() const;
	bool isEmpty() const;
	void addCar(string name, string model, int plateNum);
	void addCarVIP(string name, string model, int plateNum);
	void cancelCar(string name, string model, int plateNum);
	void removeForAuction();
	void print();
private:	
	Car *Head;
	Car *Tail;
	int count;
};