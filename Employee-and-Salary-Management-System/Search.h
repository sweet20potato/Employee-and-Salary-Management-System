#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
#include <memory>
#include "Employee.h"

class Search
{
public:
	vector<Employee> foundName(vector<unique_ptr<Employee>>&, const string);
	vector<Employee> foundType(vector<unique_ptr<Employee>>&, const string);
	vector<Employee> foundID(vector<unique_ptr<Employee>>&, const string);

	vector<Employee> foundID(vector<Employee>&, const string);

	int searchIndex(vector<unique_ptr<Employee>>&, string);
};

#endif
