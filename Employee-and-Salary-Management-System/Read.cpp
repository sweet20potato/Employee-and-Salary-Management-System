#include "Read.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

Read::Read(const string& filename) :filename(filename) {}

void Read::loadData() {
    ifstream file(filename);
	if (!file.is_open()) {
		cerr << "Failed to open file: " << filename << endl;
		return;
	}

	// === 處理 UTF-8 BOM 亂碼關鍵程式碼 ===
	unsigned char bom[3] = { 0 };
	file.read((char*)bom, 3);
	if (bom[0] == 0xEF && bom[1] == 0xBB && bom[2] == 0xBF) {
		// 如果前三個位元組是 BOM，指標留在這裡（已經跳過 3 位元組）
	}
	else {
		// 如果不是 BOM，把檔案指標移回最開頭
		file.clear();
		file.seekg(0, ios::beg);
	}

	string line;
	size_t lineNo = 0;
	while (getline(file, line)) {
		++lineNo;
		stringstream ss(line);
		Employee emp;
		string id, name, type, attend, baseSalary;

		getline(ss, id, ',');  emp.setID(id);
		getline(ss, name, ',');  emp.setName(name);
		getline(ss, type, ',');  emp.setType(type);

		// read and parse baseSalary safely
		if (getline(ss, baseSalary, ',')) {
			// trim whitespace
			auto first = baseSalary.find_first_not_of(" \t\r\n");
			if (first == string::npos) {
				emp.setBaseSalary(0.0);
			} else {
				auto last = baseSalary.find_last_not_of(" \t\r\n");
				string trimmed = baseSalary.substr(first, last - first + 1);
				try {
					emp.setBaseSalary(stod(trimmed));
				} catch (const invalid_argument&) {
					cerr << "Warning: invalid baseSalary on line " << lineNo << ": '" << trimmed << "'. Using 0." << endl;
					emp.setBaseSalary(0.0);
				} catch (const out_of_range&) {
					cerr << "Warning: baseSalary out of range on line " << lineNo << ": '" << trimmed << "'. Using 0." << endl;
					emp.setBaseSalary(0.0);
				}
			}
		} else {
			emp.setBaseSalary(0.0);
		}

		// read and parse attendance (format expected: personal/sick/late)
		if (getline(ss, attend, ',')) {
			if (!attend.empty()) {
				replace(attend.begin(), attend.end(), '/', ' ');
				stringstream as(attend);
				int p = 0, s = 0, l = 0;
				as >> p >> s >> l;
				emp.setAttendance(p, s, l);
			}
		}

		employees.push_back(emp);
	}
}

void Read::printReport() {
	cout << "===================================== EMPLOYEE REPORT =====================================" << endl;
	cout << left << setw(8) << "ID"
		<< setw(16) << "NAME"
		<< setw(8) << "TYPE"
		<< setw(12) << "BASESALARY"
		<< setw(32) << "ATTENDANCE(PERSON/SICK/LATE)"
		<< setw(8) << "BONUS"
		<< "STATUS" << endl;
	for (Employee& emp : employees) {
		cout << left << setw(8) << emp.getID()
			<< setw(16) << emp.getName()
			<< setw(8) << emp.getType()
			<< setw(12) << emp.getBaseSalary()
			<< setw(32) << emp.getAttendance().print()
			<< setw(8) << emp.getBonus() << endl;
	}
	cout << "===========================================================================================" << endl;
}

void Read::saveData() {
	ofstream file(filename);
	for (Employee& emp : employees) {
		file << emp.getID()
			 << "," << emp.getName()
			 << "," << emp.getType() 
			 << "," << emp.getBaseSalary()
			 << "," << emp.getAttendance().getPersonalLeave() << "/"
			 << emp.getAttendance().getSickLeave() << "/"
			 << emp.getAttendance().getLateHour()
			 << "," << emp.getBonus() << endl;
	}
}

vector<Employee>& Read::getEmployees() {
	return employees;
}
