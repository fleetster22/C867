//#ifndef ROSTER_H
//#define ROSTER_H
#pragma once

using namespace std;

#include <string>
#include <iostream>
#include <array>
#include <vector>
#include <cstdlib>

class Student;
//#include "student.h"
//#include "degree.h"

class Roster {

public:
  
    Student* classRosterArray[5];

    Roster();

    ~Roster();

    void parse(string studentData);

    void add(string studentID, string firstName, string lastName, string emailAddress,
        int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

    void remove(string studentID);

    void printAll();

    void printAverageDaysInCourse(string studentID);

    void printInvalidEmails();

    void printByDegreeProgram(DegreeProgram degreeProgram);

private:

    Student student;
    string id, fName, lName, email;
    int studentAge, course1Days, course2Days, course3Days;
    //DegreeProgram degreeProgram;
    int courses[3];
    int numRoster = 5;
    double numClasses;



};
//#endif
