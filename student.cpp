#include <string>
#include <array>
#include <cstdlib>
#include <iostream>
#include "student.h"

using namespace std;



Student::Student() {
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    for (int i = 0; i < numCourses; i++) this->courses[i] = 0;
    this->degreeProgram = DegreeProgram::SOFTWARE;

}

Student::Student(string studentID, string firstName, string lastName, string emailAddress,
    int age, int courseDays[], DegreeProgram degreeProgram) {

    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < numCourses; i++) this->courses[i] = courseDays[i];
        //this->daysInCourse1 = daysInCourse1;
        //this->daysInCourse2 = daysInCourse2;
        //this->daysInCourse3 = daysInCourse3;
    this->degreeProgram = degreeProgram;
    
}


    Student::~Student() {
    }

    void Student::SetStudentID(string id) {
        this->studentID = id;
    }
    string Student::GetStudentID() {
        return this->studentID;
    }

    void Student::SetFirstName(string fName) {
        this->firstName = fName;
    }
    string Student::GetFirstName() {
        return this->firstName;
    }

    void Student::SetLastName(string lName) {
        this->lastName = lName;
    }
    string Student::GetLastName() {
        return this->lastName;
    }

    void Student::SetEmail(string email) {
        this->emailAddress = email;
    }
    string Student::GetEmail() {
        return this->emailAddress;
    }

    void Student::SetAge(int studentAge) {
        this->age = studentAge;
    }
    int Student::GetAge() {
        return this->age;
    }

    void Student::SetCourseDays(int courseDays[]) {
        for (int i = 0; i < numCourses; i++) this->courses[i] = courseDays[i];
    }
    int* Student::GetCourseDays() {
        return this->courses;
    }

    void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
        this->degreeProgram = degreeProgram;
    }
    DegreeProgram Student::GetDegreeProgram() {
        return this->degreeProgram;
    }

    void Student::print() {
        string degree;

        if (degreeProgram == DegreeProgram::NETWORK) {
            degree = "NETWORK";
        }
        else if (degreeProgram == DegreeProgram::SOFTWARE) {
            degree = "SOFTWARE";
        }
        else if (degreeProgram == DegreeProgram::SECURITY) {
            degree = "SECURITY";
        }
        

        cout << GetStudentID() << "\t";
        cout << "First Name: " << GetFirstName() << "\t";
        cout << "Last Name: " << GetLastName() << "\t";
        cout << "Email: " << GetEmail() << "\t";
        cout << "Age: " << GetAge() << "\t";
        cout << "daysInCourse: { " << courses[0] << ", " << courses[1] << ", " << courses[2] << " }" << "\t";
        cout << "Degree Program: " << degree;

        cout << endl;

    }



//for (int i = 0; i < numOfDaySize; i++) this->numOfDays[i] = 0;
//for (int i = 0; i < numOfDaySize; i++) this->numOfDays[i] = numOfDays[i];
