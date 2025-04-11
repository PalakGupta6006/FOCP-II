#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Student
{
    private:
    string name;
    int roll_no;
    float cgpa;
    vector<string>courses;

    public:
    Student();
    Student(string name,int roll_no,float cgpa,vector<string>courses);
    Student(const Student &stud);
    ~Student();
    void new_courses(string new_course);
    void new_cgpa(float new_cgpa);
    void display_info();
    int getRollNumber();
};

Student::Student()
{
    name = " ";
    roll_no = 0;
    cgpa = 0.0;
    courses = {};
}

Student::Student(string name,int roll_no,float cgpa,vector<string>courses)
{
    this ->name = name;
    this ->roll_no = roll_no;
    this ->cgpa = cgpa;
    this ->courses = courses;
}

Student::Student(const Student &stud) {
    name = stud.name;
    roll_no = stud.roll_no;
    cgpa = stud.cgpa;
    courses = stud.courses;
}

Student::~Student()
{}

void Student::new_courses(string new_course)
{
    courses.push_back(new_course);
}

void Student::new_cgpa(float new_cgpa)
{
    cgpa = new_cgpa;
}

int Student::getRollNumber() 
{
    return roll_no;
}

void Student::display_info()
{
    cout<<"Name: "<<name;
    cout<<endl<<"Roll_no: "<<roll_no;
    cout<<endl<<"CGPA: "<<cgpa;
    cout<<endl<<"Courses: ";
    /*{
        for(int i=0;i<courses.size();i++)
        {
            cout<<courses<<endl;
        }
    }*/
}

class StudentManagementSystem {
    private:
        vector<Student> students;
    
    public:
        void addStudent(Student s) {
            for (int i = 0; i < students.size(); i++) {
                if (students[i].getRollNumber() == s.getRollNumber()) {
                    cout << "Student with this roll number already exists.\n";
                    return;
                }
            }
            students.push_back(s);
        }
    
        void searchStudent(int roll) {
            for (int i = 0; i < students.size(); i++) {
                if (students[i].getRollNumber() == roll) {
                    cout << "Student found:\n";
                    students[i].display_info();
                    return;
                }
            }
            cout << "Student not found.\n";
        }
    
        void displayAll() {
            if (students.size() == 0) {
                cout << "No students in the system.\n";
                return;
            }
    
            for (int i = 0; i < students.size(); i++) {
                students[i].display_info();
            }
        }
    };

int main()
{
    StudentManagementSystem c1;

    vector<string> courses1 = {"Math", "Science"};
    Student s1("Ali", 1, 3.2, courses1);

    Student s2; 
    s2 = Student("Sara", 2, 3.6, {"English", "Physics"});

    Student s3;

    c1.addStudent(s1);
    c1.addStudent(s2);

    s1.new_courses("Computer");

    s2.new_cgpa(3.9);

    c1.searchStudent(1);

    c1.displayAll();

    return 0;
}
