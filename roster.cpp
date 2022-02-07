#include <string>
#include <iostream>
#include <array>

using namespace std;

#include "student.h"
#include "roster.h"
#include "degree.h"


Roster::Roster() {
    
    this->index = 0;
    this->degreeProgram = DegreeProgram::SOFTWARE;
    this->Students = nullptr;
}

//parse studentData table and add each student object to classRosterArray
void Roster::parse(string studentData) {

        //Student ID    
        size_t rhs = studentData.find(",");
        string studentID = studentData.substr(0, rhs);

        // First Name
        size_t lhs = rhs + 1;
        rhs = studentData.find(",", lhs);
        string firstName = studentData.substr(lhs, rhs - lhs);

        //Last Name
        lhs = rhs + 1;
        rhs = studentData.find(",", lhs);
        string lastName = studentData.substr(lhs, rhs - lhs);

        //Email
        lhs = rhs + 1;
        rhs = studentData.find(",", lhs);
        string emailAddress = studentData.substr(lhs, rhs - lhs);

        //Age
        lhs = rhs + 1;
        rhs = studentData.find(",", lhs);
        int age = stoi(studentData.substr(lhs, rhs - lhs));

        //Course 1 Days
        lhs = rhs + 1;
        rhs = studentData.find(",", lhs);
        int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));

        //Course 2 Days
        lhs = rhs + 1;
        rhs = studentData.find(",", lhs);
        int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));

        //Course 3 Days
        lhs = rhs + 1;
        rhs = studentData.find(",", lhs);
        int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));

        //Degree Program
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
}

// Instantiates and updates classRosterArray

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {

    //add each students individual days into an array
    int courseDays[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
     
        classRosterArray[index] = new Student(studentID, firstName, lastName, emailAddress, age, courseDays, degreeProgram);
        index++;
}

//print a roster of all students
void Roster::printAll() {
    cout << "All enrolled students: " << endl;
    
    for (int i = 0; i < index; i++) {
            classRosterArray[i]->print();
    }
}

//prints each students' average of three course days 
void Roster::printAverageDaysInCourse(string studentID) {
    int avgDays = 0;
    
    for (int i = 0; i < index; i++) {
        if ((this->classRosterArray[i])->GetStudentID() == studentID) {
            avgDays = ((classRosterArray[i])->GetCourseDays()[0] + (classRosterArray[i])->GetCourseDays()[1] + (classRosterArray[i])->GetCourseDays()[2]) / 3;
            cout << "Student ID: " << studentID << " has taken an average of " << avgDays << " days to complete a course." << endl;
        }
    }
}

//verifies validity of each students' email address and prints a list of students who have invalid emails
void Roster::printInvalidEmails() {
    cout << "Students with invalid emails: " << endl;
    for (int i = 0; i < index; i++) {
        string email = classRosterArray[i]->GetEmail();
        if (email.find('@') == string::npos || (email.find('.') == string::npos) || (email.find(' ') != string::npos)) {
            cout << email << " is invalid." << endl;
        }      
    }
}

//print students according to a specified enumerated degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) { 

    for (int i = 0; i < index; i++) {
        if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}

//remove an individual student and output an error if a student id was not found
void Roster::remove(string studentID) {
    for (int i = 0; i <= index; i++) {
        
        if (classRosterArray[i] == nullptr) {
            cout << "No student record found" << endl;
        }
        else if (this->classRosterArray[i]->GetStudentID() == studentID) {
            classRosterArray[i] = nullptr;
            cout << "Student " << studentID << " was removed." << endl;

            //update roster
            index--;
            for (i = i; i <= index; i++) {
                classRosterArray[i] = classRosterArray[i + 1];
            }
        }
        
    }    
}

//destructor frees up memory allocation
Roster::~Roster() {

    for (int i = 0; i < index; i++) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}

