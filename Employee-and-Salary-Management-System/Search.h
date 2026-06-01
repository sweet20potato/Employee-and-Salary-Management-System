#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
#include "Employee.h"
class Search
{
public:
	vector<Employee> foundName(vector<Employee>&, const string);
	vector<Employee> foundType(vector<Employee>&, const string);
	vector<Employee> foundID(vector<Employee>&, const string);
	int searchIndex(vector<Employee>&,string);
};

#endif
