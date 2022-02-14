#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"

using namespace std;

int main()
{
    const string studentData[] =
    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
      "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
      "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
      "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
      "A5,Eli,Klinh,ekling6@gmail.com,23,25,53,21,SOFTWARE" };

    // Prints User Information
    cout << "C867-Scripting & Programming: Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 009463296" << endl;
    cout << "Name: Elliott K" << endl << "\n";

    // Creates roster instance
    Roster classRoster;
    
    // Roster classRoster = student;
    for (int i = 0; i < 5; i++) 
    {
        classRoster.parse(studentData[i]);
    }

     classRoster.printAll();
     classRoster.printInvalidEmails(); 
     classRoster.printByDegreeProgram(SOFTWARE);

     for (int i = 0; i < 5; i++)
    {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudent_ID());
    }
     cout << "\n";

     classRoster.remove("A3");
     classRoster.remove("A3");
}