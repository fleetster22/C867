#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <array>

#include "degree.h"

using namespace std;


class Student {
public:

    Student();

    Student(string studentID, string firstName, string lastName, string emailAddress,
        int age, int daysInCourse1, int daysInCourse2, int daysIncourse3, DegreeProgram degreeProgram);

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

    void SetCourseDays(int daysInCourse1, int daysInCourse2, int daysInCourse3);
    int* GetCourseDays();

    void SetDegreeProgram(DegreeProgram degreeProgram);
    DegreeProgram GetDegreeProgram();

    void print();


private:
    string studentID, firstName, lastName, emailAddress, degreeType;
    int age, numCourses, daysInCourse1, daysInCourse2, daysInCourse3;
    int courses[3]; 
    DegreeProgram degreeProgram;
};

#endif