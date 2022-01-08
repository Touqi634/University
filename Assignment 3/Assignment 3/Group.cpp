#include "Group.h"

int Group:: groupNumber = 0;

Group::Group(string name)
{
	this->name = name;
	this->number = ++groupNumber;
}

Group::Group()
{
}

void Group::addStudent(Student* st)
{
	//Student* student = new Student(st);
	this->studentList.push_back(st);
}

void Group::removeStudent(int number)
{
	for (int i = 0; i < this->studentList.size(); i++) {
		if (this->studentList[i]->getStudentNumber() == number) {
			this->studentList.erase(this->studentList.begin() + i);
		}
	}
}

int Group::getNumber()
{
	return this->number;
}

string Group::getName()
{
	return this->name;
}

vector<Student*> Group::getStudents()
{
	return this->studentList;
}

Student* Group::getStudent(int number)
{
	for (Student* student : this->studentList) {
		if (student->getStudentNumber() == number)
			return student;
	}
}

ofstream& operator<<(ofstream& out, Group* g)
{
	// TODO: insert return statement here
	out << g->getNumber() << '\n' << g->getName() << '\n' <<  g->getStudents().size() <<  endl;
	for (int i = 0; i < g->studentList.size(); i++) {
		out << g->studentList[i];
	}
	return out;
}

ifstream& operator>>(ifstream& in, Group* g)
{
	// TODO: insert return statement here
	int x;
	in >> g->number >> g->name;
	in >> x;
	for (int i = 0; i < x; i++) {
		Student* st = new Student();
		in >> st;
		g->studentList.push_back(st);
	}
	return in;
}

ostream& operator<<(ostream& os, Group* g)
{
	// TODO: insert return statement here
	os << "Group Number: " << g->getNumber() << '\n' << "Group Name: " << g->getName() << '\n' << "Group Size: " << g->studentList.size() << endl;
	for (int i = 0; i < g->studentList.size(); i++) {
		os << g->studentList[i] << endl;
	}
	return os;
}
