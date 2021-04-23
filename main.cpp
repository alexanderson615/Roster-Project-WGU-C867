
#include <iostream>
#include "roster.h"

using namespace std;


int main() {
	const string studentData[] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY"		,
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK"	,
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE"		,
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY"		,
	"A5,Alex,Anderson,Aander815@wgu.edu,20,20,30,40,SOFTWARE"
	};
	string temp;
	const int numStudents = 5;
	int j;

	cout << endl << "Scripting & Programming: Applications, C++,  Stud# 001516980,  Alex W Anderson" << endl;

	Roster roster(numStudents);

	for (int i = 0; i < numStudents; i++) {
		roster.parse(studentData[i]);		
	}

	roster.printAll();
	roster.printInvalidEmails();

	for (int i = 0; i < numStudents; i++) {
		j = 0;
		temp = "";
		while (studentData[i][j] != ',') {
			temp += studentData[i][j];
			j++;
		}
		roster.printAverageDaysInCourse(temp);
	}
		
	roster.printByDegreeProgram(DegreeProgram::SOFTWARE);
	roster.remove("A3");
	roster.printAll();
	roster.remove("A3");
	return 0;
}
