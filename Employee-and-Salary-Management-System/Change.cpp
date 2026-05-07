#include "Change.h"
#include <iostream>
using namespace std;

void Change::promote(Employee& emp) {
    if (emp.type == "part") {
        emp.type = "full";
        emp.baseSalary = 40000;
        emp.bonus = 0;
        cout << emp.name << " 已升為正職！" << endl;
    } else {
        cout << emp.name << " 已經是正職。" << endl;
    }
}

void Change::resign(Employee& emp) {
    emp.resigned = true;
    cout << emp.name << " 已辭職！" << endl;
}
