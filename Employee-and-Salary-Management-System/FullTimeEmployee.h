#ifndef FULLTIMEEMPLOYEE_H
#define FULLTIMEEMPLOYEE_H

#include "Employee.h"
class FullTimeEmployee :public Employee {
public:
	FullTimeEmployee(string id, string name, double baseSalary, Attendance attend, double bonus):Employee(id,name,"full",baseSalary,attend,bonus){}

	void setBonus(double performance) override {
		double newBonus;
		// 根據業績表現計算獎金
		if (performance >= 8) {
			newBonus = getBaseSalary() * 0.2;
		}
		else if (performance >= 6) {
			newBonus = getBaseSalary() * 0.1;
		}
		else if (performance >= 3) {
			newBonus = getBaseSalary() * 0.05;
		}
		else {
			newBonus = 0.0;
		}
		bonus = newBonus;
	}
};

#endif
