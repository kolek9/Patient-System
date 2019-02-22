//This program is a simple hospital program. It will collect patients in departments, and track the queue. It prioritizes critical
//patients as well. You can add regular patients, critical patients, remove the first person in the queue for operation, remove
//a patient, or switch departments.
//input: There are multiple inputs. There are two menus, one for department, one for procedure within the department. Then you can
//enter patient names to add or remove them from the queue based on the prior selections
//output: The program can output the queue of patients with critical patients checking in first at the top of the list. 


//libraries used
#include "Queue.h"
#include "Patient.h"
#include <iomanip>
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

//vectors for each department
vector<Patient> Heart;
vector<Patient> Lung;
vector<Patient> Plastic;

//option function declaration
void options();
int main()
{
	//critical patient counters
	int criticalHeart = 0;
	int criticalLung = 0;
	int criticalPlastic = 0;

	while (true) {
		//option menu
		cout << setw(50) << "Welcome to Starling City Hospital!\n";
		cout << "1. Heart clinic\n";
		cout << "2. Lung clinic\n";
		cout << "3. Plastic surgery\n";
		cout << "4. Exit\n";
		cout << "Please enter your choice: \n";

		string choice, department;
		cin >> choice;
		//ensures that only one character is entered
		if (choice.length() != 1) {
			cout << "\nPlease only enter one character!\n";
			cout << "Enter any key to refresh!\n";
			string accept;
			cin >> accept;
			system("CLS");
			cout << flush;
		}
		//heart department
		else if (choice == "1") {
			department = "Heart";
			//new screen
			system("CLS");
			cout << flush;
			cout << "Welcome to department : " << department << endl;
			options();
			string pick;
			Queue H;
			while (true) {
				cin >> pick;
				//ensures user only enters one character
				if (pick.length() != 1) {
					cout << "\nPlease enter only one character!\n";
					continue;
				}
				//menu for options in the heart department

				if (pick == "1") {
					H.AddPatient(Heart);
					system("CLS");
					cout << flush;
					break;
				}
				if (pick == "2") {
					H.AddCriticalPatient(Heart, criticalHeart);
					system("CLS");
					cout << flush;
					break;
				}
				if (pick == "3") {
					H.Operate(Heart, criticalHeart);
					system("CLS");
					cout << flush;
					break;
				}
				if (pick == "4") {
					H.RemovePatient(Heart, criticalHeart);
					system("CLS");
					cout << flush;
					break;
				}
				if (pick == "5") {
					H.Print(Heart, criticalHeart);
					system("CLS");
					cout << flush;
					break;
				}
				if (pick == "6") {
					system("CLS");
					cout << flush;
					break;
				}
				//case if none of the options are picked
				else if (pick != "1" && pick != "2" && pick != "3" && pick != "4" && pick != "5" && pick != "6") {
					cout << "\nPlease only enter a valid option!\n\n";
					continue;
				}
			}
		}
		//lung department
		else if (choice == "2") {
			department = "Lung";
			system("CLS");
			cout << flush;
			cout << "Welcome to department : " << department << endl;
			options();
			string pick;
			Queue L;
			int critical = 0;
			while (true) {
				cin >> pick;
				//ensures only one character is entered
				if (pick.length() != 1) {
					cout << "\nPlease enter only one character!\n";
					continue;
				}
				//menu options for lung department

				if (pick == "1") {
					L.AddPatient(Lung);
					system("CLS");
					cout << flush;
					break;
				}
				if (pick == "2") {
					L.AddCriticalPatient(Lung, criticalLung);
					system("CLS");
					cout << flush;
					break;
				}
				if (pick == "3") {
					L.Operate(Lung, criticalLung);
					system("CLS");
					cout << flush;
					break;
				}
				if (pick == "4") {
					L.RemovePatient(Lung, criticalLung);
					system("CLS");
					cout << flush;
					break;
				}
				if (pick == "5") {
					L.Print(Lung, criticalLung);
					system("CLS");
					cout << flush;
					break;
				}
				if (pick == "6") {
					system("CLS");
					cout << flush;
					break;
				}
				//case if none of the options are picked
				else if (pick != "1" && pick != "2" && pick != "3" && pick != "4" && pick != "5" && pick != "6") {
					cout << "\nPlease only enter a valid option!\n\n";
					continue;
				}
			}
		}
		//Plastic surgery department
		else if (choice == "3") {
			department = "Plastic";
			system("CLS");
			cout << flush;
			cout << "Welcome to department : Plastic surgery" << endl;
			options();
			string pick;
			Queue P;
			int critical = 0;
			while (true) {
				cin >> pick;
				//ensures only one character is entered
				if (pick.length() != 1) {
					cout << "\nPlease enter only one character!\n";
					continue;
				}
				//menu options for plastic surgery department
				if (pick == "1") {
					P.AddPatient(Plastic);
					system("CLS");
					cout << flush;
					break;
				}
				if (pick == "2") {
					P.AddCriticalPatient(Plastic, criticalPlastic);
					system("CLS");
					cout << flush;
					break;
				}
				if (pick == "3") {
					P.Operate(Plastic, criticalPlastic);
					system("CLS");
					cout << flush;
					break;
				}
				if (pick == "4") {
					P.RemovePatient(Plastic, criticalPlastic);
					system("CLS");
					cout << flush;
					break;
				}
				if (pick == "5") {
					P.Print(Plastic, criticalPlastic);
					system("CLS");
					cout << flush;
					break;
				}
				if (pick == "6") {
					system("CLS");
					cout << flush;
					break;
				}
				//case if none of the options are picked
				else if (pick != "1" && pick != "2" && pick != "3" && pick != "4" && pick != "5" && pick != "6") {
					cout << "\nPlease only enter a valid option!\n\n";
					continue;
				}
			}
		}
		//exit case
		else if (choice == "4") {
			system("CLS");
			cout << flush;
			string exitt;
			cout << "Thank you for using this system!\n";
			cout << "Enter any key to leave\n";
			cin >> exitt;
			exit(0);
		}
		//invalid input case
		else {
			cout << "\nPlease enter a valid option!\n";
			cout << "Enter any key to refresh!\n";
			string accept;
			cin >> accept;
			system("CLS");
			cout << flush;
		}

	}

	system("PAUSE");
	return 0;
}
//submenu options
void options() {
	cout << "Please enter your choice: \n";
	cout << "1. Add patient\n";
	cout << "2. Add critically ill patient\n";
	cout << "3. Take out patient for operation \n";
	cout << "4. Cancel patient\n";
	cout << "5. List the queue of Patients\n";
	cout << "6. Change departments or exit\n\n";
}
