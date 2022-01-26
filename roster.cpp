#include <string>
#include <iostream>
#include <array>

using namespace std;

#include "student.h"
#include "roster.h"
#include "degree.h"


Roster::Roster() {
    numRoster = 5;
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    this->daysInCourse1 = 0;
    this->daysInCourse2 = 0;
    this->daysInCourse3 = 0;
    *this->courses = { };    //for (int i = 0; i < numClasses; i++) this->courses[i] = 0;
    for (int i = 0; i < rosterSize; i++) this->classRosterArray[i] = { nullptr };
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

    //DegreeProgram degree = DegreeProgram::SOFTWARE;
   

    if (program == "SECURITY") {
        degreeProgram = DegreeProgram::SECURITY;
    } else if (program == "NETWORK") {
        degreeProgram = DegreeProgram::NETWORK;
    }
    else if (program == "SOFTWARE") {
        degreeProgram = DegreeProgram::SOFTWARE;
    }
    
   
    add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    //cout << studentID << firstName << lastName << emailAddress << age << daysInCourse1 << daysInCourse2 << daysInCourse3 << program << endl;
}

// Add Student objects to array

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    //add data to all fields 
    
    //int courses[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    
    for (int i = 0; i < 5; i++) {
        classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
        classRosterArray[i]->print();
    }
}

void Roster::printAll() {
    cout << "All enrolled students: " << endl;
    
    for (int i = 0; i < numRoster; i++) {
            classRosterArray[i]->print();
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    double numClasses = 3.0;
    for (int i = 0; i < numRoster; i++) {
        if ((classRosterArray[i])->GetStudentID() == studentID) {
            double avgDays = 0.0;
            avgDays = ((classRosterArray[i])->GetCourseDays()[0] + (classRosterArray[i])->GetCourseDays()[1] + classRosterArray[i])->GetCourseDays()[2] / numClasses;
            cout << "Student ID: " << studentID << " has taken an average of " << avgDays << " days to complete a course." << endl;
        }
    }
}

void Roster::printInvalidEmails() {
    for (int i = 0; i < numRoster; i++) {
        string email = classRosterArray[i]->GetEmail();
        
        if (email.find('@') == string::npos || (email.find('.') == string::npos) || (email.find(' ') != string::npos)) {
            cout << email << " is invalid." << endl;
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

    for (int i = 0; i < numRoster; i++) {
        if (Roster::classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}

void Roster::remove(string studentID) {
    for (int i = 0; i < numRoster; i++) {
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

Roster::~Roster() {
    
    delete[] * classRosterArray;
    cout << "Program deleted" << endl;
    /*
    for (int i = 0; i < numRoster; i++) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
    */
}
//sizeof(classRosterArray) / sizeof(classRosterArray[i])
