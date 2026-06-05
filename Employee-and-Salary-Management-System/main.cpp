#include "Read.h"
#include "Search.h"
#include "Change.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

	Read manage("Employees.csv");
	manage.loadData();
	manage.printReport();

	Search search;
	Change change;

	string input;
	while (true) {
		cout << "=== Function Description ===" << endl
			<< "1. Search and edit employee information (find)" << endl
			<< "2. Add a new employee. (add)" << endl
			<< "3. Firing (deleting) an employee (del)" << endl
			<< "4. Show current reports (show)" << endl
			<< "5. Save and exit (end)" << endl
			<< "Please enter the target action: ";

		getline(cin, input);
		if (input == "end") break;
		else if (input == "find") {
			cout << "lease enter your search keywords (ID / Name / Job Type): ";

			string keyword;
			getline(cin, keyword);
			if (keyword.empty()) continue;

			vector<unique_ptr<Employee>>& originalEmps = manage.getEmployees();
			vector<Employee> searchEmps;

			if (keyword == "part" || keyword == "full") {
				searchEmps = search.foundType(originalEmps, keyword);
			}
			else if (keyword[0] == 'f' || keyword[0] == 'p') {
				searchEmps = search.foundID(originalEmps, keyword);
			}
			else if (!keyword.empty()) {
				searchEmps = search.foundName(originalEmps, keyword);
			}

			if (searchEmps.empty()) cout << "Unable to find qualified employees" << endl;
			else {
				Employee target;

				if (searchEmps.size() != 1) {
					cout << "--- Find the following qualified employees ---" << endl;
					for (Employee& emp : searchEmps) {
						emp.print();
					}
					cout << "--------------------" << endl;

					cout << "Employee ID being searched: ";
					string targetID;
					cin >> targetID;
					searchEmps = search.foundID(searchEmps, targetID);
				}

				cout << "The object you want to modify is:" << endl;
				searchEmps[0].print();
				cout << "y/n : ";
				char ans;
				cin >> ans;
				if (ans == 'y') {
					change.modifyEmployee(*(originalEmps[search.searchIndex(originalEmps, searchEmps[0].getID())]));
				}
				else if (ans == 'n') {
					cout << "The employee's information remains unchanged." << endl;
					break;
				}
			}
		}
		else if (input == "add") {
			vector<unique_ptr<Employee>>& originalEmps = manage.getEmployees();
			change.addEmployee(originalEmps);
		}
		else if (input == "del") {
			vector<unique_ptr<Employee>>& originalEmps = manage.getEmployees();
			change.delEmployee(originalEmps);
		}
		else if (input == "show") {
			manage.printReport();
		}
		else {
			cout << "Invalid option, please re-enter." << endl;
		}
	}

	manage.saveData();

	return 0;
}
