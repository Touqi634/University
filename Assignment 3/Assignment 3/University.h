#include <string>
#include <vector>
#include "Group.h"
using namespace std;
#pragma once
class University
{
private:
	string name;
	vector <Group*> groups;
	vector <Student*> students;
	static int numberofStudents;
public:
	University(string name);
	void addGroup(string name);
	void addStudent(string name, int age);
	void removeStudent(int nr);
	vector <Student*> getStudents();
	vector <Group*> getGroups();
	Group* getGroup(int number);
	Student* getStudent(int number);
};

