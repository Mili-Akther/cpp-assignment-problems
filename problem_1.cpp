#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

class Student {
private:
    string id;
    string name;
    string department;
    int semester;
    float marks[5];

    float totalMarks;
    float average;
    float gpa;
    string letterGrade;


    float calculateGradePoint(float mark) {
        if (mark >= 80) return 4.00;
        if (mark >= 75) return 3.75;
        if (mark >= 70) return 3.50;
        if (mark >= 65) return 3.25;
        if (mark >= 60) return 3.00;
        if (mark >= 50) return 2.25;
        if (mark >= 40) return 2.00;
        return 0.00;
    }

    string determineLetterGrade(float overallGPA) {
        if (overallGPA >= 4.00) return "A+";
        if (overallGPA >= 3.75) return "A";
        if (overallGPA >= 3.50) return "A-";
        if (overallGPA >= 3.25) return "B+";
        if (overallGPA >= 3.00) return "B";
        if (overallGPA >= 2.25) return "C";
        if (overallGPA >= 2.00) return "D";
        return "F";
    }

public:

    Student() {}

    Student(string i, string n, string d, int s, float m1, float m2, float m3, float m4, float m5) {
        id = i;
        name = n;
        department = d;
        semester = s;
        marks[0] = m1; marks[1] = m2; marks[2] = m3; marks[3] = m4; marks[4] = m5;
        calculateMetrics();
    }


    void calculateMetrics() {
        totalMarks = 0;
        float totalGradePoints = 0;

        for (int i = 0; i < 5; i++) {
            totalMarks += marks[i];
            totalGradePoints += calculateGradePoint(marks[i]);
        }

        average = totalMarks / 5.0;
        gpa = totalGradePoints / 5.0;
        letterGrade = determineLetterGrade(gpa);
    }


    void inputData() {
        cout << "Enter Student ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Department: ";
        cin >> department;
        cout << "Enter Semester: ";
        cin >> semester;
        cout << "Enter marks for 5 courses (separated by spaces): ";
        for (int i = 0; i < 5; i++) {
            cin >> marks[i];
        }
        calculateMetrics();
        cout << "Student record added successfully!\n\n";
    }


    void displayMarksheet() const {
        cout << string(50, '-') << "\n";
        cout << "Student ID : " << id << " | Name: " << name << "\n";
        cout << "Department : " << department << " | Semester: " << semester << "\n";
        cout << string(50, '-') << "\n";
        cout << "Marks      : ";
        for (int i = 0; i < 5; i++) cout << marks[i] << "  ";
        cout << "\n";
        cout << fixed << setprecision(2);
        cout << "Total      : " << totalMarks << " / 500\n";
        cout << "Average    : " << average << "%\n";
        cout << "GPA        : " << gpa << " / 4.00\n";
        cout << "Grade      : " << letterGrade << "\n";
        cout << string(50, '-') << "\n\n";
    }

    // Getters
    string getID() const { return id; }
    string getDepartment() const { return department; }
    float getGPA() const { return gpa; }
};


bool compareGPA(const Student &a, const Student &b) {
    return a.getGPA() > b.getGPA();
}


void loadTestData(vector<Student>& students) {
    students.push_back(Student("S01", "Mili Akther", "CSE", 3, 85, 90, 88, 92, 80));
    students.push_back(Student("S02", "Romana Jannat", "BBA", 2, 70, 75, 80, 65, 72));
    students.push_back(Student("S03", "meherun Nahar", "EEE", 4, 95, 98, 91, 89, 90));
    students.push_back(Student("S04", "Begum Rokeya", "CSE", 3, 60, 65, 70, 75, 68));
    students.push_back(Student("S05", "Rita Chakma", "BBA", 1, 40, 50, 45, 55, 60));
    students.push_back(Student("S06", "Shimla Dey", "EEE", 2, 78, 82, 85, 80, 79));
    students.push_back(Student("S07", "Prantika", "CSE", 4, 88, 85, 90, 92, 87));
    students.push_back(Student("S08", "Promi Akther", "BBA", 3, 75, 70, 68, 72, 74));
    students.push_back(Student("S09", "Jisan", "EEE", 1, 55, 60, 58, 62, 65));
    students.push_back(Student("S10", "Ohin", "CSE", 2, 92, 95, 96, 90, 93));
    students.push_back(Student("S11", "Imran", "BBA", 4, 80, 82, 85, 88, 84));
    students.push_back(Student("S12", "Nahid", "EEE", 3, 65, 70, 75, 68, 72));
    students.push_back(Student("S13", "Rahadul", "CSE", 1, 45, 50, 55, 40, 48));
    students.push_back(Student("S14", "Nina Dobrev", "BBA", 2, 85, 88, 90, 82, 86));
    students.push_back(Student("S15", "Nuri", "EEE", 4, 72, 75, 78, 70, 74));
    students.push_back(Student("S16", "Ibnul", "CSE", 3, 90, 92, 88, 85, 89));
    students.push_back(Student("S17", "Faysal", "BBA", 1, 60, 65, 62, 68, 70));
    students.push_back(Student("S18", "Eraz", "EEE", 2, 82, 85, 80, 88, 84));
    students.push_back(Student("S19", "Rakib", "CSE", 4, 98, 95, 100, 96, 99));
    students.push_back(Student("S20", "Ahnaf Islam", "BBA", 3, 88, 90, 92, 85, 89));
}

int main() {
    vector<Student> students;
    loadTestData(students);

    int choice;
    do {
        cout << "=== STUDENT RECORD MANAGEMENT ===\n";
        cout << "1. Display All Students\n";
        cout << "2. Search by Student ID\n";
        cout << "3. Sort by GPA and Display Topper\n";
        cout << "4. Department-wise Average GPA\n";
        cout << "5. Input New Student Data\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "\n";

        if (choice == 1) {
            for (const auto& s : students) {
                s.displayMarksheet();
            }
        }
        else if (choice == 2) {
            string searchID;
            cout << "Enter Student ID (e.g., S01): ";
            cin >> searchID;
            bool found = false;
            for (const auto& s : students) {
                if (s.getID() == searchID) {
                    cout << "\n--- Student Found ---\n";
                    s.displayMarksheet();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Student ID not found.\n\n";
        }
        else if (choice == 3) {
            sort(students.begin(), students.end(), compareGPA);
            cout << "Students sorted by GPA. \n\n";
            cout << "=== TOPPER ===\n";
            students[0].displayMarksheet();
        }
        else if (choice == 4) {
            map<string, float> deptTotalGPA;
            map<string, int> deptCount;

            for (const auto& s : students) {
                deptTotalGPA[s.getDepartment()] += s.getGPA();
                deptCount[s.getDepartment()]++;
            }

            cout << "=== DEPARTMENT-WISE AVERAGE GPA ===\n";
            for (const auto& pair : deptCount) {
                string dept = pair.first;
                int count = pair.second;
                float avgGPA = deptTotalGPA[dept] / count;
                cout << "Department " << dept << " : " << fixed << setprecision(2) << avgGPA << " (from " << count << " students)\n";
            }
            cout << "\n";
        }
        else if (choice == 5) {
            Student newStudent;
            newStudent.inputData();
            students.push_back(newStudent);
        }
        else if (choice == 6) {
            cout << "Exiting system. Goodbye!\n";
        }

    } while (choice != 6);

    return 0;
}
