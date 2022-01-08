#include <vector>
#include "Student.h"
#include <string>
using namespace std;
#pragma once
class Group
{
private:
	int number;
	string name;
	vector <Student*> studentList;
	static int groupNumber;
public:
	Group(string name);
	Group();
	void addStudent(Student* st);
	void removeStudent(int number);
	int getNumber();
	string getName();
	vector <Student*> getStudents();
	Student* getStudent(int number);

	friend ofstream& operator<< (ofstream& out, Group* g);
	friend ifstream& operator>> (ifstream& in, Group* g);
	friend ostream& operator<<(ostream& os, Group* g);
};

