#include "Queue.h"

//add a patient function
vector<Patient> Queue::AddPatient(vector<Patient> & q) {
	int fail = 0;//fail int to skip adding patient if wrong input 
	string leave;
	//new screen
	system("CLS");
	cout << flush;
	string first, last;
	int ss;
	cout << "You picked : Add Patient\n";
	if (q.size() < 100) { //ensures size of vector is less than 100
		cout << "Please enter the patient's first name : \n";
		cin >> first;
		while (true) {
			bool is_alph = true;
			for (int i = 0; i < first.length(); i++) { //loop to make sure name is only alpha characters
				if (isalpha(first[i]) == false) {
					is_alph = false;
					break;
				}
			}
			if (is_alph == false) {
				cout << "Invalid response! Cancelling patient\n";
				cout << "Enter any key to return to the main menu\n";
				string accept;
				cin >> accept;
				fail = -1; //if not alpha fail is assigned -1
				break;
			}
			else if (is_alph == true) {
				break;
			}
		}
		if (fail != -1) { //since there were non-alpha characters already, skips the last name and ssn
			cout << "Please enter the patient's last name : \n";
			cin >> last;
			while (true) {
				bool is_alph = true;
				for (int i = 0; i < last.length(); i++) { //checks to see if all name characters are of alpha type
					if (isalpha(last[i]) == false) {
						is_alph = false;
						break;
					}
				}
				if (is_alph == false) {
					cout << "Invalid Response! Cancelling patient\n";
					cout << "Enter any key to return to the main menu\n";
					string accept;
					cin >> accept;
					fail = -1; //if wrong input on last name, will still assign fail to skip ssn and adding of patient to vector
					break;
				}
				else if (is_alph == true) {
					break;
				}
			}
		}
		if (fail != -1) { //if there was a fail before don't ask for social security number
			cout << "Please enter the patient's social security number : \n";
			cin >> ss;
			if (cin.fail()){//makes sure integer is input
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				ss = -1;
			}
			//exits if social security # is negative
			if (ss <= 0) {
				cout << "\nInvalid response, cancelling patient!\n";
				cout << "Enter any key to return to the main menu\n";
				string accept;
				cin >> accept;
			}
			//makes sure social security # is positive before adding patient to vector
			if (ss > 0) {
				q.push_back(Patient(first, last, ss));
				system("CLS");
				cout << flush;
				cout << "You added patient : " << first << " " << last << " " << ss << endl;
				string temp;
				cout << "Press any key to return to the main menu\n";
				cin >> temp;
			}
		}
	}
	//if size is > 100 then output a full queue message
	else {
		cout << "Queue is full!\n";
		cout << "Enter any key to return to the main menu!\n";
		cin >> leave;
	}
	return q; //return final vector
}

vector<Patient> Queue::AddCriticalPatient(vector<Patient> & q, int & critical)
{
	//fail state integer
	int fail = 0;
	string leave;
	//first clears screen
	system("CLS");
	cout << flush;
	string first, last;
	int ss;
	cout << "You picked : Add Critically Ill Patient\n";
	if (q.size() < 100) { //makes sure vector is under size limit first
		cout << "Please enter the patient's first name : \n";
		cin >> first;
		while (true) { //makes sure name is only alpha characters
			bool is_alph = true;
			for (int i = 0; i < first.length(); i++) {
				if (isalpha(first[i]) == false) {
					is_alph = false;
					break;
				}
			}
			if (is_alph == false) { //if not all alpha, cancel adding patient
				cout << "Invalid response! Cancelling patient\n";
				cout << "Enter any key to return to the main menu\n";
				string accept;
				cin >> accept;
				fail = -1; // fail state on
				break;
			}
			else if (is_alph == true) {
				break;
			}
		}
		cout << "Please enter the patient's last name : \n";
		if(fail != -1){
		cin >> last;
		while (true) {//makes sure the name is only alpha characters
			bool is_alph = true; 
			for (int i = 0; i < last.length(); i++) {
				if (isalpha(last[i]) == false) {
					is_alph = false;
					break;
				}
			}
			if (is_alph == false) { //if not all alpha, stop adding patient
				cout << "Invalid response! Cancelling patient\n";
				cout << "Enter any key to return to the main menu\n";
				string accept;
				cin >> accept;
				fail = -1; //fail state on
				break;

			}
			else if (is_alph == true) {
				break;
			}
		}
	}
		//if no failures try social security number
		if (fail != -1) {
			cout << "Please enter the patient's social security number : \n";
			cin >> ss;
			if (cin.fail()) { //makes sure only integer is entered
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				ss = -1;
			}
			if (ss <= 0) { //if fail is on or negative social security, exit to menu
				cout << "\nInvalid response, cancelling patient!\n";
				cout << "Enter any key to return to the main menu\n";
				string accept;
				cin >> accept;
			}
			if (ss > 0) { //if not fail or negative social security, add patient to vector 
				Patient p(first, last, ss, true);
				q.insert(q.begin() + critical, p); //makes sure patient is above non-critical, but behind other critical patients
				system("CLS");
				cout << flush; //new screen
				cout << "You added critical patient : " << first << " " << last << " " << ss << endl;
				string temp;
				cout << "Enter any key to return to the main menu!\n";
				cin >> temp;
			}
		}
	}
	else { //message if queue is full
		cout << "Queue is full!\n";
		cout << "Enter any key to return to the main menu!\n";
		cin >> leave;
	}
	critical = critical + 1; //adds to critical patients
	return q; //return final vector
}

vector<Patient> Queue::Operate(vector<Patient> & q, int & critical)
{
	string leave;
	system("CLS"); //new screen
	cout << flush;
	cout << "You chose : Take out patient to operate\n";
	if (q.size() == 0) { //message if there are no patients
		cout << "\nNo more patients!\n";
		cout << "\nEnter any key to go to the main menu!\n";
		cin >> leave;
	}
	//if first patient was critical, remove them and decriment critical number of patients
	else if (q.front().getCriticallyIll()) {
		critical--;
		cout << "Patient going to operating room : ";
		cout << q.front() << endl; //output front of vector
		cout << "Enter any key to go back to the main menu!\n";
		cin >> leave;
		q.erase(q.begin()); //remove from front of vector
	}
	else if (q.front().getCriticallyIll() == false) { //if not critical patient just remove 
		cout << "Patient going to operating room : ";
		cout << q.front() << endl; //outputs first patient in queue
		cout << "Enter any key to go back to the main menu!\n";
		cin >> leave;
		q.erase(q.begin()); //deletes first patient in queue
	}
	return q; //returns updated vector
}

vector<Patient> Queue::RemovePatient(vector<Patient> & q, int & critical)
{
	//fail state integer
	int fail = 0;
	//first clears screen
	system("CLS");
	cout << flush;
	string first, last;
	int ss;
	cout << "You picked : Remove Patient\n";
	cout << "Please enter the patient's first name : \n";
	cin >> first;
	while (true) { //checks to make sure name is only alpha
		bool is_alph = true;
		for (int i = 0; i < first.length(); i++) {
			if (isalpha(first[i]) == false) {
				is_alph = false;
				break;
			}
		}
		//quits searching if name is not all alpha
		if (is_alph == false) {
			cout << "Invalid response! Cancelling patient search\n";
			cout << "Enter any key to return to the main menu\n";
			string accept;
			cin >> accept;
			fail = -1; //fail state on 
			break;
		}
		else if (is_alph == true) {
			break;
		}
	}
	if (fail != -1) { //if fail don't continue with last name
		cout << "Please enter the patient's last name : \n";
		cin >> last;
		while (true) {
			bool is_alph = true; //makes sure last name is all alpha
			for (int i = 0; i < last.length(); i++) {
				if (isalpha(last[i]) == false) {
					is_alph = false;
					break;
				}
			}
			//quits searching if name is not all alpha
			if (is_alph == false) {
				cout << "Invalid Response! Cancelling patient search\n";
				cout << "Enter any key to return to the main menu\n";
				string accept;
				cin >> accept;
				fail = -1; //fail state on 
				break;

			}
			else if (is_alph == true) {
				break;
			}
		}
	}
	if (fail != -1) {
		cout << "Please enter the patient's social security number : \n";
		cin >> ss;
		//makes sure only integer is input
		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			ss = -1;
		}
		if (ss <= 0) { //stops searching if negative/invalid social security #
			cout << "\nInvalid response, cancelling patient search!\n";
			cout << "Enter any key to return to the main menu\n";
			string accept;
			cin >> accept;
		}
		//if names and social security are valid, add patient to vector/queue
		if (ss > 0) {
			Patient s(first, last, ss);
			int count = 0;
			int size = q.size();
			for (vector<Patient>::iterator iter = q.begin(); iter != q.end(); iter++) { //iterates through vector looking for patient
				if (iter->getfirst() == s.getfirst() && iter->getlast() == s.getlast() && iter->getSSN() == s.getSSN()) {
					q.erase(q.begin() + count); //when patient is found remove them from queue vector
					cout << "\nPatient removed!\n";
					cout << "Enter any key to return to the main menu!\n";
					string accept;
					cin >> accept;
					break;
				}
				count++;
			}
			if (count == size) { //when patient is found counter stops, so if the counter is the same as the vector size, the patient wasn't found
				cout << "\nPatient does not exist!\n";
				cout << "Enter any key to return to the main menu!\n";
				string accept;
				cin >> accept;
			}
		}
	}

	return q; //return final vector
}
//print function definition
void Queue::Print(vector<Patient> q, const int & critical)
{
	//first clears the screen
	system("CLS");
	cout << flush;
	cout << "You chose : List the queue of patients\n";
	//outputs message if no patients
	if (q.size() == 0) {
		cout << "\nNo patients in the queue!\n";
	}
	if (q.size() > 0) {
		cout << "First    Last     Social Security Number" << endl<< endl;
		//first outputs the number and list of critical patients in order of checkout time
		cout << "Number of critical patients: " << critical << endl;
		for (vector<Patient>::iterator iter = q.begin(); iter != q.begin() + critical; iter++) {
			cout << *iter << endl;
		}
		//next outputs the number and list of non-critical patients in order of checkout time
		cout << "Number of non-critical patients: " << (q.size() - critical) << endl;
		for (vector<Patient>::iterator iter = q.begin() + critical; iter != q.end(); iter++) {
			cout << *iter << endl;
		}
	}
	//leave message
	string leave;
	cout << "Enter any key to go back to the main menu!\n";
	cin >> leave;
}