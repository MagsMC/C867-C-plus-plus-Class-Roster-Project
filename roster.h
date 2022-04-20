#pragma once
#ifndef ROSTER_H
#define ROSTER_H
#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"

using namespace std;


class Roster
{
private:
	int lastindex = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];

public:
	Student** getclassRosterArray();
	void parse(string row);
	void add(string ID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void printAll();
	void printInvalidEmails();
	void printAverageDaysInCourse(string studentID);
	void printByDegreeProgram(DegreeProgram degreeProgram);
	void removebyStudentID(string studentID);
	~Roster();

};

#endif



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