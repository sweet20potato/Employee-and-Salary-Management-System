#ifndef CHAMGE_H
#define CHANGE_H

#include <iostream>
#include <vector>
#include "Employee.h"
class Change {
public:
	void modifyEmployee(Employee&);
	void addEmployee();
	void delEmployee(vector<Employee>&);
};

#endif
