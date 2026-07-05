#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    int id;
    string name;
    string designation;
    double salary;
    double houseRent;
    double medical;
    double tax;
    double netSalary;

    void calculateSalary() {
        houseRent = salary * 0.20;
        medical = salary * 0.10;
        tax = salary * 0.05;
        netSalary = salary + houseRent + medical - tax;
    }
};

class Payroll {
private:
    Employee emp[100];
    int total = 0;

public:

    void addEmployee() {
        cout << "Employee ID: ";
        cin >> emp[total].id;

        cin.ignore();

        cout << "Employee Name: ";
        getline(cin, emp[total].name);

        cout << "Designation: ";
        getline(cin, emp[total].designation);

        cout << "Basic Salary: ";
        cin >> emp[total].salary;

        emp[total].calculateSalary();

        total++;

        cout << "Employee Added Successfully.\n";
    }

    void displaySortedEmployees() {

        if (total == 0) {
            cout << "No Employees Found.\n";
            return;
        }

        for (int i = 0; i < total - 1; i++) {
            for (int j = i + 1; j < total; j++) {
                if (emp[j].netSalary > emp[i].netSalary) {
                    Employee temp = emp[i];
                    emp[i] = emp[j];
                    emp[j] = temp;
                }
            }
        }

        cout << "\n EMPLOYEE PAYROLL \n";

        for (int i = 0; i < total; i++) {
            cout << "\nEmployee ID : " << emp[i].id << endl;
            cout << "Name        : " << emp[i].name << endl;
            cout << "Designation : " << emp[i].designation << endl;
            cout << "Salary      : " << emp[i].salary << endl;
            cout << "House Rent  : " << emp[i].houseRent << endl;
            cout << "Medical     : " << emp[i].medical << endl;
            cout << "Tax         : " << emp[i].tax << endl;
            cout << "Net Salary  : " << emp[i].netSalary << endl;
        }
    }
};

int main() {

    Payroll payroll;
    int choice;

    do {

        cout << "\n PAYROLL MENU \n";
        cout << "1. Add Employee\n";
        cout << "2. Display Employees (Sorted by Net Salary)\n";
        cout << "3. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            payroll.addEmployee();
            break;

        case 2:
            payroll.displaySortedEmployees();
            break;

        case 3:
            cout << "Program Ended.\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 3);

    return 0;
}
