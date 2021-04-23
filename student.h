#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <string>
#include <iostream>

using namespace std;


class Student {
private:
	string degreeProgramStrings(DegreeProgram dp);
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int days[3];
	DegreeProgram degreeProgram;

public:
	Student();
	Student(string studentId, string firstName, string lastName, string emailAddress, int age, int days[3], DegreeProgram type);
	~Student();

	string getStudentId();
	string getFirstName();
	string getLastName(); 
	string getEmail();
	int getAge();
	int* getDays(); 
	DegreeProgram getDegreeProgram();

	void setStudentId(string studentId); 
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string emailAddress);
	void setAge(int studentAge);
	void setDays(int daysInCourse[]);
	void setDegreeProgram(DegreeProgram dp);
	virtual void print();
};

#endif
