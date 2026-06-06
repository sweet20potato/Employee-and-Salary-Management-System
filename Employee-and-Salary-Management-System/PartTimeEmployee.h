#ifndef PARTTIMEEMPLOYEE_H
#define PARTTIMEEMPLOYEE_H

#include "Employee.h"
class PartTimeEmployee :public Employee {
public:
	PartTimeEmployee(string id, string name, double baseSalary, Attendance attend, double bonus) :Employee(id, name, "part", baseSalary, attend, bonus) {}

	void setBonus(double performance) override {
		int personalLeave = getAttendance().getPersonalLeave();
		int sickLeave = getAttendance().getSickLeave();
		if(personalLeave > 0 && sickLeave > 0) {
			bonus = 0.0; // 兼職員工有請假則無獎金
		}
		else {
			bonus = getBaseSalary() * 0.1; // 沒有請假則獎金為基本薪水的10%
		}
	}
};

#endif
