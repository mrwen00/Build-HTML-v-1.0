#pragma once
#include "personal.h"

class Tutor :
	public Personal
{
protected:
	string Degree;
	int NumOfClass;
public:
	Tutor(void);
	~Tutor(void);
	friend istream & operator>> (istream &is, Tutor &A);
	friend ostream & operator<< (ostream &os, Tutor &A);
	Tutor operator= (const Tutor &A);
	void calSalary();
	string getDegree() {
		return Degree;
	}
	string getNumOfClass() {
		return intToString(NumOfClass);
	}
	int TypeClass(void) {
		return 1;
	}
	
};

