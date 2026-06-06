#include "Employee.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int Employee::numOfEmployee = 0;

Employee::Employee() : baseSalary(0), bonus(0.0) {
    numOfEmployee++;
}

Employee::Employee(string id, string name, string type, double baseSalary, Attendance attend, double bonus)
    : id(id), name(name), type(type), baseSalary(baseSalary), attend(attend), bonus(bonus) {
    numOfEmployee++;
}

Employee::~Employee() {
    numOfEmployee--;
}

void Employee::setID(string id) { this->id = id; }
void Employee::setName(string name) { this->name = name; }
void Employee::setType(string type) { this->type = type; }
void Employee::setBaseSalary(double baseSalary) { this->baseSalary = baseSalary; }
void Employee::setAttendance(int personalLeave, int sickLeave, int lateHour) {
    attend.setPersonalLeave(personalLeave);
    attend.setSickLeave(sickLeave);
    attend.setLateHour(lateHour);
}
void Employee::setBonus(double bonus) { this->bonus = bonus; }

string Employee::getID() const { return id; }
string Employee::getName() const { return name; }
string Employee::getType() const { return type; }
double Employee::getBaseSalary() const { return baseSalary; }
Attendance Employee::getAttendance() const { return attend; }
double Employee::getBonus() const { return bonus; }

double Employee::getFinalSalary() const {
    return attend.getFinalSalary(baseSalary) + getBonus();
}

void Employee::print() {
    cout << left << setw(8) << getID()
        << setw(16) << getName()
        << setw(8) << getType()
        << setw(12) << getBaseSalary()
        << setw(20) << getAttendance().print()
        << setw(8) << getBonus()
        << setw(12) << getFinalSalary()
        << endl;
}

int Employee::getNumOfEmployee() { return numOfEmployee; }
