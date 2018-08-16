#include "HourlyEmployee.h"

HourlyEmployee::HourlyEmployee()
{
	expert = 'F';
	salary = 0;
}

char HourlyEmployee::getExpertEmployee() const
{
	return expert;
}

double HourlyEmployee::getSalary() const
{
	return salary;
}

bool HourlyEmployee::setExpertEmployee(char exp)
{
	if (exp == 'F' || exp == 'T') {
		expert = exp;
		return true;
	}
	return false;
}

bool HourlyEmployee::setSalary(double sal)
{
	if (sal >= 1000 || sal <= 10000) {
		salary = sal;
		return true;
	}
	return false;
}

string HourlyEmployee::getType() const
{
	return "Hourly Employee";
}

bool HourlyEmployee::ReadData(istream & in)
{
	Employee::readData(in);
	in >> expert >> salary;

	return in.good();
}

bool HourlyEmployee::WriteData(ostream & out) const
{
	Employee::writeData(out);
	out << expert << endl;
	out << salary << endl;

	return out.good();
}
