#include "Search.h"
vector<Employee> Search::foundName(vector<Employee>& emps, const string keyword) {
	vector<Employee> newEmployee;
	
	for (Employee& employee : emps) {
		if (keyword == employee.getName()) {
			newEmployee.push_back(employee);
		}
	}
	return newEmployee;
}
vector<Employee> Search::foundType(vector<Employee>& emps, const string keyword) {
	vector<Employee> newEmployee;
	
	for (Employee& employee : emps) {	
		if (keyword == employee.getType()) {
			newEmployee.push_back(employee);
		}
	}
	return newEmployee;
}
vector<Employee> Search::foundID(vector<Employee>& emps, const string keyword) {
	vector<Employee> newEmployee;
	
	for (Employee& employee : emps) {
		if (keyword == employee.getID()) {
			newEmployee.push_back(employee);
		}
	}
	return newEmployee;
}

int Search::searchIndex(vector<Employee>& emps, string targetID) {
	int index = 0;
	for (Employee& employee : emps) {
		if (employee.getID() == targetID) break;
		index++;
	}
	return index;
}
