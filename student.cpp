#include <string>
#include <array>
#include <vector>
#include <cstdlib>

#include "student.h"

using namespace std;



Student::Student() {
    int numCourses = 3.0;
    studentID = "";
    firstName = "";
    lastName = "";
    emailAddress = "";
    age = 0;
    //courseDays[numCourses] = {0, 0, 0};
    for (int i = 0; i < numCourses; i++) this->courses[i] = 0; 
    degreeProgram = DegreeProgram::SOFTWARE;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress,
    int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->daysInCourse1 = daysInCourse1;
    this->daysInCourse2 = daysInCourse2;
    this->daysInCourse3 = daysInCourse3;
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

void Student::SetCourseDays(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
    this->daysInCourse1 = daysInCourse1;
    this->daysInCourse2 = daysInCourse2;
    this->daysInCourse3 = daysInCourse3;
    courses[0] = daysInCourse1;
    courses[1] = daysInCourse2;
    courses[2] = daysInCourse3;
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

}

//for (int i = 0; i < numOfDaySize; i++) this->numOfDays[i] = 0;
//for (int i = 0; i < numOfDaySize; i++) this->numOfDays[i] = numOfDays[i];
