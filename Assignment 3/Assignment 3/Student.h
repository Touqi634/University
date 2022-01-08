#pragma once
#include "Person.h"
#include "ModuleGrade.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
class Student : public Person
{
private:
	int studentNumber;
	vector <ModuleGrade*> gradeList;

public:
	Student(string s, int age, int nr);
	Student(Student& st);
	Student();
	~Student();
	void addModule(string modName, int ModGrade);
	void ShowGradeList();
	int getStudentNumber();
	Student& operator= (const Student& st);

	friend ofstream& operator<< (ofstream& out, Student* s);
	friend ifstream& operator>> (ifstream& in, Student* s);
	friend ostream& operator<<(ostream& os, Student* s);
};

