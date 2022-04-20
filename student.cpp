#include <iostream>
#include "student.h"
#include "degree.h"
#include <string>

using namespace std;

Student::Student()
{
	this->studentID = "";
	this->firstname = "";
	this->lastname = "";
	this->emailaddress = "";
	this->age = ' ';
	for (int i = 0; i < daysArrayincourse; i++) this->daysincourse[i] = 0;
	this->degreeProgram = DegreeProgram::NETWORK;
}

Student::Student(string studentID, string firstname, string lastname, string emailaddress, int age, int daysincourse[], DegreeProgram degreeProgram)
//Full constructor
{
	
	this->studentID = studentID;
	this->firstname = firstname;
	this->lastname = lastname;
	this->emailaddress = emailaddress;
	this->age = age;
	for (int i = 0; i < daysArrayincourse; i++) this->daysincourse[i] = daysincourse[i]; 
	this->degreeProgram = degreeProgram;

}

Student::~Student() {} //Destructor

void Student::printHeader()
{
	cout << "ID - ";
	cout << "FirstName - ";
	cout << "LastName - ";
	cout << "Age - ";
	cout << "DaysInCourse1 - ";
	cout << "DaysInCourse2 - ";
	cout << "DaysInCourse3 - ";
	cout << "Program - ";
	cout << endl;
}

void Student::print()
{
	cout << this->studentID << '\t';
	cout << this->firstname << '\t';
	cout << this->lastname << '\t'; '\t';
	cout << this->age << '\t'; 
	cout << "{" << this->daysincourse[0] << '\t';
	cout << this->daysincourse[1] << '\t';
	cout << this->daysincourse[2] << "}" << '\t';
	cout << degreeProgramStrings[(int)this->degreeProgram];
	cout << endl;
}

//getters
string Student::getID() { return this->studentID; }
string Student::getFirstName() { return this->firstname; }
string Student::getLastName() { return this->lastname; }
string Student::getEmailAddress() { return this->emailaddress; }
int Student::getAge() { return this->age; }
int* Student::getDaysInCourse() { return this->daysincourse; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

//setters
void Student::setID(string ID) { this->studentID = ID; }
void Student::setFirstName(string firstname) { this->firstname = firstname; }
void Student::setLastName(string lastname) { this->lastname = lastname; }
void Student::setEmailAddress(string emailaddress) { this->emailaddress = emailaddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysInCourse(int daysincourse[])
{
	for (int i = 0; i < daysArrayincourse; i++) this->daysincourse[i] = daysincourse[i];
}
void Student::setDegreeProgram(DegreeProgram degreeProgram)
{
	this->degreeProgram = degreeProgram;
}



/* D2. Create each of the following functions in the Student class:
a. an accessor (i.e., getter) for each instance variable from part D1
b. a mutator (i.e., setter) for each instance variable from part D1
c. All external access and changes to any instance variables of the Student
class must be done using accessorand mutator functions.
d. constructor using all of the input parameters provided in the table
e. print() to print specifi c student data
*/
