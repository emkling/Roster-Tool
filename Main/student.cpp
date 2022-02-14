#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;

student::student (string student_id, string firstName, string lastName, string email,
	int age, int daysToCompletion[],
	DegreeProgram degreeProgram) {

	this->student_id = student_id;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	this->daysToCompletion[0] = daysToCompletion[0];
	this->daysToCompletion[1] = daysToCompletion[1];
	this->daysToCompletion[2] = daysToCompletion[2];
	this->degreeProgram = degreeProgram;
}

//Mutator Functions
void student::setDaysToCompletion(int daysToCompletion[]){

	this->daysToCompletion[0] = daysToCompletion[0];
	this->daysToCompletion[1] = daysToCompletion[1];
	this->daysToCompletion[2] = daysToCompletion[2];
}

void student::setAge(int age) {

	this->age = age;
}

void student::setFirstName(string firstName) {
	this->firstName = firstName;
}

void student::setLastName(string lastName) {
	this->lastName = lastName;
}

void student::setEmail(string email) {
	this->email = email;
}

void student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}


//Accessor Functions

string student::getStudent_ID() {

	return student_id;

}

string student::getFirstName() {
	
	return firstName;

}

string student::getLastName() {

	return lastName;
}

string student::getEmail() {

	return email;
}

int student::getAge() {

	return age;
}

int* student::getDaysToCompletion() {

	return daysToCompletion;
}


DegreeProgram student::getDegreeInfo() {

	return degreeProgram;
}

//Print Function

void student::print()
{
	cout << getStudent_ID() << "\t";
	cout << getFirstName() << "\t";
	cout << getLastName() << "\t";
	cout << getEmail() << "\t";
	cout << getAge() << "\t";
	cout << "{" << getDaysToCompletion()[0] << ",";
	cout << getDaysToCompletion()[1] << ",";
	cout << getDaysToCompletion()[2] << "}\t";
	cout << degreeString[getDegreeInfo()] << endl;
}
