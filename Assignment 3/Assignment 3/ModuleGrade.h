#pragma once
#include <vector>
#include <string>
#include <fstream>
using namespace std;
class ModuleGrade
{
private:
	string moduleName;
	int moduleGrade;

public:
	ModuleGrade(string modName, int modGrade);
	ModuleGrade();
	void showModule();

	string getName();
	int getGrade();

	friend ofstream& operator<< (ofstream& out, ModuleGrade* g);
	friend ifstream& operator>> (ifstream& in, ModuleGrade* g);
	friend ostream& operator<<(ostream& os, ModuleGrade* g);
};

