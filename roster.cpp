#include <string>
#include <iostream>
#include <array>

using namespace std;

//#include "student.h"
#include "roster.h"
#include "degree.h"


Roster::Roster() {
    double numClasses = 0.0;
    int numRoster = 0;
    studentID = "";
    firstName = "";
    lastName = "";
    emailAddress = "";
    age = 0;
    daysInCourse1 = 0;
    daysInCourse2 = 0;
    daysInCourse3 = 0;
    for (int i = 0; i < numClasses; i++) this->courses[i] = 0;
    for (int i = 0; i < numRoster; i++) this->classRosterArray[i] = nullptr;
    degreeProgram = DegreeProgram::SOFTWARE;
}


void Roster::parse(string studentData) {

    size_t rhs = studentData.find(",");
    string studentID = studentData.substr(0, rhs);

    size_t lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string firstName = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string lastName = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string emailAddress = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int age = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string program = studentData.substr(lhs, rhs - lhs);

    DegreeProgram degree = DegreeProgram::SOFTWARE;
   

    if (program == "SECURITY") {
        degree = DegreeProgram::SECURITY;
    } else if (program == "NETWORK") {
        degree = DegreeProgram::NETWORK;
    }
    

    
    //cout << studentID << firstName << lastName << emailAddress << age << daysInCourse1 << daysInCourse2 << daysInCourse3 << program << endl;
    add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    
    int courses[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
        classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    }
    
}

void Roster::remove(string studentID) {
    for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
        if (classRosterArray[i] == nullptr) {
            cout << "No student record found for " << studentID << endl;
        }
        else if (classRosterArray[i]->GetStudentID() == studentID) {
                classRosterArray[i] = nullptr;
                cout << "Student " << studentID << " was removed." << endl;
                numRoster--;
                for (i = i; i <= numRoster; i++) {
                    classRosterArray[i] = classRosterArray[i + 1];
                }
        }
    }
}

void Roster::printAll() {

    for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
        if (classRosterArray[i] != nullptr)
        {
            classRosterArray[i]->print();
        }
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    double numClasses = 3.0;
    for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
        if ((classRosterArray[i])->GetStudentID() == studentID) {
            double avgDays = 0.0;
            avgDays = ((classRosterArray[i])->GetCourseDays()[0] + (classRosterArray[i])->GetCourseDays()[1] + classRosterArray[i])->GetCourseDays()[2] / numClasses;
            cout << "Student ID: " << studentID << " has taken an average of " << avgDays << " days to take 3 courses." << endl;
        }
    }
}

void Roster::printInvalidEmails() {
    for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
        string email = classRosterArray[i]->GetEmail();
        
        if (email.find('@') == string::npos || (email.find('.') == string::npos) || (email.find(' ') != string::npos)) {
            cout << emailAddress << " is invalid." << endl;
        }
        //else if (email.find('.') != string::npos) {
        //    cout << emailAddress << endl;
        //}
        //else if (email.find(' ') == string::npos) {
        //            cout << emailAddress << " is invalid" << endl;
        //}
            
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {

    for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
        if (Roster::classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}

Roster::~Roster() {

    for (int i = 0; i < numRoster; i++) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
