#include "University.h"
#include "Group.h"

int University::numberofStudents = 0;

University::University(string name)
{
	this->name = name;
}

void University::addGroup(string name)
{
	Group* group = new Group(name);
	this->groups.push_back(group);
}

void University::addStudent(string name, int age)
{
	Student* student = new Student(name, age, ++numberofStudents);
	this->students.push_back(student);
}

void University::removeStudent(int nr)
{
	for (int i = 0; i < this->students.size(); i++) {
		if (this->students[i]->getStudentNumber() == nr) {
			this->students.erase(this->students.begin() + i);
		}
	}

	for (int i = 0; i < this->groups.size(); i++) {
		if (this->groups[i]->getStudent(nr)) {
			this->groups[i]->removeStudent(nr);
		}
	}
}

vector<Student*> University::getStudents()
{
	return this->students;
}

vector<Group*> University::getGroups()
{
	return this->groups;
}

Group* University::getGroup(int number)
{
	
	for (Group* group : this->groups) {
		if (group->getNumber() == number)
			return group;
	}
}

Student* University::getStudent(int number)
{
	for (Student* student : this->students) {
		if (student->getStudentNumber() == number)
			return student;
	}
}
