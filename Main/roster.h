#pragma once
#include <iostream>
#include "student.h"
#include "degree.h"
#include <array>


class Roster {
public:
	student *classRosterArray[5];
	int studentCount = -1;
	int tableSize = 5;

public:
	void add(std::string student_ID, std::string firstName, std::string lastName, std::string email,
		int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,
		DegreeProgram degreeProgram);
	void parse(std::string element);
	void remove(std::string studentID);
	void printAll();
	void printAverageDaysInCourse(std::string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	~Roster();


};