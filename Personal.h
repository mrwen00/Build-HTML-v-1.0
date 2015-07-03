#pragma once

string intToString(int n);
class Personal
{
protected:
	string Name;
	string Sex;
	string ID;
	int BirthYear;
	int SalaryLevel;
	long SalaryAdds;
	int Salary;
public:
	Personal(void);
	~Personal(void);
	void InputData(void);
	void OputData(void);
	virtual void calSalary() = 0;
	virtual int TypeClass(void) = 0;	
	string getName() {
		return Name;
	}
	string getID() {
		return ID;
	}
	string getSex() {
		return Sex;
	}
	string getBirthYear() {
		return intToString(BirthYear);
	}
	string getSalary() {
		return intToString(Salary);
	}
};

