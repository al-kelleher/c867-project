#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "roster.h"
#include "degree.h"
using namespace std;

const string studentData[] =
{ 
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Alfred,Kelleher,akel596@wgu.edu,23,53,30,55,SOFTWARE" 
};

//String for dereferencing the enum
string degree_array[] = { "SECURITY", "SOFTWARE", "NETWORK", "NA" };

//Sets the size of the table for use in loop increases
int table_size = sizeof(studentData) / sizeof(string);

//Constructor for roster object
Roster::Roster() {
	//Puts a new student for each position in the array of pointers and adds that from studentData
	for (int i = 0; i < table_size; i++) {
		classRosterArray[i] = new Student;

		//Temp var for parsing
		string temp_student_id, temp_first_name, temp_last_name, temp_student_email, age_string, day0_string, day1_string, day2_string, degree_string;
		int temp_student_age, temp_day0, temp_day1, temp_day2;
		DegreeProgram temp_degree = NA;

		int temp_day_to_complete[3];

		stringstream input_stream; //A string stream that stores the single line from the student data table to the following string stream in the next line
		input_stream << studentData[i];

		char delimit = ',';

		//Creates a temporary student object to parse the string data
		Student* ptr_student;
		ptr_student = new Student;

		//Recieves each item from the string stream as seperated by the delimiting character and then sets it using the setter for the student object
		getline(input_stream, temp_student_id, delimit);
		ptr_student->set_student_id(temp_student_id);

		getline(input_stream, temp_first_name, delimit);
		ptr_student->set_first_name(temp_first_name);

		getline(input_stream, temp_last_name, delimit);
		ptr_student->set_last_name(temp_last_name);

		getline(input_stream, temp_student_email, delimit);
		ptr_student->set_student_email(temp_student_email);

		getline(input_stream, age_string, delimit);
		temp_student_age = stoi(age_string);
		ptr_student->set_student_age(temp_student_age);


		//Recieves the total days to complete classes
		getline(input_stream, day0_string, delimit);
		temp_day0 = stoi(day0_string);
		temp_day_to_complete[0] = stoi(day0_string);

		getline(input_stream, day1_string, delimit);
		temp_day1 = stoi(day1_string);
		temp_day_to_complete[1] = stoi(day1_string);

		getline(input_stream, day2_string, delimit);
		temp_day2 = stoi(day2_string);
		temp_day_to_complete[2] = stoi(day2_string);

		//Sets the full days to complete using a populated array
		ptr_student->set_day_to_complete(temp_day_to_complete);

		//Recieves the string related to the degree
		getline(input_stream, degree_string, delimit);

		//if-else statements that assign the matching degree program to the enum value
		if (degree_string == "SECURITY")
			temp_degree = SECURITY;
		else if (degree_string == "NETWORK")
			temp_degree = NETWORK;
		else if (degree_string == "SOFTWARE")
			temp_degree = SOFTWARE;
		else
			temp_degree = NA;

		//Sets the enum value for the degree program for the pointer student
		ptr_student->set_degree_program(temp_degree);

		//Sets the temporary student object to the appropriate position in the roster array
		classRosterArray[i] = ptr_student;
	}
}


//Destructor for releasing memory and declares that the destructor has ran
Roster::~Roster() { cout << "Roster Destructor has ran." << endl; }


//Loops through each item and calls the print function from the student method
void Roster::printAll() {
	for (int i = 0; i < table_size; i++) {
		classRosterArray[i]->print();
	}
}

void Roster::remove(string remove_student_ID) {
	//A boolean flag to determine if the ID has been found
	bool found_flag = false;

	for (int i = 0; i < table_size; i++) {
		if (classRosterArray[i]->get_student_id() == remove_student_ID) {
			found_flag = true; //Found flag gets set to true

			table_size = table_size - 1; //Reduces the table size as we are removing one element

			//Loop starts where the ID was found and shifts every item
			for (int j = i; j < table_size; j++) {
				classRosterArray[j] = classRosterArray[j + 1];
			}
		}
	}
	//Reports ID was not found 
	if (found_flag == false) { cout << "The Student ID was not found" << endl; }
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
	table_size++; //Increments table size
	int a = table_size - 1;

	int days_array[3]; //Temp array

	//Temp object
	Student* add_student;
	add_student = new Student;


	//Setter for strings and age
	add_student->set_student_id(studentID);
	add_student->set_first_name(firstName);
	add_student->set_last_name(lastName);
	add_student->set_student_email(emailAddress);
	add_student->set_student_age(age);

	//Populates temp array with integers given
	days_array[0] = daysInCourse1;
	days_array[1] = daysInCourse2;
	days_array[2] = daysInCourse3;

	//Sets the days to complete array by passing the temporary array to the setter
	add_student->set_day_to_complete(days_array);

	//Sets the degree program based on the passed in value
	add_student->set_degree_program(degreeprogram);

	//Set the new spot in the array to the values of the temporary student
	classRosterArray[a] = add_student;
}

void Roster::printInvalidEmails() {

	bool valid_email = true;
	bool valid_char = true;
	string email_search;
	size_t found; //Will point to the position in the string where the character was found or at the end of the string if it was not found

	for (int i = 0; i < table_size; i++) {

		//Base condition at the start of the for-loop
		valid_email = true;
		valid_char = true;

		//Putting the objects email into a string
		email_search = classRosterArray[i]->get_student_email();

		//Looks for the email string @
		found = email_search.find("@");

		//Invalid if this is found after the length of the email
		if (found > email_search.length()) { valid_email = false; }

		//If @ symbol is located this if statement will then check if the next character is valid
		if (found < email_search.length()) {
			found++; //Increments found by one
			valid_char = isalnum(email_search[found]);
		}

		if (valid_char == false) { valid_email = false; } //If a valid character isnt located then the email is invalid

		//Looks in the email string for . (period)
		found = email_search.find(".");
		if (found > email_search.length()) { valid_email = false; }


		//Looks for a blank spaces in the email string
		found = email_search.find(" ");
		if (found < email_search.length()) { valid_email = false; }

		//Prints invalid emails
		if (valid_email == false) {
			cout << email_search << "\t" << "- is invalid." << endl;

		}
	}
}

void Roster::printAverageDaysInCourse(string student_id) {

	for (int i = 0; i < table_size; i++) {

		int day0, day1, day2; //Int declaration
		double avg;
		string id = classRosterArray[i]->get_student_id(); //Gets the student ID based on the loop iteration

		//Assigns the values from the student object to the local integer variable
		day0 = classRosterArray[i]->get_day_to_complete()[0];
		day1 = classRosterArray[i]->get_day_to_complete()[1];
		day2 = classRosterArray[i]->get_day_to_complete()[2];

		avg = (day0 + day1 + day2) / 3.0;

		if (id == student_id) {
			cout << "Student ID: " << id << ", average days in course is: - " << avg << endl;

		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degree_to_print) {

	cout << "Students In " << degree_array[degree_to_print] << " Degree Program:\n" << endl;

	int student_count = 0;
	DegreeProgram local_degree;

	for (int i = 0; i < table_size; i++) {

		//Sets a local variable in the function to the value of the degree program for the studen being checked
		local_degree = classRosterArray[i]->get_degree_program();

		//If the student matches then print
		if (local_degree == degree_to_print) {

			classRosterArray[i]->print();
			student_count++;
		}
	}
	//Displays a message if no valid students are found
	if (student_count == 0) { cout << "No valid students found" << endl; }
}