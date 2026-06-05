#include "Change.h"
#include <iostream>
#include <sstream>
using namespace std;

void Change::modifyEmployee(Employee& emp) {
	if (cin.peek() == '\n') {
		cin.ignore();//吃掉殘留的換行=>防止初始cout兩次
	}
	// 允許使用者多次修改同一員工的不同資訊，直到輸入 "done" 為止
	while (true) {
		cout << endl << "The employee's original information is as follows: " << endl;
		emp.print();
		cout << "Please enter the information you want to change (type/name/salary/attend/bonus) (Enter [done] to finish editing): ";
		string keyword;
		getline(cin, keyword);
		if (keyword == "done") break;
		// 修改員工類型
		else if (keyword == "type") {
			string currentType = emp.getType();
			string currentID = emp.getID();
			if (currentType == "full") {
				emp.setType("part");
				if (!currentID.empty() && currentID[0] == 'f') {
					currentID[0] = 'p';
					emp.setID(currentID);
				}
			}
			else if (currentType == "part") {
				emp.setType("full");
				if (!currentID.empty() && currentID[0] == 'p') {
					currentID[0] = 'f';
					emp.setID(currentID);
				}
			}
		}
		// 修改員工姓名
		else if (keyword == "name") {
			cout << "Enter the name you want to change it to: ";
			string newName;
			getline(cin, newName);
			emp.setName(newName);
		}
		// 修改員工基本薪資
		else if (keyword == "salary") {
			cout << "Enter the salary you want to change it to: ";
			double newSalary;
			cin >> newSalary;
			cin.ignore(); //吃掉殘留的換行=>防止初始cout兩次
			emp.setBaseSalary(newSalary);
		}
		// 修改員工出勤狀況
		else if (keyword == "attend") {
			cout << "Enter the attendance you want to change it to: ";
			string newAttendance;
			getline(cin, newAttendance);
			stringstream ss(newAttendance);
			char flash;
			int personLeave, sickLeave, lateTimes;
			ss >> personLeave >> flash >> sickLeave >> flash >> lateTimes;

			emp.setAttendance(personLeave, sickLeave, lateTimes);
		}
		// 修改員工獎金
		else if (keyword == "bonus") {
			cout << "Enter the number of sales this month : ";
			double performance;
			cin >> performance;
			cin.ignore(); //吃掉殘留的換行=>防止初始cout兩次
			double bonus = 0.0;
			// 根據業績表現計算獎金
			if (performance >= 8) {
				bonus = emp.getBaseSalary() * 0.2;
			}
			else if (performance >= 6) {
				bonus = emp.getBaseSalary() * 0.1;
			}
			else if (performance >= 3) {
				bonus = emp.getBaseSalary() * 0.05;
			}
			else {
				bonus = 0.0; 
			}
			emp.setBonus(bonus);
		}
	}
	cout << "The employee's information has been changed as follows: ";
	emp.print();
}

//新增員工
void Change::addEmployee(vector<unique_ptr<Employee>>& employees) {
	string name, type, id;
	double baseSalary;
	// 新增員工資訊
	cout << "Enter employee name: ";
	getline(cin, name);

	cout << "Enter employee type (full/part): ";
	getline(cin, type);

	// 初始化隨機種子
	srand(time(0));

	// 生成唯一 ID
	bool unique = false;
	while (!unique) {
		int num = rand() % 900 + 100; // 100~999
		if (type == "full") {
			id = "f" + to_string(num);
		}
		else {
			id = "p" + to_string(num);
		}
		// 檢查ID是否重複
		unique = true;
		for (auto& emp : employees) {
			if (emp->getID() == id) {
				unique = false;
				break;
			}
		}
	}
	// 輸入新員工基本薪資
	cout << "Enter employee base salary: ";
	cin >> baseSalary;
	cin.ignore();
	// 出勤狀況預設為 0/0/0
	if (type == "full") {
		employees.push_back(make_unique<FullTimeEmployee>(id, name, baseSalary, Attendance(0, 0, 0)));
	}
	else {
		employees.push_back(make_unique<PartTimeEmployee>(id, name, baseSalary, Attendance(0, 0, 0)));
	}

	cout << "Employee added successfully. ID = " << id << endl;
	cout << endl;
}

//刪除員工
void Change::delEmployee(vector<unique_ptr<Employee>>& employees) {
	cout << "Enter employee name or id:";
	string delNameOrID;
	getline(cin, delNameOrID);
	// 先檢查是否有符合的員工
	int count = 0;
	for (int i = 0; i < employees.size(); i++) {
		if (employees[i]->getName() == delNameOrID || employees[i]->getID() == delNameOrID) {
			count++;
		}
	}
	if (count == 0) {
		cout << "Employee not found." << endl;
		return;
	}
	if (count == 1) {
		for (int i = 0; i < employees.size(); i++) {
			if (employees[i]->getName() == delNameOrID) {
				employees.erase(employees.begin() + i);
				cout << "Employee deleted successfully" << endl;
				return;
			}
		}
	}
	cout << "Multiple employees with the same name found." << endl;
	cout << "Please enter employee ID." << endl;
	// 列出所有符合名稱的員工資訊
	for (int i = 0; i < employees.size(); i++) {
		if (employees[i]->getName() == delNameOrID) {
			cout << "ID:" << employees[i]->getID() << " Name:" << employees[i]->getName() << endl;
		}
	}
	string delID;
	cout << "Enter ID:";
	cin >> delID;
	cin.ignore();
	// 根據ID刪除員工
	for (int i = 0; i < employees.size(); i++) {
		if (employees[i]->getID() == delID) {
			employees.erase(employees.begin() + i);
			cout << "Employee deleted successfully." << endl;
			return;
		}
	}
	cout << "ID not found." << endl;
}
