#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class Course {
public:
    int courseId;
    string courseName;
    int credit;
    double grade;

    Course() {}

    Course(int id, string name, int c, double g = 0.0) {
        courseId = id;
        courseName = name;
        credit = c;
        grade = g;
    }
};

class Teacher {
public:
    int teacherId;
    string teacherName;
    string department;

    Teacher() {}

    Teacher(int id, string name, string dept) {
        teacherId = id;
        teacherName = name;
        department = dept;
    }

    void display() {
        cout << "\nTeacher ID : " << teacherId << endl;
        cout << "Teacher Name : " << teacherName << endl;
        cout << "Department : " << department << endl;
    }
};

class Student {
public:
    int studentId;
    string studentName;
    string department;
    vector<Course> courses;

    Student() {}

    Student(int id, string name, string dept) {
        studentId = id;
        studentName = name;
        department = dept;
    }

    void registerCourse(Course c) {
        courses.push_back(c);
    }

    double calculateGPA() {
        double totalPoints = 0;
        int totalCredits = 0;

        for (auto c : courses) {
            totalPoints += c.grade * c.credit;
            totalCredits += c.credit;
        }

        if (totalCredits == 0)
            return 0;

        return totalPoints / totalCredits;
    }

    void transcript() {
        cout << "\n========== Transcript ==========\n";
        cout << "ID : " << studentId << endl;
        cout << "Name : " << studentName << endl;
        cout << "Department : " << department << endl;

        cout << "\nCourses:\n";

        for (auto c : courses) {
            cout << c.courseId << " "
                 << c.courseName
                 << " Credit:" << c.credit
                 << " Grade:" << c.grade << endl;
        }

        cout << "GPA : " << calculateGPA() << endl;
        cout << "================================\n";
    }
};

class Department {
public:
    string deptName;

    Department() {}

    Department(string name) {
        deptName = name;
    }

    void statistics(vector<Student> students) {
        int count = 0;

        for (auto s : students) {
            if (s.department == deptName)
                count++;
        }

        cout << "\nDepartment : " << deptName << endl;
        cout << "Total Students : " << count << endl;
    }
};

class University {
public:
    vector<Student> students;
    vector<Teacher> teachers;

    void admitStudent(Student s) {
        students.push_back(s);
    }

    void assignTeacher(Teacher t) {
        teachers.push_back(t);
    }

    void searchStudent(int id) {
        bool found = false;

        for (auto s : students) {
            if (s.studentId == id) {
                s.transcript();
                found = true;
                break;
            }
        }

        if (!found)
            cout << "\nStudent Not Found!\n";
    }

    void sortByGPA() {
        sort(students.begin(), students.end(),
             [](Student a, Student b) {
                 return a.calculateGPA() > b.calculateGPA();
             });

        cout << "\nStudents Sorted By GPA\n";

        for (auto s : students) {
            cout << s.studentId << " "
                 << s.studentName
                 << " GPA : "
                 << s.calculateGPA()
                 << endl;
        }
    }

    void saveData() {
        ofstream file("students.txt");

        for (auto s : students) {
            file << s.studentId << endl;
            file << s.studentName << endl;
            file << s.department << endl;
            file << s.calculateGPA() << endl;
        }

        file.close();

        cout << "\nStudent Data Saved Successfully.\n";
    }

    void loadData() {
        ifstream file("students.txt");

        if (!file) {
            cout << "\nNo File Found.\n";
            return;
        }

        int id;
        string name;
        string dept;
        double gpa;

        cout << "\n====== Loaded Student Data ======\n";

        while (file >> id) {
            file.ignore();

            getline(file, name);
            getline(file, dept);
            file >> gpa;

            cout << "ID : " << id << endl;
            cout << "Name : " << name << endl;
            cout << "Department : " << dept << endl;
            cout << "GPA : " << gpa << endl;
            cout << "--------------------------\n";
        }

        file.close();
    }
};

int main() {

    University u;

    Teacher t1(201, "Mr. Rahman", "CSE");
    Teacher t2(202, "Ms. Akter", "EEE");

    u.assignTeacher(t1);
    u.assignTeacher(t2);

    Student s1(101, "Alice", "CSE");
    Student s2(102, "Bob", "CSE");

    s1.registerCourse(Course(1, "Programming", 3, 4.00));
    s1.registerCourse(Course(2, "Database", 3, 3.75));

    s2.registerCourse(Course(1, "Programming", 3, 3.50));
    s2.registerCourse(Course(3, "Math", 3, 3.25));

    u.admitStudent(s1);
    u.admitStudent(s2);

    cout << "\nTeacher Information\n";
    t1.display();
    t2.display();

    u.searchStudent(101);

    u.sortByGPA();

    Department d("CSE");
    d.statistics(u.students);

    u.saveData();

    u.loadData();

    return 0;
}
