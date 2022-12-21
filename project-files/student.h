#pragma once
#include "degree.h"
using namespace std;

//Student class is defined
class Student {
private:
	string student_id, first_name, last_name, student_email;
	int student_age;
	int day_to_complete[3]; //Int array of days
	DegreeProgram degree_program;

public:
	Student(); //Constructor
	~Student(); //Destructor

	//Defines the set methods for each class variable
	void set_student_id(string new_student_id);
	void set_first_name(string new_first_name);
	void set_last_name(string new_last_name);
	void set_student_email(string new_student_email);
	void set_student_age(int new_student_age);
	void set_degree_program(DegreeProgram new_degree_program);
	void set_day_to_complete(int* new_day_to_complete);

	//Defines getters for each private class variable
	string get_student_id();
	string get_first_name();
	string get_last_name();
	string get_student_email();
	int get_student_age();
	DegreeProgram get_degree_program();
	int* get_day_to_complete();

	//Defines the print method for student class
	void print();
};