#include <iostream>
using namespace std;

// Base class
class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}
    virtual void displayDetails() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
    virtual double calculatePayment() {
        return 0.0;
    }
};
class Student : public Person {
public:
    Student(string n, int a) : Person(n, a) {}
    void displayDetails() override {
        cout << "Student - ";
        Person::displayDetails();
    }
};
class UndergraduateStudent : public Student {
    string major;
    string expgrdate;
public:
    UndergraduateStudent(string n, int a, string m,string d) : Student(n, a), major(m),expgrdate(d) {}
    void displayDetails() override {
        Student::displayDetails();
        cout << "Major: " << major << endl;
        cout << "Expected Graduation Date " << expgrdate << endl;
    }
};
class GraduateStudent : public Student {
    string thesis_title;
    string research_topic;
public:
    GraduateStudent(string n, int a, string thesis,string t) : Student(n, a), thesis_title(thesis),research_topic(t) {}
    void displayDetails() override {
        Student::displayDetails();
        cout << "Thesis Title: " << thesis_title << endl;
        cout << "research topic" << research_topic << endl;
    }
    double calculatePayment() override {
        return 1000.0; 
    }
};

// Professor class inherits from Person
class Professor : public Person {
protected:
    double baseSalary;
public:
    Professor(string n, int a, double salary) : Person(n, a), baseSalary(salary) {}
    void displayDetails() override {
        cout << "Professor - ";
        Person::displayDetails();
    }
    double calculatePayment() override {
        return baseSalary;
    }
};
class AssistantProfessor : public Professor {
public:
    AssistantProfessor(string n, int a, double salary) : Professor(n, a, salary) {}
    double calculatePayment() override {
        return baseSalary + 100; 
    }
};
class Classroom {
    public:
        string roomNumber;
        Classroom(string n) : roomNumber(n) {}
    
        void displayDetails() const {
            cout << "Classroom: " << roomNumber << endl;
        }
    };
 class Schedule {
        public:
            string time;
            string day;
        
            Schedule(string t, string d) : time(t), day(d) {}
        
            void displayDetails() const {
                cout << "Time: " << time << ", Day: " << day << endl;
            }
      };
     class Course:public Classroom {
        string professor;
        public:
            Course(string p, string n) : professor(p),Classroom(n) {}
            void displayDetails() const {
                cout << " professor" <<professor << ", Room number" << roomNumber << endl;
            }
     };

// Main function to test
int main() {
    UndergraduateStudent u("Shreya", 19, "Computer Science","10-01-2028");
    GraduateStudent g("Karan", 23, "AI Discovery","Boons of AI");
    AssistantProfessor p("Aman", 40, 50000);

    cout << "\n--- Undergraduate Student ---" << endl;
    u.displayDetails();

    cout << "\n--- Graduate Student ---" << endl;
    g.displayDetails();
    cout << "Payment: " << g.calculatePayment() << endl;

    cout << "\n--- Assistant Professor ---" << endl;
    p.displayDetails();
    cout << "Payment: " << p.calculatePayment() << endl;

    return 0;
} 