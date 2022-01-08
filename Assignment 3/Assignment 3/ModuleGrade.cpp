#include "ModuleGrade.h"
#include <iostream>

ModuleGrade::ModuleGrade(string modName, int modGrade)
{
	this->moduleName = modName;
	this->moduleGrade = modGrade;
}

ModuleGrade::ModuleGrade()
{
}

void ModuleGrade::showModule()
{
	cout << "Module Name: " << this->moduleName << " Module Grade: " << this->moduleGrade << endl;
}

string ModuleGrade::getName()
{
	return this->moduleName;
}

int ModuleGrade::getGrade()
{
	return this->moduleGrade;
}

ofstream& operator<<(ofstream& out, ModuleGrade* g)
{
	out << g->moduleName << '\n' << g->moduleGrade << endl;
	return out;
}

ifstream& operator>>(ifstream& in, ModuleGrade* g)
{
	in >> g->moduleName >> g->moduleGrade;
	return in;
}

ostream& operator<<(ostream& os, ModuleGrade* g)
{
	os << "Module Name: " << g->moduleName << '\n' << "Module Grade: " <<  g->moduleGrade << endl;
	return os;
}
