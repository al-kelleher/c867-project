#include <iostream>
#include "student.h"
#include "degree.h"
#include "roster.h"
using namespace std;

//Constructor for the student class
Student::Student() {
	//Variable initialization
	student_id = "";
	first_name = "";
	last_name = "";
	student_email = "";

	//initialize the array of integers for days to complete each course
	for (int i = 0; i < 3; i++) {
		day_to_complete[i] = i;
	}

	//Sets age variable to zero
	student_age = 0;

	//Intitializes degree program
	degree_program = NA;
}

//Student destructor
Student::~Student() {
	cout << "Student Destructor has ran." << endl;
}

//Setters
void Student::set_student_id(string new_student_id) { this->student_id = new_student_id; }
void Student::set_first_name(string new_first_name) { this->first_name = new_first_name; }
void Student::set_last_name(string new_last_name) { this->last_name = new_last_name; }
void Student::set_student_email(string new_student_email) { this->student_email = new_student_email; }
void Student::set_student_age(int new_student_age) { this->student_age = new_student_age; }
void Student::set_degree_program(DegreeProgram new_degree_program) { this->degree_program = new_degree_program; }

//Setter for the days to complete
void Student::set_day_to_complete(int* new_day_to_complete) {
	for (int k = 0; k < 3; k++) {
		this->day_to_complete[k] = new_day_to_complete[k];
	}
}

//Getters
string Student::get_student_id() { return this->student_id; }
string Student::get_first_name() { return this->first_name; }
string Student::get_last_name() { return this->last_name; }
string Student::get_student_email() { return this->student_email; }
int Student::get_student_age() { return this->student_age; }
DegreeProgram Student::get_degree_program() { return this->degree_program; }
int* Student::get_day_to_complete() { return this->day_to_complete; }

void Student::print() {
	cout << this->student_id << "\t" << flush;
	cout << this->first_name << "\t" << flush;
	cout << this->last_name << "\t" << flush;
	cout << this->student_age << "\t" << flush;

	//Prints days to complete
	cout << "{" << this->day_to_complete[0] << ", " << this->day_to_complete[1] << ", " << this->day_to_complete[2] << "}" << " \t" << flush;

	//Dereferences enum
	string print_degree_array[] = { "SECURITY", "SOFTWARE", "NETWORK", "NA" };
	cout << print_degree_array[this->degree_program] << "\t" << endl;;
}


