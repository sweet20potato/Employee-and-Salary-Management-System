#include "Change.h"
#include <iostream>
#include <sstream>
using namespace std;

void Change::modifyEmployee(Employee& emp) {
	if (cin.peek() == '\n') {
		cin.ignore();
	}
	//吃掉殘留的換行=>防止初始cout兩次

	while (true) {

		cout << endl << "The employee's original information is as follows: " << endl;
		emp.print();

		cout << "lease enter the information you want to change (type/name/salary/attend) (Enter [done] to finish editing): ";
		string keyword;
		getline(cin, keyword);
		if (keyword == "done") break;
		else if (keyword == "type") {
			if (emp.getType() == "full") emp.setType("part");
			else emp.setType("full");
		}
		else if (keyword == "name") {
			cout << "Enter the name you want to change it to: ";
			string newName;
			getline(cin, newName);
			emp.setName(newName);
		}
		else if (keyword == "salary") {
			cout << "Enter the salary you want to change it to: ";
			double newSalary;
			cin >> newSalary;
			cin.ignore(); //吃掉殘留的換行=>防止初始cout兩次
			emp.setBaseSalary(newSalary);
		}
		else if (keyword == "attend") {
			cout << "Enter the attendance you want to change it to: ";
			string newAttendance;
			getline(cin, newAttendance);
			stringstream ss(newAttendance);
			char flash;
			int personLeave, sickLeave, lateTimes;
			ss >> personLeave >> flash >> sickLeave >> flash >> lateTimes;

			emp.setAttendance(personLeave,sickLeave,lateTimes);
		}
	}
	cout << "The employee's information has been changed as follows: ";
	emp.print();
}

void Change::addEmployee() {

}

void Change::delEmployee() {

}
