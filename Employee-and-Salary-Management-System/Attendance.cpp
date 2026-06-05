#include "Attendance.h"
#include <iostream>
#include <sstream>
using namespace std;

Attendance::Attendance() :personalLeave(0), sickLeave(0), lateDate(0) { }
Attendance::Attendance(int personalLeave, int sickLeave, int lateDate) :personalLeave(personalLeave), sickLeave(sickLeave), lateDate(lateDate) { }

void Attendance::setPersonalLeave(int personalLeave) { this->personalLeave = personalLeave; }
void Attendance::setSickLeave(int sickLeave) { this->sickLeave = sickLeave; }
void Attendance::setLateHour(int lateHour) { this->lateDate = lateHour; }

int Attendance::getPersonalLeave() { return personalLeave; }
int Attendance::getSickLeave() { return sickLeave; }
int Attendance::getLateHour() { return lateDate; }

string Attendance::print() {
	stringstream ss;
	ss << getPersonalLeave() << "/" << getSickLeave() << "/" << getLateHour();
	return ss.str();
}
// 根據事假、病假和遲到的規則計算最終薪水
double Attendance::getFinalSalary(double baseSalary) const {
    double penalty = 0.0;
	//事假扣薪
    if (personalLeave > 3) {
        penalty += (personalLeave - 3) * 500;
    }
	//病假扣薪
    if (sickLeave > 5) {
        penalty += (sickLeave - 5) * 300;
    }
	//遲到扣薪
    if (lateDate > 3) {
        penalty += (lateDate - 3) * 100;
    }
    // 確保不會扣到負薪水
    if (penalty > baseSalary) {
        penalty = baseSalary;
    }

    return baseSalary - penalty;
}
