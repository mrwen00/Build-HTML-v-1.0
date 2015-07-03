// BuildHTML.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



int _tmain(int argc, _TCHAR* argv[])
{
	ListPerson A, B;
	cin >> A;
	saveFileHTML("e:\\", A);   // you can change the default save location here, the default file is "abc.html"
	/*saveListPersonFile("e:\\person", A);
	B = loadListPersonFile("e:\\person");
	cout << B;*/
	return 0;
}

