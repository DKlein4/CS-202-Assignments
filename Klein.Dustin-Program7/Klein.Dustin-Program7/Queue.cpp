#include "Queue.h"

#include <iostream>

Car::Car()
{
	isVIP = false;
	next = NULL;
}

Car::Car(string nName, string nModel, int nPlateNum, bool VIP, Car* link)
{
	name = nName;
	model = nModel;
	plateNum = nPlateNum;
	isVIP = VIP;
	next = link;
}

// Prints one Car
void Car::printCar()
{
	cout << "Name: " << name << endl;
	cout << "Model: " << model << endl;
	cout << "Plate Number: " << plateNum << endl << endl;
}

Queue::Queue()
{
	Head = NULL;
	Tail = NULL;
	count = 0;
}

// Return the size of the queue
int Queue::size() const
{
	return count;
}

// Returns true if the queue is empty
bool Queue::isEmpty() const
{
	return count == 0;
}

// Adds a car to the queue
void Queue::addCar(string name, string model, int plateNum)
{
	if (isEmpty()) {
		Head = new Car(name, model, plateNum, false, NULL);
		Tail = Head;
	}
	else {
		Tail->next = new Car(name, model, plateNum, false, NULL);
		Tail = Tail->next;
	}
	count++;
}

// Add a VIP car to the queue
void Queue::addCarVIP(string name, string model, int plateNum)
{
	if (isEmpty()) {
		Head = new Car(name, model, plateNum, false, NULL);
		Tail = Head;
	}
	else {
		Tail->next = new Car(name, model, plateNum, false, NULL);
		Tail = Tail->next;
	}
	count++;
}

// Remove a specific car from the queue
void Queue::cancelCar(string name, string model, int plateNum)
{
	if (Head != NULL) {
		Car *p = Head;
		if (name == p->name && model == p->model && plateNum == p->plateNum) {
			Head = Head->next;
			delete p;
			count--;
		}
		else
		{
			while ((name == p->name && model == p->model && plateNum == p->plateNum) && (p->next != NULL))
			{
				p = p->next;
			}
			Car* target = p->next;
			if (target != NULL)
			{
				cout << "Car was removed from the auction: " << endl;
				target->printCar();
				system("pause");
				p->next = target->next;
				delete target;
				count--;
			}
			else {
				cout << "Car not found" << endl;
				system("pause");
			}
		}
	}
}

// Removes the first element from the queue
void Queue::removeForAuction()
{
	if (!isEmpty())
	{
		Car *temp = Head;
		Head = Head->next;

		if (Head == NULL) {
			Tail = Head;
		}

		system("CLS");
		temp->printCar();
		cout << "Was removed for auction" << endl;

		delete temp;
		count--;
	}
}

// Prints all of the elements in the queue
void Queue::print()
{
	Car *temp = Head;
	if (isEmpty()) {
		cout << "Queue is empty" << endl << endl;
	}
	else {
		while (temp != NULL) {
			temp->printCar();
			temp = temp->next;
		}
	}

}
