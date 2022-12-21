#include <iostream>
#include "Student.h"
#include "Degree.h"
#include "Roster.h"
using namespace std;

int main()
{
	cout << "C867-Scripting & Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 010175860" << endl;
	cout << "Name: Alfred Kelleher" << endl;
	cout << endl;

	Roster classRoster; //Creates roster class 

	//Prints the roster
	cout << "Displaying all Students: \n" << endl;
	classRoster.printAll();
	cout << endl;

	//Displays invalid emails
	cout << "Displaying Invalid Emails: \n" << endl;
	classRoster.printInvalidEmails();
	cout << endl;			  

	//Prints average days in course for each ID
	classRoster.printAverageDaysInCourse("A1");
	classRoster.printAverageDaysInCourse("A2");
	classRoster.printAverageDaysInCourse("A3");
	classRoster.printAverageDaysInCourse("A4");
	classRoster.printAverageDaysInCourse("A5");
	cout << endl;	

	//Prints students in SOFTWARE degree program
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl;	

	//Terminating ID A3	
	cout << "Removing A3." << endl;
	classRoster.remove("A3");

	//Prints the current roster again
	cout << endl;
	classRoster.printAll();
	cout << endl;

	//Removes A3 again, outputs error
	cout << "Removing A3, again. \n" << endl;
	classRoster.remove("A3");
	cout << endl;

	return(0);
}