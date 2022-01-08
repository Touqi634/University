#pragma once
#include <string>
#include <vector>
using namespace std;
class Person
{
protected:
	string name;
	int age;
	static int numberofPersons;

public:
	Person();
	Person(string s, int age);
	string getName();
	int getAge();
	static int getNumberofPersons();
};

