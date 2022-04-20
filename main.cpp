#include <iostream>
#include <string>
#include "roster.h"
#include "degree.h"

using namespace std;

int main()
{
	//Personal student info
	cout << "***********************************************************" << endl;
	cout << "* C867 Scripting and Programming: Applications            *" << endl;
	cout << "* Language: C++                                           *" << endl;
	cout << "* Student ID: #000583145                                  *" << endl;
	cout << "* Name: Maggie M. Garcia                                  *" << endl;
	cout << "***********************************************************" << endl;

	const string classRosterArray[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Maggie,Garcia,mgar163@wgu.edu,39,35,20,40,SOFTWARE"
	};

	const int numStudents = 5;
	Roster classRoster;


	for (int i = 0; i < numStudents; i++) classRoster.parse(classRosterArray[i]);
	cout << "Displaying all students: " << endl;
	classRoster.printAll();
	cout << endl;

	cout << "Displaying invalid emails:" << endl;
	classRoster.printInvalidEmails();
	cout << endl;

	cout << "Displaying days in course: " << endl;
	for (int i = 0; 1 < numStudents; i++)
	{
		classRoster.printAverageDaysInCourse(classRosterArray[i]);
		break;
	}
	cout << endl;

	cout << "Showing students in degree program: SOFTWARE " << endl;
	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
	cout << endl;

	cout << "Removing students with ID: A3:" << endl;
	cout << "------------------------------" << endl;
	cout << "..." << endl;
	classRoster.removebyStudentID("A3");
		
	cout << "Removing students with ID: A3 again : " << endl;
	cout << "-------------------------------------" << endl;
	cout << "..." << endl;
	classRoster.removebyStudentID("A3");
	
	cout << "Done. Destructors will be called automatically upon exit." << endl;

	return 0;
}



/* F. Demonstrate the program’s required functionality by adding a main() function in main.cpp, 
	which will contain therequired function calls to achieve the following results:
1. Print out to the screen, via your application, the course title, the programming language used, your WGU studentID, and your name.
2. Create an instance of the Roster class called classRoster.
3. Add each student to classRoster.
4. Convert the following pseudo code to complete the rest of the main() function:
	classRoster.printAll();
	classRoster.printInvalidEmails();

**loop through classRosterArray and for each element:
classRoster.printAverageDaysInCourse(/*current_object's student id);
**Note: For the current_object's student id, use an accessor(i.e., getter) for the classRosterArray toaccess the student id.
	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");
**expected: the above line should print a message saying such a student with this IDwas not found.
5. Implement the destructor to release the memory that was allocated dynamically in Roster.
*/