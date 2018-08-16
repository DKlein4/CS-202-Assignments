#include "Employee.h"

string Employee::getName() const
{
	return name;
}

string Employee::getID() const
{
	return ID;
}

void Employee::setName(const string n)
{
	name = n;
}

void Employee::setID(const string i)
{
	ID = i;
}

string Employee::getType() const
{
	return "Employee";
}

bool Employee::readData(istream & input)
{
	getline(input, name);
	input >> ID;

	return input.good();
}

bool Employee::writeData(ostream & output) const
{
	output << name << endl;
	output << ID << endl;

	return output.good();
}
