#include "Student.h"

Student::Student(string s, int age, int nr) : Person(s,age)
{
	this->studentNumber = nr;
	//this->gradeList = null ;
}

Student::Student(Student& st) : Person(st)
{
	this->studentNumber = st.studentNumber;
	ModuleGrade* mg;
	for (int i = 0; i < st.gradeList.size(); i++) {
		mg = new ModuleGrade(st.gradeList[i]->getName(), st.gradeList[i]->getGrade());
		this->gradeList.push_back(mg);
	}
}

Student::Student()
{
}

Student::~Student()
{
	for (int i = 0; i < this->gradeList.size(); i++) {
		delete gradeList[i];
	}
	this->gradeList.clear();
}

void Student::addModule(string modName, int ModGrade)
{

	ModuleGrade* mg;
	mg = new ModuleGrade(modName, ModGrade);

	this->gradeList.push_back(mg);
}

void Student::ShowGradeList()
{
	for (int i = 0; i < this->gradeList.size(); i++) {
		this->gradeList[i]->showModule();
	}
}

int Student::getStudentNumber()
{
	return this->studentNumber;
}

Student& Student::operator= (const Student& st) {
	if (this == &st) return *this;
	Person::operator = (st);
	this->studentNumber = st.studentNumber;
	for (int i = 0; i < this->gradeList.size(); i++) {
		delete this->gradeList[i];
	}
	this->gradeList.clear();

	ModuleGrade* mg;
	for (int i = 0; i < st.gradeList.size(); i++) {
		mg = new ModuleGrade(st.gradeList[i]->getName(), st.gradeList[i]->getGrade());
		this->gradeList.push_back(mg);
	}


}

std::ofstream& operator <<(std::ofstream& out, Student* s)
{
	// TODO: insert return statement here
	out << s->getStudentNumber() << '\n' << s->getName() << '\n' << s->getAge() << '\n' << s->gradeList.size() << endl;
	for (int i = 0; i < s->gradeList.size(); i++) {
		out << s->gradeList[i];
	}
	return out;
}

ifstream& operator>>(ifstream& in, Student* s)
{
	// TODO: insert return statement here
	int x;
	in >> s->studentNumber >> s->name >> s->age;
	in >> x;
	for (int i = 0; i < x; i++) {
		ModuleGrade* gr = new ModuleGrade();
		in >> gr;
		s->gradeList.push_back(gr);
	}
	return in;
}

ostream& operator<<(ostream& os, Student* s)
{
	// TODO: insert return statement here
	os << "Student Number: " <<  s->studentNumber << '\n' << "Student Name: " << s->getName() << '\n' << "Age: " << s->getAge() << std::endl;
	os << "Number of Modules: " << s->gradeList.size() << std::endl;
	for (int i = 0; i < s->gradeList.size(); i++) {
		os << s->gradeList[i];
	}
	return os;
}
