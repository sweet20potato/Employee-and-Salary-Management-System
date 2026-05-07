#ifndef READ_H
#define READ_H

#include <string>
#include <vector>
using namespace std;

struct Employee {
    string id;
    string name;
    string type;
    double baseSalary;
    int absenceDays;
    int lateCount;
    double bonus;
    bool resigned;
};

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
};

#endif
