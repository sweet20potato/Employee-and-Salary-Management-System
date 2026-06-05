#ifndef PARTTIMEEMPLOYEE_H
#define PARTTIMEEMPLOYEE_H

#include "Employee.h"
class PartTimeEmployee :public Employee {
public:
	PartTimeEmployee(string id,string name,double baseSalary,Attendance attend):Employee(id,name,"part",baseSalary,attend){}

	double getBonus() const override {
		return 0.0;
	}
};

#endif
