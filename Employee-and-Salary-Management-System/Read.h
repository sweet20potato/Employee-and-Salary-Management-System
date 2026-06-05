#ifndef READ_H
#define READ_H

#include <string>
#include <memory>
#include <vector>
#include "Employee.h"
#include "FullTimeEmployee.h"
#include "PartTimeEmployee.h"
using namespace std;

class Read {
private:
    string filename;
    vector<unique_ptr<Employee>> employees;

public:
    Read(const string& filename);
    void loadData();
    void printReport();
    void saveData();
    vector<unique_ptr<Employee>>& getEmployees();
    vector<Employee> copyEmployees;
};

#endif
