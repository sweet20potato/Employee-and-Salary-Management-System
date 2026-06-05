#ifndef FULLTIMEEMPLOYEE_H
#define FULLTIMEEMPLOYEE_H

#include "Employee.h"
class FullTimeEmployee :public Employee {
public:
	FullTimeEmployee(string id,string name, double baseSalary, Attendance attend):Employee(id,name,"full",baseSalary,attend){}

	double getBonus() const override {
		return bonus;
	}
};

#endif
