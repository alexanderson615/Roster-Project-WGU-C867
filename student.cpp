
#include "student.h"

Student::Student() : studentID(""), firstName(""), lastName(""), email(""), age(0) {
	degreeProgram = DegreeProgram::NETWORKING;
	for (int i = 0; i < 3; i++) {
		days[i] = 0;
	}	
}

Student::Student(string ID, string first, string last, string emailAddress, int studentAge, int days[3], DegreeProgram type)
	: studentID(ID), firstName(first), lastName(last), email(emailAddress), age(studentAge)
{
	degreeProgram = type;
	this->days[0] = days[0];
	this->days[1] = days[1];
	this->days[2] = days[2];
}

string Student::getFirstName() {
	return firstName;
}

string Student::getLastName() {
	return lastName;
}

string Student::getStudentId() {
	return studentID;
}

string Student::getEmail() {
	return email;
}

int Student::getAge() {
	return age;
}

int* Student::getDays() {
	return days;
}

DegreeProgram Student::getDegreeProgram() {
	return degreeProgram;
}


void Student::setStudentId(string studentId) {
	studentId = studentId;
	return;
}

void Student::setFirstName(string firstName) {
	firstName = firstName;
	return;
}

void Student::setLastName(string lastName) {
	lastName = lastName;
	return;
}

void Student::setEmail(string emailAddress) {
	email = emailAddress;
	return;
}

void Student::setDays(int daysForCourse[]) {
	for (int i = 0; i < 3; i++) days[i] = daysForCourse[i];
}

void Student::setAge(int studentAge) {
	this->age = studentAge;
	return;
}

void Student::setDegreeProgram(DegreeProgram dp)
{
	degreeProgram = dp;
}

string Student::degreeProgramStrings(DegreeProgram dp)
{
	if (dp == DegreeProgram::NETWORKING)
		return "Networking";
	else if (dp == DegreeProgram::SECURITY)
		return "Security";
	else
		return "Software";
}

void Student::print() {	
	cout << getStudentId() << "\t";
	cout << "\t First Name: " << getFirstName() << "\t Last Name: " << getLastName();
	cout << "\t Age: " << getAge() ;
	cout << "\tdaysInCourse: {" << days[0] << ", " << days[1] << ", " << days[2] << "}";
	cout << " Degree Program: " << degreeProgramStrings(degreeProgram)	 << "." << endl;	
}

Student::~Student() {

}





