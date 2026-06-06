#ifndef CHANGE_H
#define CHANGE_H

#include <iostream>
#include <vector>
#include <memory>
#include "Employee.h"
#include "FullTimeEmployee.h"
#include "PartTimeEmployee.h"
#include "Attendance.h"
class Change {
public:
	void modifyEmployee(Employee&);
	void addEmployee(vector<unique_ptr<Employee>>&);
	void delEmployee(vector<unique_ptr<Employee>>&);
};

#endif
