
#include <string>
#include <iostream>
#include <array>

using namespace std;;

#include "roster.h"



int main() {

    //Step A
    const string studentData[] =
    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Anaka,Norfleet,anakanorfleet@gmail.com,48,34,30,32,SOFTWARE",
    };
    
    //my information
    cout << "C867 Scripting & Programming: Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 001528537" << endl;
    cout << "Name: Anaka Norfleet" << endl << endl << endl;

    const int numRoster = 5;

    //Instantiate Roster class 
    Roster classRoster; 

    //add each student to classRoster
    for (int i = 0; i < numRoster; i++) classRoster.parse(studentData[i]);

    classRoster.printAll();
    cout << endl << endl << endl;

    classRoster.printInvalidEmails();
    cout << endl << endl << endl;
 
    cout << "Average days for each student based on three courses: " << endl;
    for (int i = 0; i < numRoster; i++) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentID());
    }
    cout << endl << endl << endl;

    cout << "Software Students: " << endl;
        classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
        cout << endl << endl << endl;

    classRoster.remove("A3");
    cout << endl << endl << endl;

    cout << "Updated roster of all students: " << endl;
    classRoster.printAll();
    cout << endl << endl << endl;

    cout << "Try to remove student with ID that no longer exists" << endl;
    classRoster.remove("A3");
    cout << endl << endl << endl;

    cout << "Releasing memory" << endl;
    classRoster.~Roster();
  
    return 0;
}
