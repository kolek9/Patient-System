#include "Patient.h"

//default constructor
Patient::Patient() {
	firstName = "";
	lastName = "";
	SSN = 0;
	isCriticallyIll = false;
}

//constructor with parameters, namely for critical patients
Patient::Patient(const string & first, const string & last, const int & ssnum, bool isCriticallyIllcheck)
{
	firstName = first;
	lastName = last;
	SSN = ssnum;
	isCriticallyIll = isCriticallyIllcheck;
}
//constructor for non-critical patients
Patient::Patient(const string & first, const string & last, const int & ssnum)
{
	firstName = first;
	lastName = last;
	SSN = ssnum;
	isCriticallyIll = false;
}
//getter and setter for critically ill
bool Patient::getCriticallyIll()
{
	return isCriticallyIll;
}

void Patient::setCriticallyIll(const bool & ill)
{
	isCriticallyIll = ill;
}

//getters for name and ssn since those shouldn't be changeable
string Patient::getfirst()
{
	return firstName;
}

string Patient::getlast()
{
	return lastName;
}

int Patient::getSSN()
{
	return SSN;
}

//overwritten ostream operator to output patients
ostream & operator<<(ostream & out, Patient p)
{
	out << p.firstName << " " << p.lastName << " " << p.SSN << endl;
	return out;
}
