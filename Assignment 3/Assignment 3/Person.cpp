#include "Person.h"

int Person::numberofPersons = 0;

Person::Person()
{
	this->name = "";
	this->age = NULL;
	numberofPersons++;
}

Person::Person(string s, int age)
{
	this->name = s;
	this->age = age;
	numberofPersons++;
}

string Person::getName()
{
	return this->name;
}

int Person::getAge()
{
	return this->age;
}

int Person::getNumberofPersons()
{
	return numberofPersons;
}
