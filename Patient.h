#ifndef PATIENT_H
#define PATIENT_H

//libraries used
#include <string>
#include <stdlib.h>
using namespace std;

//Patient sturucture
struct Patient {
	//private variables
	string firstName;
	string lastName;
	int SSN;
	bool isCriticallyIll;
	//constructors and basic functions
	Patient();
	Patient(const string & first, const string & last, const int & ssnum, bool isCriticallyIllcheck);
	Patient(const string & first, const string & last, const int & ssnum);
	bool getCriticallyIll();
	void setCriticallyIll(const bool & ill);
	//no setters for the others because names and Social Security cannot be changed
	string getfirst();
	string getlast();
	int getSSN();
	friend ostream & operator<<(ostream & out, Patient p);
};

#endif
