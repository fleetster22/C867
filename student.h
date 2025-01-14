#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <array>

#include "degree.h"

using namespace std;


class Student {
public:
    //for courses array
    const static int numCourses = 3;

    Student();

    //Step D1 & D2
    Student(string studentID, string firstName, string lastName, string emailAddress,
        int age, int courses[], DegreeProgram degreeProgram);

    ~Student();

    void SetStudentID(string studentID);
    string GetStudentID();

    void SetFirstName(string firstName);
    string GetFirstName();

    void SetLastName(string lastName);
    string GetLastName();

    void SetEmail(string emailAddress);
    string GetEmail();

    void SetAge(int age);
    int GetAge();

    void SetCourseDays(int courseDays[]);
    int* GetCourseDays();

    void SetDegreeProgram(DegreeProgram degreeProgram);
    DegreeProgram GetDegreeProgram();

    void print();


private:
    string studentID, firstName, lastName, emailAddress;
    int age;
    int courses[numCourses];
    DegreeProgram degreeProgram;
};

#endif