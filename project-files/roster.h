#pragma once
#include "student.h"
using namespace std;

class Roster {
private:
	//Empty for now

public:
	//Constructor
	Roster();

	//Destructor
	~Roster();

	//Initializes pointers
	Student* classRosterArray[5];

	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string remove_student_ID);
	void printAll();
	void printAverageDaysInCourse(string student_id);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degree_to_print);
};