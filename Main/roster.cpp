#pragma once
#include "roster.h"
#include "student.h"
#include "degree.h"
#include <iostream>
#include <string> 
#include <iomanip>
using namespace std;

void Roster::add(std::string student_ID, std::string firstName, std::string lastName, std::string email,
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,
	DegreeProgram degreeProgram)
	
{
	int daysInCourseArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	student* newStudent = new student(student_ID, firstName, lastName, email, age, daysInCourseArray, degreeProgram);
	classRosterArray[++studentCount] = newStudent;
}

void Roster::parse(string studentElements)
{
	int endPosition = studentElements.find(",");
	string student_ID = studentElements.substr(0, endPosition);

    int startPosition = endPosition + 1;
	endPosition = studentElements.find(',', startPosition);
	string firstName = studentElements.substr(startPosition, endPosition - startPosition);

	startPosition = endPosition + 1;
	endPosition = studentElements.find(',', startPosition);
	string lastName = studentElements.substr(startPosition, endPosition - startPosition);

	startPosition = endPosition + 1;
	endPosition = studentElements.find(',', startPosition);
	string email = studentElements.substr(startPosition, endPosition - startPosition);

	startPosition = endPosition + 1;
	endPosition = studentElements.find(',', startPosition);
	int age = stoi(studentElements.substr(startPosition, endPosition - startPosition));

	startPosition = endPosition + 1;
	endPosition = studentElements.find(',', startPosition);
	int days1 = stoi(studentElements.substr(startPosition, endPosition - startPosition));

	startPosition = endPosition + 1;
	endPosition = studentElements.find(',', startPosition);
	int days2 = stoi(studentElements.substr(startPosition, endPosition - startPosition));

	startPosition = endPosition + 1;
	endPosition = studentElements.find(',', startPosition);
	int days3 = stoi(studentElements.substr(startPosition, endPosition - startPosition));

	startPosition = endPosition + 1;
	endPosition = studentElements.find(',', startPosition);
	string degreeP = studentElements.substr(startPosition, endPosition - startPosition);

	DegreeProgram degreeP2 = SOFTWARE;
	
	if (degreeP == "SECURITY") 
	{
		degreeP2 = SECURITY;
	}

	if (degreeP == "NETWORK") 
	{
		degreeP2 = NETWORK; 
	}

	add(student_ID, firstName, lastName, email, age, days1, days2, days3, degreeP2);
}

void Roster::remove(std::string studentID)
{
	bool check = false;
	for (int i = 0; i <= Roster::studentCount; i++)
	{
		if (studentID == classRosterArray[i]->getStudent_ID())
		{
			if (i < tableSize - 1)
			{
				cout << classRosterArray[i]->getStudent_ID() << " was removed" << "\n\n";
				student* place = classRosterArray[i] = classRosterArray[tableSize-1];
				classRosterArray[tableSize-1] = place;
				check = true;
			}
			studentCount--;
		}
	}
	if (check == false)
	{
		cout << "No matching student ID for " << studentID << " was found\n\n";
	}
	printAll();
}

void Roster::printAll()
{
	cout << "Displaying all students:" << endl;
	for (int i = 0; i <= Roster::studentCount; i++)
	{
	
	cout << classRosterArray[i]->getStudent_ID() << "\t";

	cout << setw(10) <<  (classRosterArray[i]->getFirstName()) << "\t";

	cout << setw(10) << (classRosterArray[i]->getLastName()) << "\t";

	cout << classRosterArray[i]->getEmail() << "\t";

	cout << classRosterArray[i]->getAge() << "\t";

	cout << "{" << *classRosterArray[i]->getDaysToCompletion() << ",";

	cout << *classRosterArray[i]->getDaysToCompletion() << ",";

	cout << *classRosterArray[i]->getDaysToCompletion() << "}\t";

	cout << degreeString[classRosterArray[i]->getDegreeInfo()] << "\t" << endl;
}
	cout << "\n";
}

void Roster::printInvalidEmails()
{
	cout << "Displaying Invalid Emails:" << endl << "\n";
	for (int i = 0; i <= studentCount; i++)
	{
		if (classRosterArray[i]->getEmail().find(" ") != string::npos || classRosterArray[i]->getEmail().find('@') == string::npos || classRosterArray[i]->getEmail().find('.') == string::npos)
		{
			cout << classRosterArray[i]->getEmail() << " - is invalid" << endl;
		}
	}
	cout << "\n";
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) 
{

	cout << "Showing students in the degree program: " << degreeString[degreeProgram] << endl;
	
	for (int i = 0; i <= studentCount; i++) 
	{ 
		if (classRosterArray[i]->getDegreeInfo() == degreeProgram)
		{
		classRosterArray[i]->print();
		}
	}
	cout << "\n";

}

void Roster::printAverageDaysInCourse(std::string studentID) {

	for (int i = 0; i <= studentCount; i++) 
	{

		if (studentID == classRosterArray[i]->getStudent_ID())
		{

			int average = (classRosterArray[i]->getDaysToCompletion()[0] + classRosterArray[i]->getDaysToCompletion()[1] + classRosterArray[i]->getDaysToCompletion()[2]) / 3;

			cout << "Student ID: " << classRosterArray[i]->getStudent_ID() << ", average days in course is: " <<  average << endl;
		}

	}
}

Roster::~Roster()
{
	for (int i = 0; i < 5; i++)
	{
		classRosterArray[i] = nullptr;
	}
	cout << "Destructor Called";
}
