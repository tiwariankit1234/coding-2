#include <iostream>
#include <iomanip>
using namespace std;

class Employee {
private:
    string name; // Changed char to string for name
    int id;
public:
    void getData(){ // No need to pass Employee object as argument
        cin >> name;
        cin >> id;
    }
    void putData(){ // Display the data
        cout << "Employee name: " << name << endl;
        cout << "Employee id: " << id << endl;
    }
};

int main() {
    Employee list1[2];
    int i = 0;
    char choice;
    while (i < 2) {
        cout << "Do you want to enter employee details? (y/n): ";
        cin >> choice;
        if (choice == 'y') {
            list1[i].getData(); // Call getData using the object
            i++;
        } else if (choice == 'n') {
            break;
        } else {
            cout << "Invalid choice. Choose again: ";
        }
    }
    cout << "List of Employees: ------" << endl;
    for (int j = 0; j < i; j++) {
        cout << j + 1 << ")  " << endl;
        list1[j].putData();
    }

    return 0;
}
