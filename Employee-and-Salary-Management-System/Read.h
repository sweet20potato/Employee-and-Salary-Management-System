#ifndef READ_H
#define READ_H

#include <string>
#include <vector>
#include "Employee.h"
using namespace std;

class Read {
private:
    string filename;
    vector<Employee> employees;

public:
    Read(const string& filename);
    void loadData();
    void printReport();
    void saveData();
    vector<Employee>& getEmployees();
    vector<Employee> copyEmployees;
};

#endif
