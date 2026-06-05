#include "Search.h"
vector<Employee> Search::foundName(vector<unique_ptr<Employee>>& emps, const string keyword) {
	vector<Employee> newEmployee;
	
	for (auto& employee : emps) {
		if (employee->getName().find(keyword)!=string::npos) {
			newEmployee.push_back(*employee);
		}
	}
	return newEmployee;
}
vector<Employee> Search::foundType(vector<unique_ptr<Employee>>& emps, const string keyword) {
	vector<Employee> newEmployee;
	
	for (auto& employee : emps) {	
		if (keyword == employee->getType()) {
			newEmployee.push_back(*employee);
		}
	}
	return newEmployee;
}
vector<Employee> Search::foundID(vector<unique_ptr<Employee>>& emps, const string keyword) {
	vector<Employee> newEmployee;

	for (auto& employee : emps) {
		if (keyword == employee->getID()) {
			newEmployee.push_back(*employee);
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

int Search::searchIndex(vector<unique_ptr<Employee>>& emps, string targetID) {
	int index = 0;
	for (auto& employee : emps) {
		if (employee->getID() == targetID) break;
		index++;
	}
	return index;
}
