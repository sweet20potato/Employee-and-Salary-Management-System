#ifndef ATTENDANCE_H
#define ATTENDANCE_H

#include <string>
using namespace std;
class Attendance
{
private:
	int personalLeave;
	int sickLeave;
	int lateHour;
public:
	Attendance();
	Attendance(int, int, int);

	void setPersonalLeave(int);
	void setSickLeave(int);
	void setLateHour(int);

	int getPersonalLeave();
	int getSickLeave();
	int getLateHour();

	string print();
	double getFinalSalary(double baseSalary) const;
};

#endif
