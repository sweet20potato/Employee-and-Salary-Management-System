#include "Read.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

Read::Read(const string& filename) :filename(filename) {}

// 從CSV檔案讀取員工資料
void Read::loadData() {
	ifstream file(filename);
	
	string line;
	getline(file, line);
	while (getline(file, line)) {
		stringstream ss(line);

		string id, name, type, attendStr, baseSalaryStr, bonusStr;

		getline(ss, id, ',');
		getline(ss, name, ',');
		getline(ss, type, ',');
		getline(ss, baseSalaryStr, ',');
		getline(ss, attendStr, ',');
		getline(ss, bonusStr, ',');

		double parsedSalary = stod(baseSalaryStr);
		double parsedBonus = stod(bonusStr);

		int p = 0, s = 0, l = 0;
		char slash;
		stringstream as(attendStr);
		as >> p >> slash >> s >> slash >> l;
		Attendance actualAttend(p, s, l);

		if (type == "full") {
			employees.push_back(make_unique < FullTimeEmployee>(id, name, parsedSalary, actualAttend, parsedBonus));
		}
		else {
			employees.push_back(make_unique<PartTimeEmployee>(id, name, parsedSalary, actualAttend, parsedBonus));
		}
	}
}

// 列印員工報表
void Read::printReport() {
	cout << "========================== EMPLOYEE REPORT ==========================" << endl;
	cout << left << setw(8) << "ID"
		<< setw(16) << "NAME"
		<< setw(8) << "TYPE"
		<< setw(12) << "BASESALARY"
		<< setw(20) << "ATTENDANCE(P/S/L)"
		<< setw(8) << "BONUS"
		<< setw(12) << "FINAL SALARY"
		<< endl;
	for (auto& emp : employees) {
		emp->print();
	}
	cout << "======================================================================" << endl;
}

// 將員工資料寫回CSV檔案
void Read::saveData() {
	ofstream file(filename);
	file << "id,name,type,baseSalary,attendance,bonus\n";
	for (auto& emp : employees) {
		file << emp->getID()
			<< "," << emp->getName()
			<< "," << emp->getType()
			<< "," << emp->getBaseSalary()
			<< "," << emp->getAttendance().getPersonalLeave() << "/"
			<< emp->getAttendance().getSickLeave() << "/"
			<< emp->getAttendance().getLateHour()
			<< "," << emp->getBonus()
			<< "," << emp->getFinalSalary()
			<< "\n";
	}
}

vector<unique_ptr<Employee>>& Read::getEmployees() {
	return employees;
}
