#include "Read.h"
#include "Search.h"
#include "Change.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

	Read manage("Employees.csv");
	manage.loadData();
	manage.printReport();

	Search search;
	Change change;

	string input;
	// 主循環，處理使用者輸入的指令
	while (true) {
		cout << "=== Function Description ===" << endl
			<< "1. Search and edit employee information (find)" << endl
			<< "2. Add a new employee. (add)" << endl
			<< "3. Firing (deleting) an employee (del)" << endl
			<< "4. Show current reports (show)" << endl
			<< "5. Save and exit (end)" << endl
			<< "Please enter the target action: ";
		getline(cin, input);
		if (input == "end") break;
		// 搜尋並修改員工資訊
		else if (input == "find") {
			cout << "Please enter your search keywords (ID / Name / Job Type): ";

			string keyword;
			getline(cin, keyword);
			if (keyword.empty()) continue;

			vector<unique_ptr<Employee>>& originalEmps = manage.getEmployees();
			vector<Employee> searchEmps;
			// 根據使用者輸入的關鍵字判斷搜尋類型
			if (keyword == "part" || keyword == "full") {
				searchEmps = search.foundType(originalEmps, keyword);
			}
			// 根據ID開頭判斷是搜尋全職還是兼職員工
			else if (keyword[0] == 'f' || keyword[0] == 'p') {
				searchEmps = search.foundID(originalEmps, keyword);
			}
			// 預設為根據姓名搜尋
			else if (!keyword.empty()) {
				searchEmps = search.foundName(originalEmps, keyword);
			}

			if (searchEmps.empty()) cout << "Unable to find qualified employees" << endl;
			// 如果找到多個符合條件的員工，要求使用者進一步指定ID
			else {
				Employee target;

				if (searchEmps.size() != 1) {
					cout << "--- Find the following qualified employees ---" << endl;
					for (Employee& emp : searchEmps) {
						emp.print();
					}
					cout << "--------------------" << endl;

					cout << "Employee ID being searched: ";
					string targetID;
					cin >> targetID;
					searchEmps = search.foundID(searchEmps, targetID);
				}
				// 確認找到的員工資訊，並詢問是否要修改
				cout << "The object you want to modify is:" << endl;
				searchEmps[0].print();
				cout << "y/n : ";
				char ans;
				cin >> ans;
				if (ans == 'y') {
					change.modifyEmployee(*(originalEmps[search.searchIndex(originalEmps, searchEmps[0].getID())]));
				}
				else if (ans == 'n') {
					cout << "The employee's information remains unchanged." << endl;
					continue;
				}
			}
		}
		// 新增員工
		else if (input == "add") {
			vector<unique_ptr<Employee>>& originalEmps = manage.getEmployees();
			change.addEmployee(originalEmps);
		}
		// 刪除員工
		else if (input == "del") {
			vector<unique_ptr<Employee>>& originalEmps = manage.getEmployees();
			change.delEmployee(originalEmps);
		}
		// 顯示當前員工報表
		else if (input == "show") {
			manage.printReport();
		}
		else {
			cout << "Invalid option, please re-enter." << endl;
		}
	}

	manage.saveData();

	return 0;
}
