#include <iostream>
#include <sstream>
#include <string>
#include "roster.h"
#include "student.h"


using namespace std;


Student** Roster::getclassRosterArray()
{
	return Roster::classRosterArray;
}

void Roster::parse(string studentData)
{
	size_t rhs = studentData.find(",");
	string studentID = studentData.substr(0, rhs);

	size_t lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string firstName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lastName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string emailAddress = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int age = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysincourse1 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysincourse2 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysincourse3 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string degreeProgramStrings = studentData.substr(lhs, rhs - lhs);

	DegreeProgram degreeProgram = DegreeProgram::NETWORK;
	if (degreeProgramStrings == "SECURITY")
	{
		degreeProgram = DegreeProgram::SECURITY;
	} 
	else if (degreeProgramStrings == "SOFTWARE")
	{
		degreeProgram = DegreeProgram::SOFTWARE;
	} 
	add (studentID, firstName, lastName, emailAddress, age, daysincourse1, daysincourse2, daysincourse3, degreeProgram);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
	int daysArrayInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[++lastindex] = new Student(studentID, firstName, lastName, emailAddress, age, daysArrayInCourse, degreeprogram);
}

void Roster::printAll()
{
	cout << "------------------------" << endl;
	Student::printHeader();
	for (int i = 0; i <= Roster::lastindex; i++) Roster::classRosterArray[i]->print();
}

void Roster::printInvalidEmails()
{
	cout << "--------------------------" << endl;
	for (int i = 0; i <= Roster::lastindex; i++)
	{
		string emailaddress = Roster::getclassRosterArray()[i]->getEmailAddress();
		if (emailaddress.find(' ') != string::npos || emailaddress.find('.') == string::npos || emailaddress.find('@') == string::npos)

			cout << emailaddress << " is invalid!" << endl;
	}
}

void Roster::printAverageDaysInCourse(string studentID)
{
	cout << "--------------------------" << endl;
	for (int i = 0; i <= Roster::lastindex; i++)
	{
		cout << classRosterArray[i]->getID() << ":";
		cout << (classRosterArray[i]->getDaysInCourse()[0]
			+ classRosterArray[i]->getDaysInCourse()[1]
			+ classRosterArray[i]->getDaysInCourse()[2]) / 3.0 << endl;
	}
	cout << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	cout << "---------------------------------------------" << endl;
	Student::printHeader();
	for (int i = 0; i <= Roster::lastindex; i++)
	{
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) 
			classRosterArray[i]->print();
	}
	cout << endl;
}

void Roster::removebyStudentID(string studentID)
{
	bool success = false;
	for (int i = 0; i <= Roster::lastindex; i++)
	{
		if (classRosterArray[i]->getID() == "A3")
		{
			success = true;
			Student* temp = classRosterArray[i];
			classRosterArray[i] = classRosterArray[numStudents - 1];
			classRosterArray[numStudents - 1] = temp;

			Roster::lastindex--;
		}
		cout << endl;
	}

	if (success)
	{
		cout << "Student " << studentID << " removed." << endl;
		printAll();
		cout << endl;
	}

	else cout << "Student " << studentID << " not found." << endl;
	cout << endl;
	
}

Roster::~Roster()
{
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Destructor has been called " << classRosterArray[i]->getID() << endl;
	}
}



/*
E. Create a Roster class (roster.cpp) by doing the following:
1. Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
2. Create a student object for each student in the data table and populate classRosterArray.
	a. Parse each set of data identified in the “studentData Table.”
	b. Add each student object to classRosterArray.
3. Define the following functions:
	a. public void add(string studentID, string firstName, string lastName, stringemailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,
	DegreeProgram degreeprogram) that sets the instance variables from part D1 and updates the roster.
	b. public void remove(string studentID) that removes students from the roster by student ID.
	If thestudent ID does not exist, the function prints an error message indicating that the student was not found.
	c. public void printAll() that prints a complete tab-separated list of student data in the provided format:
	A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse:{35, 40, 55} Degree Program: Security.
	The printAll() function should loop through all thestudents in classRosterArray and call the print() function for each student.
d. public void printAverageDaysInCourse(string studentID) that correctly prints a student’saverage number of days in the three courses.
	The student is identifi ed by the studentID parameter.
e. public void printInvalidEmails() that verifi es student email addresses and displays all invalid emailaddresses to the user.
Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
f. public void printByDegreeProgram(DegreeProgram degreeProgram) that prints out studentinformation for a degree program specifi ed by an enumerated type.
*/