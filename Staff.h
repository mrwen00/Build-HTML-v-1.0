#pragma once
#include "personal.h"

class Staff :
	public Personal
{
protected:
	string Job;
	int WorkDay;
public:
	Staff(void);
	~Staff(void);
	friend istream & operator>> (istream &is, Staff &A);
	friend ostream & operator<< (ostream &os, Staff &A);
	void calSalary();
	string getJob() {
		return Job;
	}
	string getWorkDay() {
		return intToString(WorkDay);
	}
	int TypeClass(void) {
		return 2;
	}
};

