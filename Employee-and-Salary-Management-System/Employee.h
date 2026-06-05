#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Attendance.h"
#include <string>
using namespace std;
class Employee
{
protected:
	string id;
	string name;
	string type;
	double baseSalary;
	Attendance attend;

	static int numOfEmployee;
public:
	Employee();
	Employee(string, string, string, double, Attendance);
	virtual ~Employee();

	void setID(string);
	void setName(string);
	void setType(string);
	void setBaseSalary(double);
	void setAttendance(int, int, int);

	string getID() const;
	string getName() const;
	string getType() const;
	double getBaseSalary() const;
	Attendance getAttendance() const;

	virtual double getBonus() const;
	double getFinalSalary() const;

	void print();

	static int getNumOfEmployee();

};

#endif
