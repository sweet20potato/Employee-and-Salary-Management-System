#ifndef PARTTIMEEMPLOYEE_H
#define PARTTIMEEMPLOYEE_H

#include "Employee.h"
class PartTimeEmployee :public Employee {
public:
	PartTimeEmployee(string id, string name, double baseSalary, Attendance attend, double bonus) :Employee(id, name, "part", baseSalary, attend, bonus) {}

	void setBonus(double performance) override {
		
	}
};

#endif
