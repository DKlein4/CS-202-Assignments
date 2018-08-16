#include "MonthlyEmployee.h"

MonthlyEmployee::MonthlyEmployee(string n, string i, int r)
{
	name = n;
	ID = i;
	rank = r;
}

MonthlyEmployee::MonthlyEmployee()
{
	rank = 10;
}

int MonthlyEmployee::getRank() const
{
	return rank;
}

void MonthlyEmployee::setRank(int r)
{
	if (rank >= 0 || rank <= 10)
		rank = r;
}

string MonthlyEmployee::getType() const
{
	return "Monthly Employee";
}

bool MonthlyEmployee::ReadData(istream & in)
{
	Employee::readData(in);
	in >> rank;

	return in.good();
}

bool MonthlyEmployee::WriteData(ostream & out) const
{
	Employee::writeData(out);
	out << rank << endl;

	return out.good();
}
