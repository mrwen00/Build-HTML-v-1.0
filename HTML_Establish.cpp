#include "StdAfx.h"
#include "HTML_Establish.h"


HTML_Establish::HTML_Establish(void)
{
}


HTML_Establish::~HTML_Establish(void)
{
}



string attri(const string &attr, const string &value)
{
	return attr + ": " + value + ';' + '\n';
}

string id(const string &name, const string &id, const string &content)
{
	return name + '#' + id + "{ \n" + content + "}" + '\n';
}


string quotationMark(const string &content)
{
	return "\"" + content + "\"" ;
}

string element(const string &elem, const string &content)
{
	return elem + " = " + quotationMark(content);
}

string p(const string &content)  // heading 1;
{
	return "<p>" + content + "</p>" + "\n";
}

string h1(const string &content)  // heading 1;
{
	return "<h1>" + content + "</h1>" + "\n";
}

string h2(const string &content)
{
	return "<h2>" + content + "</h2>" + "\n";
}

string abbr(const string &abr, const string &content)
{
	return "<abbr " + element("title", content) + ">" + abr + "</abbr>" + "\n" ; 
}

string href(const string &ref, const string &content)
{
	return "<a " + element("href", ref)  + element("target", "_blank") + ">" + content + "</a>";
}

string img(const string &src, const string &alt, const string &width, const string &height, const string &title)
{
	return   "<img " + element("src", src) + element("alt", alt) + element("width", width) + 
			element("height", height) + element("title", title) + '\n'; 
}

string td(const string &content)
{
	return "<td>" + content + "</td>" + '\n';
}

string th(const string &content)
{
	return "<th>" + content +"</th>" + '\n';
}

string tr(const string &content)
{
	return "<tr>" + content + "</tr>" + '\n';
}

string caption(const string &content)
{
	return "<caption>" + content + "</caption>" + '\n';
}

string table(string id, string content)
{
	return "<br>\n<table " + element("id", id) + "> \n" + content + "</table>" + '\n';
}

string setHead(string tile)
{
	string content = "<title> " + tile + "</title>\n<style>\n";
	content += id("th", "th01", 
					attri("padding", "15px") + 
					attri("text-align", "center"));
	content += id("td", "td01", 
					attri("padding", "15px") + 
					attri("text-align", "left"));
	content += id("table", "ta01 th, tr", 
					attri("width", "15%") + 
					attri("background-color", "lightgreen") + 
					attri("padding", "5px") + 
					attri("text-align", "right"));

	content += "</style>";
	return content;
}

string CollectDataTable(ListPerson &A)
{
	string content;
	content = caption(h1("Salary of Staff in City"));
	content += tr(th("ID") + th("Name") + th("Salary"));
	for(int i = 0; i < A.n; i++)
	{
		content += tr(th(href(A.L[i]->getID() + ".html", A.L[i]->getID())) + th(A.L[i]->getName()) + th(A.L[i]->getSalary()));
	}
	return content;
}


string setBodyTable(ListPerson &A)
{
	string s = h1("Salary Table");
	s += p("Date Now");
	s += table("ta01", CollectDataTable(A));
	return s;
}

string setBodyIndentity(Personal *A)
{
	string s;
	s = p("ID: " + A->getID());
	s += p("Name: " + A->getName());
	s += p("Birth year: " + A->getBirthYear());
	s += p("Sex: " + A->getSex());
	s += p("Salary: " + A->getSalary());
	if(A->TypeClass() == 1)
	{
		s += p("Degree: " + static_cast<Tutor *>(A)->getDegree());
		s += p("The Numbers of classes of Teaching: " + static_cast<Tutor *>(A)->getNumOfClass());
	}
	else {
		s += p("Job: " + static_cast<Staff *>(A)->getJob());
		s += p("The numbers of Workdays: " + static_cast<Staff *>(A)->getWorkDay());
	}
	s += img(A->getID(), A->getID(), "150", "150", A->getName());
	return s;
}

string HTMLShell(string Head, string Body)
{
	return "<!DOCTYPE html>\n<html>\n<head>\n" + Head + "\n</head>\n<body>\n" + Body + "\n</body>\n</html>";
}

void MainTable(ofstream &f, ListPerson &A)
{
	f << HTMLShell(setHead("Salary Table"), setBodyTable(A));
}

void MainIndentity(ofstream &f, Personal *A)
{
	f << HTMLShell(setHead(A->getName()), setBodyIndentity(A));
}

void saveFileHTML(string path, ListPerson &A)
{
	ofstream f(path + "abc.html");
	if(f.is_open())  {
		MainTable(f, A);
		for(int i = 0; i < A.n; i++)
		{
			ofstream f_sub(path + A.L[i]->getID() + ".html");
			MainIndentity(f_sub, A.L[i]);
			f_sub.close();
		}
		
		f.close();
		cout << "Save Done" << endl;
	}
	else cout << "Can not save the file" << endl;
	
}
