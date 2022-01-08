// Assignment 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Student.h"
#include "Group.h"
#include "University.h"
#include "ModuleGrade.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
using namespace std;

void menu(University& uni) {

    int menuSelection;
    ofstream ofstudent;
    ifstream ifstudent;
    ofstream ofgroup;
    ifstream ifgroup;
    ofstudent.open("student.txt", ios::app);
    ifstudent.open("student.txt");
    ofgroup.open("group.txt", ios::app);
    ifgroup.open("group.txt");

    cout << "What would you like to do?" << endl;

    cout << "1.Add a group" << endl;

    cout << "2.View groups" << endl;

    cout << "3.Add a Student to a Group" << endl;

    cout << "4.Remove a Student from a Group" << endl;

    cout << "5.View Students of a Group" << endl;

    cout << "6.Add module to a student" << endl;

    cout << "7.Save a Student to a file" << endl;

    cout << "8.Read Students from a file" << endl;

    cout << "9.Save a Group to a file" << endl;

    cout << "10.Read Groups from a file" << endl;

    cout << "11.Create a Student" << endl;

    cout << "12.View Students" << endl;

    cout << "13.Remove a Student" << endl;

    cout << "14.Close application" << endl;

    cin >> menuSelection;

    switch (menuSelection)
    {
    case 1: {
        string name;
        string garbage;

        cout << "Name: ";
        cin >> name;
        getline(cin, garbage);
        uni.addGroup(name);
        break;
    }

    case 2: {
        if (uni.getGroups().size() == 0) {
            cout << "Please Create a group\n" << endl;
            break;
        }
        for (Group* group : uni.getGroups()) {
            cout << "Name: " << group->getName() << " Number: " << group->getNumber() << endl;
        }
        break;
    }

    case 3: {
        string name;
        int age;
        int number;
        string garbage;
        int groupNumber;

        if (uni.getGroups().size() == 0) {
            cout << "Please Create a group\n" << endl;
            break;
        }

        /*cout << "Name: ";
        cin >> name;
        getline(cin, garbage);
        cout << endl << "Age: ";
        cin >> age;
        getline(cin, garbage);
        cout << endl << "Number: ";
        cin >> number;

        Student* st;
        st = new Student(name, age, number);*/

        if (uni.getStudents().size() == 0) {
            cout << "Please Create a Student\n" << endl;
            break;
        }

        cout << "Please select a Student: " << endl;
        for (Student* student : uni.getStudents()) {
            cout << "Name: " << student->getName() << " Number: " << student->getStudentNumber() << "\n" << endl;
        }

        cout << "Student number: ";
        cin >> number;
        getline(cin, garbage);

        cout << "Please select group: " << endl;
        for (Group* group : uni.getGroups()) {
            cout << "Name: " << group->getName() << " Number: " << group->getNumber() << "\n" << endl;
        }

        cout << "Group number: ";
        cin >> groupNumber;
        getline(cin, garbage);

        uni.getGroup(groupNumber)->addStudent(uni.getStudent(number));

        cout << "Student added to group  " << groupNumber << endl;
        //push to list
        break;
    }

    case 4: {
        string garbage;
        int groupNumber;

        int studentNumber;

        if (uni.getGroups().size() == 0) {
            cout << "Please Create a group\n" << endl;
            break;
        }

        cout << "Please select group: " << endl;
        for (Group* group : uni.getGroups()) {
            cout << "Name: " << group->getName() << " Number: " << group->getNumber() << "\n" << endl;
        }

        cout << "Group number: ";
        cin >> groupNumber;
        getline(cin, garbage);

        cout << "Select student: " << endl;
        for (Student* student : uni.getGroup(groupNumber)->getStudents()) {
            cout << "Student number: " << student->getStudentNumber() << " name: " << student->getName() << " age: " << student->getAge() << endl;
        }

        cout << "Student Number: ";
        cin >> studentNumber;
        getline(cin, garbage);

        uni.getGroup(groupNumber)->removeStudent(studentNumber);

        break;
    }

    case 5: {

        string garbage;
        int groupNumber;

        if (uni.getGroups().size() == 0) {
            cout << "Please Create a group\n" << endl;
            break;
        }

        cout << "Please select group: " << endl;
        for (Group* group : uni.getGroups()) {
            cout << "Name: " << group->getName() << " Number: " << group->getNumber() << "\n" << endl;
        }

        cout << "Group number: ";
        cin >> groupNumber;
        getline(cin, garbage);

        for (Student* student : uni.getGroup(groupNumber)->getStudents()) {
            cout << "Student number: " << student->getStudentNumber() << " name: " << student->getName() << " age: " << student->getAge() << endl;
            student->ShowGradeList();
        }
        break;
    }

    case 6: {
        string garbage;
        int groupNumber;
        int studentNumber;
        string moduleName;
        int moduleGrade;

        /* cout << "Please select group: " << endl;
         for (Group* group : uni.getGroups()) {
             cout << "Name: " << group->getName() << " Number: " << group->getNumber() << "\n" << endl;
         }

         cout << "Group number: ";
         cin >> groupNumber;
         getline(cin, garbage);*/

        if (uni.getStudents().size() == 0) {
            cout << "Please Create a student\n" << endl;
            break;
        }

        cout << "Select student: " << endl;
        for (Student* student : uni.getStudents()) {
            cout << "Student number: " << student->getStudentNumber() << " name: " << student->getName() << " age: " << student->getAge() << endl;
        }

        cout << "Student Number: ";
        cin >> studentNumber;
        getline(cin, garbage);

        cout << "Module Name: ";
        cin >> moduleName;
        getline(cin, garbage);

        cout << "Module Grade: ";
        cin >> moduleGrade;
        getline(cin, garbage);

        //uni.getGroup(groupNumber)->getStudent(studentNumber)->addModule(moduleName,moduleGrade);
        uni.getStudent(studentNumber)->addModule(moduleName, moduleGrade);

        cout << "Module " << moduleName << " with grade " << moduleGrade << " added to Student with number " << studentNumber << endl;
        break;

    }

    case 7: {
        string garbage;

        int studentNumber;

        if (uni.getStudents().size() == 0) {
            cout << "Please create a student" << endl;
            break;
        }

        cout << "Please select a Student: " << endl;
        for (Student* student : uni.getStudents()) {
            cout << "Name: " << student->getName() << " Number: " << student->getStudentNumber() << "\n" << endl;
        }

        cout << "Student number: ";
        cin >> studentNumber;
        getline(cin, garbage);

        Student* st = uni.getStudent(studentNumber);
        ofstudent << st;

        break;
    }
    case 8: {
        while (true)
        {
            Student* st = new Student();
            ifstudent >> st;
            if (ifstudent.eof()) break;
            cout << st;
        }
        break;
    }

    case 9: {
        string garbage;
        int groupNumber;

        if (uni.getGroups().size() == 0) {
            cout << "Please Create a group\n" << endl;
            break;
        }

        cout << "Please select group: " << endl;
        for (Group* group : uni.getGroups()) {
            cout << "Name: " << group->getName() << " Number: " << group->getNumber() << "\n" << endl;
        }

        cout << "Group number: ";
        cin >> groupNumber;
        getline(cin, garbage);

        Group* gr = uni.getGroup(groupNumber);
        ofgroup << gr;
        break;

    }

    case 10: {
        while (true)
        {
            Group* gr = new Group();
            ifgroup >> gr;
            if (ifgroup.eof()) break;
            cout << gr;
        }
        break;
    }

    case 11: {
        string name;
        int age;
        string garbage;

        cout << "Name: ";
        cin >> name;
        getline(cin, garbage);
        cout << endl << "Age: ";
        cin >> age;
        getline(cin, garbage);

        uni.addStudent(name, age);

        cout << "Student " << name << " has been created with age " << age << endl;
        break;

    }
    case 12: {
        for (Student* student : uni.getStudents()) {
            cout << "Name: " << student->getName() << " Number: " << student->getStudentNumber() << " Age: " << student->getAge() << "\n" << endl;
            student->ShowGradeList();
        }
        break;
    }

    case 13: {
        int number;
        string garbage;

        if (uni.getStudents().size() == 0) {
            cout << "Please create a student" << endl;
            break;
        }

        cout << "Please select a Student: " << endl;
        for (Student* student : uni.getStudents()) {
            cout << "Name: " << student->getName() << " Number: " << student->getStudentNumber() << "\n" << endl;
        }

        cout << "Student number: ";
        cin >> number;
        getline(cin, garbage);

        uni.removeStudent(number);

        cout << "Student removed" << endl;;

        break;
    }
    case 14: {
        exit(0);
        _CrtDumpMemoryLeaks();
        break;

    }

    default:
        cout << "Please choose one of the menus" << endl;
        break;
    }

    ofstudent.close();
    ifstudent.close();
    ofgroup.close();
    ifgroup.close();
    menu(uni);
}

int main()
{
    string schoolname = "UA";
    University uni(schoolname);
    cout << "Welcome to " << schoolname << "!" << endl;

    menu(uni);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
