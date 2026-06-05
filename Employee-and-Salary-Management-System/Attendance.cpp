#include "Attendance.h"
#include <iostream>
#include <sstream>
using namespace std;
Attendance::Attendance() :personalLeave(0), sickLeave(0), lateHour(0) { }
Attendance::Attendance(int personalLeave, int sickLeave, int lateHour) :personalLeave(personalLeave), sickLeave(sickLeave), lateHour(lateHour) { }

void Attendance::setPersonalLeave(int personalLeave) { this->personalLeave = personalLeave; }
void Attendance::setSickLeave(int sickLeave) { this->sickLeave = sickLeave; }
void Attendance::setLateHour(int lateHour) { this->lateHour = lateHour; }

int Attendance::getPersonalLeave() { return personalLeave; }
int Attendance::getSickLeave() { return sickLeave; }
int Attendance::getLateHour() { return lateHour; }



string Attendance::print() {
	stringstream ss;
	ss << getPersonalLeave() << "/" << getSickLeave() << "/" << getLateHour();
	return ss.str();
}

double Attendance::getFinalSalary(double baseSalary) const {
    double penalty = 0.0;

    // 事假超過 3 次，每次扣 500
    if (personalLeave > 3) {
        penalty += (personalLeave - 3) * 500;
    }

    // 病假超過 5 次，每次扣 300
    if (sickLeave > 5) {
        penalty += (sickLeave - 5) * 300;
    }

    // 遲到超過 10 小時，每小時扣 100
    if (lateHour > 10) {
        penalty += (lateHour - 10) * 100;
    }

    // 確保不會扣到負薪水
    if (penalty > baseSalary) {
        penalty = baseSalary;
    }

    return baseSalary - penalty;
}
