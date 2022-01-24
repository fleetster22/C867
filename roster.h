#ifndef ROSTER_H
#define ROSTER_H


using namespace std;

#include <string>
#include <iostream>
#include <array>

#include "student.h"


class Roster {

public:

    Student* classRosterArray[5] = {};

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

    //Student student;
    string studentID, firstName, lastName, emailAddress;
    int age, daysInCourse1, daysInCourse2, daysInCourse3, numRoster;
    int* courses[3];
    double numClasses;
    DegreeProgram degreeProgram;


};
#endif
