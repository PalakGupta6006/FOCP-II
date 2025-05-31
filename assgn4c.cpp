#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
public:
    string name;
    int id;

    Student(string n, int i) {
        name = n;
        id = i;
    }
};

class Professor {
public:
    string name;
    int id;

    Professor(string n, int i) {
        name = n;
        id = i;
    }
};

class Course {
public:
    string title;
    int courseId;
    string professorName;
    vector<string> studentNames;

    Course(string t, int id) {
        title = t;
        courseId = id;
        professorName = "None";
    }

    void assignProfessor(string name) {
        professorName = name;
    }

    void enrollStudent(string name) {
        studentNames.push_back(name);
    }

    void displayCourse() {
        cout << "Course: " << title << "  Professor: " << professorName << endl;
        cout << "Enrolled Students: ";
        for (string s : studentNames) {
            cout << s << ", ";
        }
        cout << endl;
    }
};

class UniversitySystem {
private:
    vector<Student> students;
    vector<Professor> professors;
    vector<Course> courses;

public:
    void addStudent(string name, int id) {
        students.push_back(Student(name, id));
    }

    void addProfessor(string name, int id) {
        professors.push_back(Professor(name, id));
    }

    void addCourse(string title, int id) {
        courses.push_back(Course(title, id));
    }

    void enrollStudentInCourse(int studentId, int courseId) {
        string studentName = findStudentName(studentId);
        Course* course = findCourse(courseId);

        if (studentName != "" && course != nullptr) {
            course->enrollStudent(studentName);
        } else {
            cout << "Invalid student or course ID!" << endl;
        }
    }

    void assignProfessorToCourse(int profId, int courseId) {
        string profName = findProfessorName(profId);
        Course* course = findCourse(courseId);

        if (profName != "" && course != nullptr) {
            course->assignProfessor(profName);
        } else {
            cout << "Invalid professor or course ID!" << endl;
        }
    }

    void generateReport() {
        cout << "University Report:\n";
        for (Course &c : courses) {
            c.displayCourse();
        }
    }

private:
    string findStudentName(int id) {
        for (Student &s : students) {
            if (s.id == id) return s.name;
        }
        return "";
    }

    string findProfessorName(int id) {
        for (Professor &p : professors) {
            if (p.id == id) return p.name;
        }
        return "";
    }

    Course* findCourse(int id) {
        for (Course &c : courses) {
            if (c.courseId == id) return &c;
        }
        return nullptr;
    }
};

// Main function
int main() {
    UniversitySystem uni;

    uni.addStudent("=Shreya", 10);
    uni.addStudent("Muskan", 13);
    uni.addProfessor("Dr.Aman", 21);
    uni.addCourse("Physics", 303);
    uni.assignProfessorToCourse(21, 303);
    uni.enrollStudentInCourse(10, 303);
    uni.enrollStudentInCourse(13, 303);

    uni.generateReport();

    return 0;
}