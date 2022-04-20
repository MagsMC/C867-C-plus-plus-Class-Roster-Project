#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include "degree.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
using std::string;
using std::cout;
using std::endl;

class Student
{
public:
	const static int daysArrayincourse = 3;  /*Array*/
private:
	string studentID;
	string firstname;
	string lastname;
	string emailaddress;
	int age;
	int daysincourse[daysArrayincourse];
	DegreeProgram degreeProgram;
public:
	Student();
	Student(string studentID, string firstname, string lastname, string emailaddress, int age, int Daysincourse[], DegreeProgram degreeProgram);
	~Student();

	/*accessors*/
	string getID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysInCourse();
	DegreeProgram getDegreeProgram();

	/*mutators*/
	void setID(string ID);
	void setFirstName(string firstname);
	void setLastName(string lastname);
	void setEmailAddress(string emailaddress);
	void setAge(int age);
	void setDaysInCourse(int daysincourse[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	static void printHeader();

	void print();
};

#endif


/* D. For the Student class, do the following:
1. Create the class Student in the files student.h and student.cpp, which includes each of the following variables:
• student ID
• first name
• last name
• email address
• age
• array of number of days to complete each course
• degree program
*/