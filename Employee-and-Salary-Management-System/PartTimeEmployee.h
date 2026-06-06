#ifndef PARTTIMEEMPLOYEE_H
#define PARTTIMEEMPLOYEE_H

#include "Employee.h"
class PartTimeEmployee :public Employee {
public:
	PartTimeEmployee(string id, string name, double baseSalary, Attendance attend, double bonus) :Employee(id, name, "part", baseSalary, attend, bonus) {}

	void setBonus(double performance) override {
		double newBonus;
		// 根據業績表現計算獎金
		if (performance >= 5) {
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
