#include "roster.h"
#include <iomanip>

Roster::Roster(int numberOfStudents) {
	classRosterArray = new Student*[numberOfStudents];
	numStudents = numberOfStudents;

	for (int i = 0; i < numberOfStudents; i++) {
		classRosterArray[i] = nullptr;
	}
}

Roster::~Roster() {
	for (int i = 0; i < numStudents; i++) {
		if (classRosterArray[i] != nullptr) {
			delete classRosterArray[i];
		}
	}
	delete [] classRosterArray;
}


// Parse the row data, extract a student's data and add a student object
void Roster::parse(string row) //studentInfo)
{
	string ID, first, last, email;
	int age;
	int days[3];
	string data[9];
	DegreeProgram dp;
	int count = 0;
	unsigned int i;

	for (i = 0; i < row.length(); i++) {
		if (row[i] == ',') {
			count++;
		}		
		else {
			data[count] += row[i];
		}
	}

	ID = data[0];
	first = data[1];
	last = data[2];
	email = data[3];

	age = stoi(data[4]);
	days[0] = stoi(data[5]);
	days[1] = stoi(data[6]);
	days[2] = stoi(data[7]);
	string degree = data[8];

	if (degree == "NETWORK") {
		dp = DegreeProgram::NETWORKING;
	}
	else if (degree == "SOFTWARE") {
		dp = DegreeProgram::SOFTWARE;
	}
	else {
		dp = DegreeProgram::SECURITY;
	}

	add(ID, first, last, email, age, days[0], days[1], days[2], dp);
}

void Roster::printAll() {
	cout << endl;
	for (int j = 0; j < numStudents; ++j) {
		classRosterArray[j]->print();		
	}	
}


void Roster::remove(string studentID) {
	cout << endl;
	cout << " Removing student " << studentID << endl;

	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i]->getStudentId() == studentID) {
			delete classRosterArray[i];
			for (; i < numStudents - 1; i++) classRosterArray[i] = classRosterArray[i + 1];
			classRosterArray[numStudents - 1] = nullptr;
			numStudents--;
			return;
		}
	}

	cout << " Error: Student not found." << endl;	
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram type) {
	int i;

	int days[3];
	days[0] = daysInCourse1;
	days[1] = daysInCourse2;
	days[2] = daysInCourse3;

	Student* student = new Student(studentID, firstName, lastName, emailAddress, age, days, type);
		
	//Add student to classRoster array
	for (i = 0; i < numStudents; i++) {
		if (classRosterArray[i] == nullptr) {
			classRosterArray[i] = student;
			break;
		}
	}
}



void Roster::printInvalidEmails() {
	cout << endl << "\n Invalid emails list:" << endl;
	int sign, dot, space;
	bool validEmail;
	string email;
	int count = 1;

	for (int i = 0; i < numStudents; ++i) {
		email = classRosterArray[i]->getEmail();
		validEmail = true;
		sign = email.find('@');
		space = email.find(' ');		
		dot = email.find_last_of('.');
	
		if (sign == string::npos ||  space != string::npos ||  dot == string::npos)
			validEmail = false;
		else if (sign > dot) {
			validEmail = false;
		}else if (sign == 0) {
			validEmail = false;
		}

		if (validEmail == false) {
			cout << count++ << " " << email << endl;
		}
	}
	cout << endl;
}

void Roster::printAverageDaysInCourse(string studentID) {
	float averageDays;
	//cout << endl;
	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i]->getStudentId() == studentID) {
			cout << "Student ID: " << classRosterArray[i]->getStudentId();
			int* tempDays = classRosterArray[i]->getDays();			
			averageDays = (tempDays[0] + tempDays[1] + tempDays[2]) / 3.0f;
			cout << "\tAverage number of days: " << fixed <<  setprecision(1) <<  averageDays << endl;
			return;
		}
	}
}

string Roster::degreeProgramStrings(DegreeProgram dp)
{
	if (dp == DegreeProgram::NETWORKING)
		return "Networking";
	else if (dp == DegreeProgram::SECURITY)
		return "Security";
	else
		return "Software";
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	int count = 0;
	
	cout << "\n The students in " << degreeProgramStrings(degreeProgram) << " are:\n";

	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			count++;
			cout << count << " ";
			classRosterArray[i]->print();
		}
	}	
}
