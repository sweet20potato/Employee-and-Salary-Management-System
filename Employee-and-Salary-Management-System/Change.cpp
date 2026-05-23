#include "Change.h"
#include "Employee.h"
#include <iostream>
using namespace std;

void Change::promote(Employee& emp) {
	if (emp.getType() == "part") {
		emp.setType("full");
		cout << emp.getName() << " got promoted!" << endl;
	}
	else {
		cout << emp.getName() << " is already a full-time employee." << endl;
	}
}
