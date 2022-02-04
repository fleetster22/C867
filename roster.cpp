#include <string>
#include <iostream>
#include <array>

using namespace std;

#include "student.h"
#include "roster.h"
#include "degree.h"


Roster::Roster() {
    
    this->size = 0;
    this->degreeProgram = DegreeProgram::SOFTWARE;
    this->lastIndex = -1;
    //*this->classRosterArray = nullptr;
    //for (int i = 0; i < rosterSize; i++) this->classRosterArray[i] = nullptr;
    //for (int i = 0; i < numCourses; i++) this->courses[i] = 0;
}

Roster::Roster(int size) {
    this->size = size;
    this->lastIndex = -1;
    this->degreeProgram = DegreeProgram::SOFTWARE;
    //for (int i = 0; i < rosterSize; i++) this->classRosterArray[i] = nullptr;
    //for (int i = 0; i < numCourses; i++) this->courses[i] = courses[i];
}




void Roster::parse(string studentData) {
    //if(lastIndex < numRoster){
    //    lastIndex++;
    //for(int i = 0; i < numRoster; i++) {
        
        //int courses{ numRoster };
        
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

        //Convert string program to enum DegreeProgram
        if (program == "SECURITY") {
            degreeProgram = DegreeProgram::SECURITY;
        }
        else if (program == "NETWORK") {
            degreeProgram = DegreeProgram::NETWORK;
        }
        else if (program == "SOFTWARE") {
            degreeProgram = DegreeProgram::SOFTWARE;
        }
        

        add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
        //cout << studentID << firstName << lastName << emailAddress << age << daysInCourse1 << daysInCourse2 << daysInCourse3 << program << endl;
    //}
}

// Add Student objects to array

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    //add data to all fields 
    int courseDays[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    
   
    //if (classRosterArray[index] = nullptr) {
        classRosterArray[index] = new Student(studentID, firstName, lastName, emailAddress, age, courseDays, degreeProgram);
        //classRosterArray[index]->print();  // for testing
        
        index++;
    //}
}

void Roster::printAll() {
    cout << "All enrolled students: " << endl;
    
    for (int i = 0; i < numRoster; i++) {
            classRosterArray[i]->print();
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    int avgDays = 0;

    for (int i = 0; i < numRoster; i++) {
        if ((this->classRosterArray[i])->GetStudentID() == studentID) {
            avgDays = ((classRosterArray[i])->GetCourseDays()[0] + (classRosterArray[i])->GetCourseDays()[1] + (classRosterArray[i])->GetCourseDays()[2]) / 3;
            cout << "Student ID: " << studentID << " has taken an average of " << avgDays << " days to complete a course." << endl;
        }
    }
}

void Roster::printInvalidEmails() {
    cout << "Students with invalid emails: " << endl;
    for (int i = 0; i < numRoster; i++) {
        string email = classRosterArray[i]->GetEmail();
        if (email.find('@') == string::npos || (email.find('.') == string::npos) || (email.find(' ') != string::npos)) {
            cout << email << " is invalid." << endl;
        }      
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < numRoster; i++) {
        if (this->classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}

void Roster::remove(string studentID) {
    for (int i = 0; i < numRoster; i++) {
        if (classRosterArray[i]->GetStudentID() == studentID) {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
            cout << "Student " << studentID << " was removed." << endl;
            numRoster--;
            for (i = i; i < numRoster; i++) {
                classRosterArray[i] = classRosterArray[i + 1];
            }
        }
        else if (classRosterArray[i] == nullptr) {
            cout << "No student record found" << endl;
        }
    }
}

Roster::~Roster() {

    for (int i = 0; i < numRoster; i++) {
        delete classRosterArray[i];
    }
cout << "Memory released" << endl;

}
//sizeof(classRosterArray) / sizeof(classRosterArray[i])
