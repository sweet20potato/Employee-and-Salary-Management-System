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
