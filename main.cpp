#include "Read.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void foundName(vector<Employee>& emps, const string keyword);
void foundType(vector<Employee>& emps, const string keyword);
void foundID(vector<Employee>& emps, const string keyword);

int main() {
	Read manage("Employees.csv");
	manage.loadData();
	manage.printReport();

	cout << "Search(id/name/type): ";
	string keyword;
	while (getline(cin,keyword) && keyword != "end") {
		if (keyword.empty()) continue;

		vector<Employee> &emps = manage.getEmployees();

		if (keyword.find(" ") != string::npos) {
			foundName(emps, keyword);
		}
		else if (keyword == "part" || keyword == "full") {
			foundType(emps, keyword);
		}
	}

	return 0;
}
