#include "StdAfx.h"
#include "Personal.h"

string intToString(int n)
{
	char buffer[100];
	itoa (n, buffer, 10);
	return buffer;
}


Personal::Personal(void)
{
	Name = "";
	Sex = "";
	ID = "";
	BirthYear = 0;
	SalaryLevel = 0;
	SalaryAdds = 0;
}

Personal::~Personal(void)
{
}

void Personal::InputData(void)
{
	cout << "Name: ";
	fflush(stdin);
	getline(cin, Name);
	cout << "Sex: ";
	cin >> Sex;
	cout << "ID: ";
	cin >> ID;
	cout << "Birth Year:";
	cin >> BirthYear;
	cout << "Salary Level: ";
	cin >> SalaryLevel;
	cout << "Salary Adds: ";
	cin >> SalaryAdds;
}

void Personal::OputData(void)
{
	cout << "Name: " << Name << endl;
	cout << "Sex: " << Sex << endl;
}
