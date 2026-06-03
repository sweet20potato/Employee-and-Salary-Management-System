#ifndef CHAMGE_H
#define CHANGE_H

#include <iostream>
#include <vector>
#include "Employee.h"
class Change {
public:
	void modifyEmployee(Employee&);
	void addEmployee(vector<Employee>&);
	void delEmployee(vector<Employee>&);
};

#endif
