#include "StdAfx.h"
#include "Tutor.h"


Tutor::Tutor(void)
{
	Degree = "";
	NumOfClass = 0;
}


Tutor::~Tutor(void)
{
}

istream & operator>> (istream &is, Tutor &A)
{
	A.InputData();
	cout << "Degree: ";
	cin >> A.Degree;
	cout << "The numbers of Class: ";
	cin >> A.NumOfClass;
	A.calSalary();
	return is;
}

ostream & operator<< (ostream &os, Tutor &A)
{
	A.OputData();
	cout << "Job: " << A.Degree << endl;
	cout << "Salary: " << A.Salary;
	return os;
}
void Tutor::calSalary()
{
	Salary = 730 * SalaryLevel + SalaryAdds + NumOfClass * 45;
}

