#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    int employeeNumber;
    int salary; // Added member variable to store salary

public:
    void getData() {
        cout << "Enter name of employee: ";
        cin >> name;
        cout << "Enter employee number: ";
        cin >> employeeNumber;
        cout << "Enter salary: ";
        cin >> salary; // Prompt for salary input
    }

    void putData() {
        cout << "Name of employee: " << name << endl;
        cout << "Employee number: " << employeeNumber << endl;
        cout << "Salary: " << salary << endl; // Display salary
    }

    int getSalary() const {
        return salary;
    }
};

int main() {
    const int SIZE = 2;
    Employee ashneer[SIZE];

    // Get data for each employee
    for (int i = 0; i < SIZE; i++)
        ashneer[i].getData();

    // Find employee with maximum salary
    int maxSalary = -4000;
    int index = -1;
    for (int i = 0; i < SIZE; i++) {
        if (ashneer[i].getSalary() > maxSalary) {
            maxSalary = ashneer[i].getSalary();
            index = i;
        }
    }

    // Display details of employee with maximum salary
    if (index != -1) {
        cout << "Employee with maximum salary:" << endl;
        ashneer[index].putData();
    } else {
        cout << "No employee data found." << endl;
    }

    return 0;
}
