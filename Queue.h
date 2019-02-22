#ifndef QUEUE_H
#define QUEUE_H

//libraries used
#include "Patient.h"
#include <vector>
#include <iostream>
#include <locale>
#include <iomanip>
#include <stdlib.h>
using namespace std;

class Queue : public Patient{
public: //all private variables in patient structure
	//Queue class methods for each option
	vector<Patient> AddPatient(vector<Patient> & q);
	vector<Patient> AddCriticalPatient(vector<Patient> & q, int & critical);
	vector<Patient> Operate(vector<Patient> & q, int & critical);
	vector<Patient> RemovePatient(vector<Patient> & q, int & critical);
	void Print(vector<Patient>  q, const int & critical);
};

#endif
