#include <iostream>
#include <cstring>
using namespace std;

class Person {
    string name;
    int age;
    int ID;
    string contact_info;
public:
    Person(const string n = "", int a = 0, int id = 0, const string contact = "") {
        setName(n);
        setAge(a);
        ID = id;
        contact_info=contact;
    }

    void setName(const string n) {
           name=n ;
    }

    void setAge(int a) {
        age = (a > 0 && a < 120) ? a : 1;
    }

    int getID() {
        return ID;
    }

    virtual void displayDetails() {
        cout << "Name: " << name << ", Age: " << age << ", ID: " << ID << ", Contact: " << contact_info << endl;
    }

    virtual double calculatePayment() {
        return 0.0;
    }
};

class Student : public Person {
private:
    string enrollmentDate;
    string program;
    double GPA;
public:
    Student(const string n, int a, int id, const string c, const string date, const string prog, double gpa)
    : Person(n, a, id, c) {
        enrollmentDate=date;
        program= prog;
        setGPA(gpa);
    }

    void setGPA(double gpa) {
        GPA = (gpa >= 0.0 && gpa <= 4.0) ? gpa : 0.0;
    }

    void displayDetails() override {
        cout << "Enrollment Date: " << enrollmentDate << ", Program: " << program << ", GPA: " << GPA << endl;
    }

    double calculatePayment() override {
        return 100.0;
    }
};

class Professor : public Person {
private:
    string department;
    string specialization;
    string hireDate;
public:
    Professor(const string n, int a, int id, const string c, const string dept, const string spec, const string hire)
    : Person(n, a, id, c) {
        department=dept;
        specialization=spec;
        hireDate= hire;
    }

    void displayDetails() override {
        cout << "Department: " << department << ", Specialization: " << specialization << ", Hire Date: " << hireDate << endl;
    }

    double calculatePayment() override {
        return 500.0;
    }
};
class GradeBook {
private:
    int studentIDs[5];
    double grades[5];
    int count;
public:
    GradeBook() {
        count = 0;
    }

    void addGrade(int id, double grade) {
        if (count < 5) {
            studentIDs[count] = id;
            grades[count] = grade;
            count++;
        }
    }

    double calculateAverageGrade() {
        if (count == 0) 
        {return 0;}
        double total = 0;
        for (int i = 0; i < count; i++)
            total += grades[i];
        return total / count;
    }

    double getHighestGrade() {
        if (count == 0) 
        return 0;
        int max = grades[0];
        for (int i = 1; i < count; i++)
            if (grades[i] > max)
                max = grades[i];
        return max;
    }

    void getFailingStudents() {
        cout << "Failing Students IDs: ";
        for (int i = 0; i < count; i++) {
            if (grades[i] < 35.0)
                cout << studentIDs[i] << " ";
        }
        cout << endl;
    }
};
class EnrollmentManager {
private:
    int enrollments[5];
    int count;
public:
    EnrollmentManager() {
        count = 0;
    }

    void enrollStudent(int studentID) {
        if (count < 5)
            enrollments[count++] = studentID;
    }

    void dropStudent(int studentID) {
        for (int i = 0; i < count; i++) {
            if (enrollments[i] == studentID) {
                for (int j = i; j < count - 1; j++)
                    enrollments[j] = enrollments[j + 1];
                count--;
                break;
            }
        }
    }

    int getEnrollmentCount() {
        return count;
    }
};

int main() {
    Student s1("Shreya", 25, 11, "9764483737", "15-01-2023", "CSE", 2.5);
    Professor p1("Arjun", 40, 21, "74358394", "CSE", "DS", "15-07-2015");

    s1.displayDetails();
    p1.displayDetails();

    cout << "Student Payment: " << s1.calculatePayment() << endl;
    cout << "Professor Salary: " << p1.calculatePayment() << endl;
    Person* people[2];
    people[0] = &s1;
    people[1] = &p1;

    for (int i = 0; i < 2; i++) {
        people[i]->displayDetails();
    }
    GradeBook GB;
    GB.addGrade(110, 85.0);
    GB.addGrade(97, 47.0);

    cout << "Average Grade: " << GB.calculateAverageGrade() << endl;
    cout << "Highest Grade: " << GB.getHighestGrade() << endl;
    GB.getFailingStudents();
    EnrollmentManager em;
    em.enrollStudent(110);
    em.enrollStudent(97);
    em.dropStudent(97);

    cout << "Enrollment Count: " << em.getEnrollmentCount() << endl;

    return 0;
}