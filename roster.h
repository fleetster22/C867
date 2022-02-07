#ifndef ROSTER_H
#define ROSTER_H


using namespace std;

#include <string>
#include <iostream>
#include <array>

#include "student.h"


class Roster {

public:

    //array of pointers, Step E1
    Student* classRosterArray[5] = {nullptr, nullptr, nullptr, nullptr, nullptr};
    Student** Students;

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

    int index;
    DegreeProgram degreeProgram;
};

#endif
