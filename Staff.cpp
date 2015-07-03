#include "StdAfx.h"
#include "Staff.h"


Staff::Staff(void)
{
	Job = "";
	WorkDay = 0;
}


Staff::~Staff(void)
{
}

istream & operator>> (istream &is, Staff &A)
{
	A.InputData();
	cout << "Job: ";
	cin >> A.Job;
	cout << "Work Day: ";
	cin >> A.WorkDay;
	A.calSalary();
	return is;
}

ostream & operator<< (ostream &os, Staff &A)
{
	A.OputData();
	cout << "Job: " << A.Job << endl;
	cout << "Salary: " << A.Salary << endl;;
	return os;
}
void Staff::calSalary()
{
	Salary = 730 * SalaryLevel + SalaryAdds + WorkDay * 200;
}
