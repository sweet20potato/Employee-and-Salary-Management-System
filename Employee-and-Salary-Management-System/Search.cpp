#include "Search.h"

// Search類別的成員函式實作
vector<Employee> Search::foundName(vector<unique_ptr<Employee>>& emps, const string keyword) {
	vector<Employee> newEmployee;
	
	for (auto& employee : emps) {
		if (employee->getName().find(keyword)!=string::npos) {
			newEmployee.push_back(*employee);
		}
	}
	return newEmployee;
}

// 搜尋員工類型在給定員工列表中的匹配項目
vector<Employee> Search::foundType(vector<unique_ptr<Employee>>& emps, const string keyword) {
	vector<Employee> newEmployee;
	
	for (auto& employee : emps) {	
		if (keyword == employee->getType()) {
			newEmployee.push_back(*employee);
		}
	}
	return newEmployee;
}

// 搜尋員工ID在給定員工列表中的匹配項目(智慧指標)
vector<Employee> Search::foundID(vector<unique_ptr<Employee>>& emps, const string keyword) {
	vector<Employee> newEmployee;

	for (auto& employee : emps) {
		if (keyword == employee->getID()) {
			newEmployee.push_back(*employee);
		}
	}
	return newEmployee;
}

// 搜尋員工ID在給定員工列表中的匹配項目(一般員工列表)
vector<Employee> Search::foundID(vector<Employee>& emps, const string keyword) {
	vector<Employee> newEmployee;
	for (Employee& employee : emps) {
		if (keyword == employee.getID()) {
			newEmployee.push_back(employee);
		}
	}
	return newEmployee;
}

// 搜尋員工在原始員工資料中的索引位置
int Search::searchIndex(vector<unique_ptr<Employee>>& emps, string targetID) {
	int index = 0;
	for (auto& employee : emps) {
		if (employee->getID() == targetID) break;
		index++;
	}
	return index;
}
