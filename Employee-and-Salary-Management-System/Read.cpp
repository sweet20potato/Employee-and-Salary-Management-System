#include "Read.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Read::Read(const string& filename) : filename(filename) {}

void Read::loadData() {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Employee emp;
        string temp;

        getline(ss, emp.id, ',');
        getline(ss, emp.name, ',');
        getline(ss, emp.type, ',');
        getline(ss, temp, ','); emp.baseSalary = stod(temp); // 將字串轉成 double
        getline(ss, temp, ','); emp.absenceDays = stoi(temp); // 將字串轉成 int
        getline(ss, temp, ','); emp.bonus = stod(temp);

        emp.lateCount = 0;
        emp.resigned = false;
        employees.push_back(emp);
    }
}

void Read::printReport() {
    cout << endl <<"=== 員工薪資報表 ===" << endl;
    cout << "ID\t姓名\t類型\t基本薪資\t缺勤\t遲到\t獎金\t應發薪資\t狀態" <<endl;
    for (auto& emp : employees) {
        if (emp.resigned) {
            cout << emp.id << "\t" << emp.name << "\t" << emp.type
                 << "\t" << emp.baseSalary << "\t" << emp.absenceDays
                 << "\t" << emp.lateCount << "\t" << emp.bonus
                 << "\t已辭職"<< endl;
        }
        else {
            double salary = emp.baseSalary;
            salary -= emp.absenceDays * 1000;
            salary -= emp.lateCount * 200;
            if (emp.type == "full") salary += emp.bonus;

            cout << emp.id << "\t" << emp.name << "\t" << emp.type
                 << "\t" << emp.baseSalary << "\t" << emp.absenceDays
                 << "\t" << emp.lateCount << "\t" << emp.bonus
                 << "\t" << salary << "\t在職"<< endl;
        }
    }
}
// 儲存資料到Excel
void Read::saveData() {
    ofstream file(filename); // 覆蓋原本的檔案
    for (auto& emp : employees) {
        file << emp.id << ","
             << emp.name << ","
             << emp.type << ","
             << emp.baseSalary << ","
             << emp.absenceDays << ","
             << emp.lateCount << ","  
             << emp.bonus << ",";
            if (emp.resigned) {
                file << "resigned"<< endl;
            }
            else {
                file << "active"<< endl;
            }
    }
}


vector<Employee>& Read::getEmployees() {
    return employees;
}
