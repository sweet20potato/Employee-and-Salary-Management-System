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
		cout << "Please enter the information you want to change (type/name/salary/attend) (Enter [done] to finish editing): ";
		string keyword;
		getline(cin, keyword);
		if (keyword == "done") break;
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

void Change::addEmployee(vector<Employee>& employees) {
    Employee newEmp;
    string name, type, id;
    double baseSalary;

    cout << "Enter employee name: ";
    getline(cin, name);
    newEmp.setName(name);

    cout << "Enter employee type (full/part): ";
    getline(cin, type);
    newEmp.setType(type);

    // 初始化隨機種子
    srand(time(nullptr));

    // 生成唯一 ID
    bool unique = false;
    while (!unique) {
        int num = rand() % 900 + 100; // 100~999
        if (type == "full") {
            id = "f" + to_string(num);
        } else {
            id = "p" + to_string(num);
        }

        // 檢查是否重複
        unique = true;
        for (auto& emp : employees) {
            if (emp.getID() == id) {
                unique = false;
                break;
            }
        }
    }
    newEmp.setID(id);

    cout << "Enter employee base salary: ";
    cin >> baseSalary;
    cin.ignore();
    newEmp.setBaseSalary(baseSalary);

    // 出勤狀況預設為 0/0/0
    newEmp.setAttendance(0, 0, 0);

    employees.push_back(newEmp);

    cout << "Employee added successfully. ID = " << id << endl;
	cout << endl;
}


void Change::delEmployee(vector<Employee>& employees) {
	cout <<"Enter employee name:";
	string delName;
	getline(cin,delName);

	int count = 0;

	for(int i=0;i<employees.size();i++){
		if(employees[i].getName()==delName){
			count++;
		}
	}
	if(count==0){
		cout<<"Employee not found."<<endl;
		return;
	}
	if(count==1){
		for(int i=0;i<employees.size();i++){
			if(employees[i].getName()==delName){
				employees.erase(employees.begin()+i);
				cout<<"Employee deleted successfully"<<endl;
				return;
			}
		}
	}
	cout<<"Multiple employees with the same name found."<<endl;
	cout<<"Please enter employee ID."<<endl;

	for(int i=0;i<employees.size();i++){
		if(employees[i].getName()==delName){
			cout<<"ID:"<<employees[i].getID()<<" Name:"<<employees[i].getName()<<endl;
		}
	}
	string delID;
	cout<<"Enter ID:";
	cin>>delID;
	cin.ignore();

	for(int i=0;i<employees.size();i++){
		if(employees[i].getID()==delID){
			employees.erase(employees.begin()+i);
			cout<<"Employee deleted successfully."<<endl;
			return;
		}
	}
	cout<<"ID not found."<<endl;
}
