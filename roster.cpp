#include <string>
#include <iostream>
//#include <iomanip>
#include <array>
//#include <vector>


using namespace std;

//#include "student.h"
#include "roster.h"


void Roster::parse(string studentData) {

    size_t rhs = studentData.find(",");
    string id = studentData.substr(0, rhs);

    size_t lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string fName = studentData.substr(lhs, rhs - 1);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string lName = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string emailAddress = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int studentAge = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int course1Days = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int course2Days = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int course3Days = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string program = studentData.substr(lhs, rhs - lhs);

    DegreeProgram degreeProgram = DegreeProgram::SOFTWARE;
    if (program == "NETWORK") {
        degreeProgram = DegreeProgram::NETWORK;
    }
    else if (program == "SECURITY") {
        degreeProgram = DegreeProgram::SECURITY;
    }
    //cout << id << fName << lName << emailAddress << studentAge << course1Days << course2Days << course3Days << degreeProgram;
    add(id, fName, lName, emailAddress, studentAge, course1Days, course2Days, course3Days, degreeProgram);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    
    int courses[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    
    //professor helped with below line
    
    
    for (int i = 0; i < numRoster; i++) {
        classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    }
}

Roster::~Roster() {

    for (int i = 0; i < numRoster; i++) {
        delete classRosterArray[i];
    }
}

void Roster::remove(string studentID) {
    for (int i = 0; i < numRoster; i++) {
        if (classRosterArray[i] != nullptr) {
            if (classRosterArray[i]->GetStudentID() == studentID) {
                delete classRosterArray[i];
            }
        }
    }

    cout << "No student found for " << id << endl;
}

void Roster::printAll() {

    for (int i = 0; i < numRoster; i++) {
        classRosterArray[i]->print();
    }
}

void Roster::printAverageDaysInCourse(string studentID) {

    double numCourses = 3.0;
    //(course1Days + course2Days + course3Days) / numCourses;

    for (int i = 0; i <= numRoster; i++) {
        if ((classRosterArray[i])->GetStudentID() == studentID) {
            double avgDays = 0.0;
            avgDays = ((classRosterArray[i])->GetCourseDays()[0] + (classRosterArray[i])->GetCourseDays()[1] + classRosterArray[i])->GetCourseDays()[2] / numCourses;
            cout << "Student ID: " << id << " has taken an average of " << avgDays << " days to take 3 courses." << endl;
        }
    }
}

void Roster::printInvalidEmails() {
    for (int i = 0; i < numRoster; i++) {
        string email = classRosterArray[i]->GetEmail();

        if (email.find('@') != string::npos) {
            if (email.find('.') != string::npos) {
                if (email.find(' ') == string::npos) {
                    cout << email << " is invalid" << endl;
                }
            }
        }
        else {

        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {

    for (int i = 0; i < numRoster; +i++) {
        if (Roster::classRosterArray[i]->GetDegreeProgram() == degreeProgram);
    }
}
