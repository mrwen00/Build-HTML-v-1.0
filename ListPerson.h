#pragma once
class ListPerson
{
	Personal *L[100];
	int n;
public:
	ListPerson(void);
	~ListPerson(void);
	friend istream & operator>> (istream &is, ListPerson &A);
	friend ostream & operator<< (ostream &os, ListPerson A);
	friend string CollectDataTable(ListPerson &A);
	friend void saveFileHTML(string path, ListPerson &A);
	friend void saveListPersonFile(string SavePath, ListPerson &A);
	friend ListPerson loadListPersonFile(string LoadPath);
};

void saveListPersonFile(string SavePath, ListPerson &A);
ListPerson loadListPersonFile(string LoadPath);