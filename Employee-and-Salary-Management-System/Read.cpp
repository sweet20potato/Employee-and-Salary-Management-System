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
		
		string id, name, type, attend, baseSalary;

		getline(ss, id, ',');
		getline(ss, name, ',');
		getline(ss, type, ',');

		// read and parse baseSalary safely
		double parsedSalary = 0.0;
		if (getline(ss, baseSalary, ',')) {
			// trim whitespace
			auto first = baseSalary.find_first_not_of(" \t\r\n");
			if (first == string::npos) {
				auto last = baseSalary.find_last_not_of("\t\r\n");
				string trimmed = baseSalary.substr(first, last - first + 1);
				try {
					parsedSalary = stod(trimmed);
				} catch (const invalid_argument&) {
					cerr << "Warning: invalid baseSalary on line " << lineNo << ": '" << trimmed << "'. Using 0." << endl;
				} catch (const out_of_range&) {
					cerr << "Warning: baseSalary out of range on line " << lineNo << ": '" << trimmed << "'. Using 0." << endl;
				}
			}
		}

		// read and parse attendance (format expected: personal/sick/late)
		int p = 0, s = 0, l = 0;
		if (getline(ss, attend, ',')) {
			if (!attend.empty()) {
				replace(attend.begin(), attend.end(), '/', ' ');
				stringstream as(attend);
				as >> p >> s >> l;
			}
		}

		Attendance actualAttend(p, s, l);

		if (type == "full") {
			employees.push_back(make_unique < FullTimeEmployee>(id, name, parsedSalary, actualAttend));
		}
		else {
			employees.push_back(make_unique<PartTimeEmployee>(id, name, parsedSalary, actualAttend));
		}
	}
}

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

void Read::saveData() {
	ofstream file(filename);
	for (auto& emp : employees) {
		file << emp->getID()
			 << "," << emp->getName()
			 << "," << emp->getType() 
			 << "," << emp->getBaseSalary()
			 << "," << emp->getAttendance().getPersonalLeave() << "/"
			 << emp->getAttendance().getSickLeave() << "/"
			 << emp->getAttendance().getLateHour()
			 << "," << emp->getBonus() << endl;
	}
}

vector<unique_ptr<Employee>>& Read::getEmployees() {
	return employees;
}
