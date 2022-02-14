#pragma once

#include <string>
#include <array>
#include "degree.h"

class student {
private:
	std::string student_id, firstName, lastName, email;
	int age;
	int daysToCompletion [3];
	DegreeProgram degreeProgram;

public:
	int *getDaysToCompletion();
	int getAge();
	std::string getStudent_ID();
	std::string getFirstName();
	std::string getLastName();
	std::string getEmail();
	DegreeProgram getDegreeInfo();

	void setDaysToCompletion(int daysToCompletion[]);
	void setAge(int age1);
	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setEmail(std::string email);
	void setDegreeProgram(DegreeProgram degreeProgram);

	student(
		std::string student_id,
		std::string firstName,
		std::string lastName,
		std::string email,
		int age,
		int daysToCompletion[],
		DegreeProgram degreeProgram
	);

	~student();

	void print();
};
