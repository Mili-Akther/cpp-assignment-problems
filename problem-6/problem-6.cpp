#include <iostream>
#include <string>
using namespace std;

class Course {
public:
    string code;
    int credit;
    double gradePoint;
};

class Student {
private:
    string name;
    int id;
    Course courses[6];
    int totalCourses = 0;

public:

    void inputStudent() {
        cout << "Student ID: ";
        cin >> id;

        cin.ignore();

        cout << "Student Name: ";
        getline(cin, name);
    }

    void registerCourse() {

        if (totalCourses == 6) {
            cout << "Maximum 6 courses allowed.\n";
            return;
        }

        string code;

        cout << "Course Code: ";
        cin >> code;


        for (int i = 0; i < totalCourses; i++) {
            if (courses[i].code == code) {
                cout << "Course already registered.\n";
                return;
            }
        }

        courses[totalCourses].code = code;

        cout << "Credit Hours: ";
        cin >> courses[totalCourses].credit;

        cout << "Grade Point (0-4): ";
        cin >> courses[totalCourses].gradePoint;

        totalCourses++;

        cout << "Course Registered Successfully.\n";
    }

    void dropCourse() {

        string code;

        cout << "Course Code to Drop: ";
        cin >> code;

        int index = -1;

        for (int i = 0; i < totalCourses; i++) {
            if (courses[i].code == code) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Course Not Found.\n";
            return;
        }

        for (int i = index; i < totalCourses - 1; i++) {
            courses[i] = courses[i + 1];
        }

        totalCourses--;

        cout << "Course Dropped Successfully.\n";
    }

    void showResult() {

        int totalCredit = 0;
        double totalPoint = 0;

        for (int i = 0; i < totalCourses; i++) {
            totalCredit += courses[i].credit;
            totalPoint += courses[i].credit * courses[i].gradePoint;
        }

        double gpa = 0;

        if (totalCredit != 0)
            gpa = totalPoint / totalCredit;

        cout << "\n SEMESTER RESULT \n";
        cout << "Student ID    : " << id << endl;
        cout << "Student Name  : " << name << endl;
        cout << "Registered Courses: " << totalCourses << endl;
        cout << "Total Credits : " << totalCredit << endl;
        cout << "Semester GPA  : " << gpa << endl;
    }
};

int main() {

    Student student;

    student.inputStudent();

    int choice;

    do {

        cout << "\n COURSE REGISTRATION MENU \n";
        cout << "1. Register Course\n";
        cout << "2. Drop Course\n";
        cout << "3. Show Total Credit & GPA\n";
        cout << "4. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            student.registerCourse();
            break;

        case 2:
            student.dropCourse();
            break;

        case 3:
            student.showResult();
            break;

        case 4:
            cout << "Program Ended.\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 4);

    return 0;
}
