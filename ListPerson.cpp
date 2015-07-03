#include "StdAfx.h"
#include "ListPerson.h"


ListPerson::ListPerson(void)
{
}


ListPerson::~ListPerson(void)
{
}

istream & operator>> (istream &is, ListPerson &A)
{
	int choice;
	cout << "Input the number of people: ";
	is >> A.n;
	for(int i = 0; i < A.n; i++)
	{
		cout << "Choice 1. Tutor, 2. Staff: ";
		is >> choice;
		switch(choice) {
		case 1: {
			A.L[i] = new Tutor;
			is >> *static_cast<Tutor *>(A.L[i]);
			break;
				}
		case 2: {
			A.L[i] = new Staff;
			is >> *static_cast<Staff *>(A.L[i]);
			break;
				}
		}
	}
	return is;
}

ostream & operator<< (ostream &os, ListPerson A)
{
	for(int i = 0; i < A.n; i++)
	{
		if(A.L[i]->TypeClass() == 1)
			os << *static_cast<Tutor *> (A.L[i]) << endl;
		else
			os << *static_cast<Staff *> (A.L[i]) << endl;
	}
	return os;
}



// These functions have not been set up completely yet, Some troubles appear that is save the binary
// file which store different class type.

//void saveListPersonFile(string SavePath, ListPerson &A)
//{
//	ofstream f(SavePath, ios::binary);
//	if(f.is_open()) {
//		for(int i = 0; i < A.n; i++)
//		{
//			if(A.L[i]->TypeClass() == 1)
//				f.write((char *) & *A.L[i], sizeof(Tutor));
//			else {
//				f.write((char *) & *A.L[i], sizeof(Staff));
//			}
//		}
//		f.close();
//	}
//	else {
//		cout << "Can not save the file.";
//	}
//}
//ListPerson loadListPersonFile(string LoadPath)
//{
//	ListPerson A;
//	Tutor tempTutor;
//	Staff tempStaff;
//	int i = 0;
//	size_t tempsize = 0;
//	ifstream f(LoadPath, ios::binary);
//	if(f.is_open()) {
//		while(!f.eof()) {
//			f.read((char *) &tempsize, sizeof(size_t));
//			if(tempsize == sizeof(Tutor)) {
//				f.read((char *) &tempTutor, sizeof(tempsize));
//			}
//			else if(tempsize == sizeof(Staff)) {
//				f.read((char *) &tempStaff, sizeof(tempsize));
//			}
//
//
//
//			/*f.read((char *) &temp, sizeof(Tutor));
//			if(temp.TypeClass() == 1) {
//			A.L[i] = new Tutor;
//			*A.L[i] = temp;
//			}
//			else if(temp.TypeClass() == 2) {
//			A.L[i] = new Staff;
//			*A.L[i] = temp;
//			}*/
//
//			i++;
//		}
//		f.close();
//	}
//	else {
//		cout << "Can not open the file.";
//	}
//
//	return A;
//}