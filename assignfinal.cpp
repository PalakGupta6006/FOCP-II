#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
using namespace std;
class InvalidIDException:public exception 
{
    public:
    const char* what() const noexcept override 
    {
    return "Error: ID must be a positive number.";
    }
};
class EmptyNameException : public exception 
{
public:
const char* what() const noexcept override 
{
    return "Error: Name cannot be empty.";
}
};
class UniversitySystemException:public std::exception 
{
protected:
std::string message;
public:
UniversitySystemException(const std::string& msg):message("University System Error: "+msg){}
const char* what()const noexcept override
{
    return message.c_str();
}
};
class EnrollmentException:public UniversitySystemException 
{
public:
EnrollmentException(const std::string& studentID):UniversitySystemException("Enrollment failed for student ID: "+studentID){}
};
class GradeException:public UniversitySystemException 
{
public:
GradeException(float invalidGrade):UniversitySystemException("Invalid grade: "+std::to_string(invalidGrade)){}
};
class PaymentException:public UniversitySystemException 
{
public:
PaymentException(const std::string& msg) : UniversitySystemException("Payment Error: "+msg){}
};
class Course;
class Professor;
class Person
{
private:
string name;
int age,payment,items;
string ID;
string contact_no;
public:
Person()
{
    name="Unknown";
    age=0;
    ID="0";
    contact_no="0";
    payment=0;
    items=0;
    cout<<"Default Constructor called ."<<endl;
}
Person(string n,int a,string I,string c,int p,int i)
{
    name=n;
    age=a;
    ID=I;
    contact_no=c;
    payment=p;
    items=i;
    cout<<"parametrized Constructor Called for "<<name<<endl;
}
void set()
{
    cout<<"Give name: ";
    cin>>name;
    cout<<"Give age: ";
    cin>>age;
    cout<<"Give ID: ";
    cin>>ID;
    cout<<"Give Contact Number: ";
    cin>>contact_no;
    cout<<"Enter the payment for 1: ";
    cin>>payment;
    cout<<"Enter no of items: ";
    cin>>items;
}
virtual void displayDetails()
{
    cout<<"Name is : "<<name<<endl;
    if(age>0)
    {
    cout<<"Age is: "<<age<<endl;
    }
    else
    {
    cout<<"Invalid age";
    }
    cout<<"ID is : "<<ID<<endl;
    cout<<"Contact number is: "<<contact_no<<endl;
}
virtual void calculatepayment()
{
    if (payment<0||items<0) 
    {
        throw PaymentException("Negative payment or items count.");
    }
    int amount=payment*items;
    cout<<"The total payable amount is: "<<amount<<endl;
}
virtual ~Person()
{
    cout<<"Destructor called"<<endl;
}
};
class Student:public Person
{
private:
int idd;
string namee;
string enroll_date;
string program;
float GPA;
public:
Student()
{
    enroll_date="N/A";
    program="N/A";
    GPA=0.0;
    cout<<"Default constructor called"<<endl;
}
Student(string e,string p,float g)
{
    enroll_date=e;
    program=p;
    GPA=g;
    cout<<"Parametrized constructor called for class Student."<<endl;
}
void set()
{
    cout<<"Enter enrollment date: ";
    cin>>enroll_date;
    cout<<"Enter Program name: ";
    cin>>program;
    cout<<"Enter the GPA scored: ";
    cin>>GPA;
}
void displayDetails() override
{
    cout<<"Enroll date is : "<<enroll_date<<endl;
    cout<<"Program name is: "<<program<<endl;
    if(GPA>0.0 && GPA<=4.0)
    {
    cout<<"GPA of each student is : "<<GPA<<endl;
    }
}
void calculatepayment() override
{
cout<<"Student has scholarship. payment reduced to zero."<<endl;
}
~Student()
{
    cout<<"Destructor called"<<endl;
}
Student(int id, string name) 
{
if (id<= 0) throw InvalidIDException();
if (name.empty()) throw EmptyNameException();
this->idd= id;
this->namee=name;
}
void display() const
{
cout<<"Student ID: "<<idd<<",Name: "<<namee<<endl;
}
};
class StudentWithCourses:public Student 
{
private:
Course* courses[5];
int courseCount=0;
public:
void enrollCourse(Course* c) 
{
    if (courseCount<5) 
    {
        courses[courseCount++]=c;
    }
}
void listCourses() 
{
    for (int i=0;i<courseCount;i++) 
    {
        courses[i]->display();
    }
}
};    
class underGraduateStudent:public Student
{
private:
string major,minor,graduationdate;
public:
underGraduateStudent(string e,string p,float g,string mj,string mn,string gd):Student(e,p,g),major(mj),minor(mn),graduationdate(gd)
{
    cout<<"UnderGraduatestudent constructor called"<<endl;
}
void displayDetails() override
{
Student::displayDetails();
cout<<"Manjot: "<<major<<"\n Minor"<<minor<<"\n Graduation date: "<<graduationdate<<endl;
}
void calculatepayment() override
{
cout<<"Undergraduate Student with 30 percent scholarship "<<endl;
}
};
class GraduateStudent:public Student
{
private:
string researchTopic,advisor,thesisTitle;
public:
GraduateStudent(string e,string p,float g,string rt,string adv,string tt): Student(e,p,g),researchTopic(rt),advisor(adv),thesisTitle(tt)
{
    cout << "GraduateStudent constructor called\n";
}
void displayDetails() override 
{
    Student::displayDetails();
    cout<<"Research Topic: "<<researchTopic<<"\nAdvisor: "<<advisor<<"\nThesis: "<< thesisTitle<<endl;
}
void calculatepayment() override 
{
    cout << "Graduate Student with full assistantship. No payment required.\n";
}
};
class GraduateStudentWithAdvisor:public GraduateStudent 
{
private:
Professor* advisor;
public:
void trackTeachingAssistantship(string courseName) 
{
    cout<<"Graduate student assisting in teaching course: "<<courseName<<endl;
}
void trackResearchAssistantship(string projectName) 
{
    cout<<"Graduate student assisting in research project: "<<projectName<<endl;
}
GraduateStudentWithAdvisor(string e,string p,float g,string rt,string ad,string tt,Professor* a):GraduateStudent(e,p,g,rt,ad,tt),advisor(a){}
void showAdvisor() 
{
    if(advisor) 
    {
        cout<<"Advisor Details:"<<endl;
        advisor->displayDetails();
    } 
    else 
    {
        cout<<"No advisor assigned."<<endl;
    }
}
};
class Professor:public Person
{
private:
string department;
string specialization;
string hire_date;
public:
Professor()
{
    department="N/A";
    specialization="N/A";
    hire_date="-";
    cout<<"Default constructor called"<<endl;
}
Professor(string d,string sp,string h)
{
    department=d;
    specialization=sp;
    hire_date=h;
    cout<<"Parametrized constructor called"<<endl;
}
void set()
{
    cout<<"Enter Department name: ";
    cin>>department;
    cout<<"Enter specialization name: ";
    cin>>specialization;
    cout<<"Enter the hire date: ";
    cin>>hire_date;
}
void displayDetails() override
{
    cout<<"Department name is : "<<department<<endl;
    cout<<"Specialisation name is: "<<specialization<<endl;
    cout<<"Hire date was : "<<hire_date<<endl;
}
void calculatepayment() override 
{
    cout<<"Professor recieves the salary. Monthly salary fixed to 70,000 "<<endl;
}
~Professor()
{
    cout<<"Destructor called"<<endl;
}
};
class Assistantprofessor:public Professor 
{
private:
bool isTenureTrack;
public:
Assistantprofessor(string d,string sp,string h,bool tenure):Professor(d,sp,h),isTenureTrack(tenure) 
{
    cout << "AssistantProfessor constructor called."<<endl;
}
void displayDetails() override 
{
    Professor::displayDetails();
    cout<<"Tenure Track: "<<(isTenureTrack?"Yes":"No")<<endl;
}
void calculatepayment() override 
{
    cout<<"Assistant Professor salary: 50,000."<<endl;
}
};
class AssociateProfessor:public Professor 
{
private:
int publicationsRequired;
public:
AssociateProfessor(string d,string sp,string h,int pubs):Professor(d,sp,h),publicationsRequired(pubs) 
{
    cout<<"AssociateProfessor constructor called."<<endl;
}
void displayDetails() override 
{
    Professor::displayDetails();
    cout<<"Publications Required: "<<publicationsRequired<<endl;
}
void calculatepayment() override 
{
cout<<"Associate Professor salary: 65,000 "<<endl;
}
};
class FullProfessor : public Professor 
{
private:
int yearsOfExperience;
public:
FullProfessor(string d,string sp,string h,int yoe):Professor(d,sp,h),yearsOfExperience(yoe)
{
    cout<<"FullProfessor constructor called "<<endl;
}
void displayDetails() override 
{
    Professor::displayDetails();
    cout<<"Years of Experience: "<<yearsOfExperience<<endl;
}
void calculatepayment() override 
{
    cout<<"Full Professor salary: 80,000 "<<endl;
}
};
class Course
{
public:
string course_code;
string title;
int credits;
string description;
public:
Course()
{
    course_code="N/A";
    title="N/A";
    credits=0;
    description="N/A";
    cout<<"Default constructor called"<<endl;
}
Course(string cc,string t,int cr,string de)
{
    course_code=cc;
    title=t;
    credits=cr;
    description=de;
    cout<<"Parametrized constructor called"<<endl;
}
void set()
{
    cout<<"Enter the course code: ";
    cin>>course_code;
    cout<<"Enter the title: ";
    cin.ignore();
    getline(cin,title);
    cout<<"Enter the credit points: ";
    cin>>credits;
    cout<<"Enter the description: ";
    getline(cin,description);
}
void displayDetails()
{
    cout<<"Course code is : "<<course_code<<endl;
    cout<<"Course title is: "<<title<<endl;
    if(credits>0)
    {
    cout<<"Credits are : "<<credits<<endl;
    }
    cout<<"Description is: "<<description<<endl;
}
Course(string course_code, string title) 
{
if (course_code.empty()) throw InvalidIDException();
if (title.empty()) throw EmptyNameException();
this->course_code =course_code;
this->title=title;
}
void display() const 
{
cout<<"Course ID: "<<course_code<<", Name: "<<title<<endl;
}
~Course()
{
    cout<<"Destructor called"<<endl;
}
};
class CourseWithInstructor:public Course 
{
private:
Professor* instructor;
public:
CourseWithInstructor():instructor(nullptr){}
void assignInstructor(Professor* p) 
{
    instructor=p;
}
void showInstructor() 
{
    if (instructor) 
    {
        cout<<"Instructor details:"<<endl;
        instructor->displayDetails();
    } 
    else 
    {
        cout<<"No instructor assigned."<<endl;
    }
}
};
class Department
{
private:
string name;
string location;
int budget;
public:
Department()
{
    name="-";
    location="N/A";
    budget=0;
    cout<<"Default constructor called"<<endl;
}
Department(string name_,string loc,int bud)
{
    name=name_;
    location=loc;
    budget=bud;
    cout<<"Parametrized constructor called"<<endl;
}
void set()
{
    cout<<"Enter the department name: ";
    cin>>name;
    cout<<"Enter the department location: ";
    cin>>location;
    cout<<"Enter the budget: ";
    cin>>budget;
}
void display()
{
    cout<<"Name is : "<<name<<endl;
    cout<<"Location is: "<<location<<endl;
    cout<<"Budget is : "<<budget<<endl;
}
~Department()
{
    cout<<"Destructor called"<<endl;
}
};
class DepartmentWithProfessors:public Department 
{
private:
Professor profs[10];
int profCount = 0;
public:
void addProfessor(const Professor& p) 
{
    if(profCount<10) 
    {
        profs[profCount++]=p;
    }
}
void listProfessors() 
{
    for(int i=0;i<profCount;i++) 
    {
        profs[i].displayDetails();
    }
}
};
class University 
{
private:
Department departments[10];
int deptCount=0;
public:
void addDepartment(const Department& d) 
{
    if (deptCount<10) 
    {
        departments[deptCount++]=d;
    }
}
void listDepartments() 
{
    for (int i = 0; i < deptCount; i++) 
    {
        departments[i].display();
    }
}
};   
class GradeBook
{
private:
string studentID[100];
float grades[100];
int count;
public:
GradeBook()
{
    count=0;
}
void addGrade(string stud,float grade)
{
    if(grade<0.0||grade>100.0) 
    {
        throw GradeException(grade);
    }
studentID[count]=stud;
grades[count]=grade;
count++;
}
void showGrade()
{
    cout<<"Student ID's and Grades: \n";
    for(int i=0;i<count;i++)
    {
    cout<<"Student ID: "<<studentID[i]<<"\t"<<"Grades: "<<grades[i]<<endl;
    }
}
void getcalcAvgGrades()
{
float sum=0;float average;
for(int j=0;j<count;j++)
{
    sum=sum+grades[j];
}
average=sum/count;
cout<<"The average grades for the students are: "<<average<<endl;
}
void getHighestGrade()
{
float highest=grades[0];int k;
string topStudent=studentID[0];
for(k=0;k<count;k++)
{
    if(grades[k]>highest)
    {
        highest=grades[k];
    }
}
cout<<"The highest grades scored are: "<<highest<<" and are scored by: "<<topStudent<<endl;
}
void getFailStudents()
{
    int count1=0;
    for(int l=0;l<count;l++)
    {
        if(grades[l]<33.0)
        {
            count1++;
            cout<<studentID[l]<<" has failed the exam."<<endl;
        }
    }
    cout<<"Total number of students who failed are: "<<count1<<endl;
}
};
class EnrollmentManager
{
private:
string studentIDS[100];
string ctitle[50];
int count;
public:
EnrollmentManager()
{
    count=0;
}
void add(string stud,string titlee)
{
studentIDS[count]=stud;
ctitle[count]=titlee;
count++;
}
void display()
{
    cout<<"Student ID's and respective courses are : \n";
    for(int i=0;i<count;i++)
    {
    cout<<"Student ID: "<<studentIDS[i]<<"\t"<<"Course: "<<ctitle[i]<<endl;
    }
}
void EnrollStudent(string study)
{
    if(study.empty()) 
    {
        throw EnrollmentException("Empty ID");
    }
    studentIDS[count]=study;
    cout<<"Student "<<study<<" is enrolled."<<endl;
    count++;
}
void dropStudent()
{
string idToDrop;
cout << "Enter the Student ID to drop: ";
cin >> idToDrop;
bool found = false;
for(int i = 0; i < count; i++)
{
    if(studentIDS[i] == idToDrop)
    {
        studentIDS[i] = "";  // Mark as dropped
        found = true;
        cout << "Student "<<idToDrop<<" dropped successfully."<<endl;
        break;
    }
}
if(!found)
{
    cout<<"Student ID not found."<<endl;
}
}
void getenrollmentcount()
{
cout<<"No. of enrollments are: "<<count<<endl;
}
};
class Classroom 
{
private:
string roomNumber;
int capacity;
public:
Classroom(string room, int cap):roomNumber(room),capacity(cap){}
void display() 
{
    cout << "Room: " << roomNumber << ", Capacity: " << capacity << endl;
}
};
class Schedule 
{
private:
string timeSlot;
Classroom* classroom;
public:
Schedule(string time,Classroom* c):timeSlot(time),classroom(c){}
void showSchedule() 
{
cout<<"Time Slot: "<<timeSlot<<endl;
if(classroom)
classroom->display();
}
};    
void testPolymorphism(Person* p) 
{
p->displayDetails();
p->calculatepayment();
}
class UniversityManagementSystem 
{
private:
vector<Student> students;
vector<Course> courses;
public:
void addStudent() 
{
int id;
string name;
cout << "Enter Student ID: ";
cin >> id;
cin.ignore();
cout << "Enter Student Name: ";
getline(cin, name);
try {
Student s(id, name);
students.push_back(s);
cout << "Student added successfully!\n";
} 
catch (const exception& e) 
{
cerr << e.what() << endl;
}
}
void addCourse() 
{
string id1;
string name;
cin.ignore();
cout << "Enter Course Name: ";
getline(cin, name);
cout<<"Enter the course code :";
getline(cin,id1);
try {
Course c(id1,name);
courses.push_back(c);
cout<<"Course added successfully!"<<endl;
}
catch(const exception& e)
{
cerr<<e.what() << endl;
}
}
void displayStudents() const 
{
if (students.empty()) 
{
cout << "No students to display.\n";
return;
}
cout << "\n--- List of Students ---\n";
for (const auto& s : students) 
{
s.display();
}
}
void viewCourses() const 
{
if (courses.empty()) 
{
cout << "No courses to display.\n";
return;
}
cout << "\n--- List of Courses ---\n";
for (const auto& c : courses) 
{
c.display();
}
}
void menu();
};
void menu() 
{
    int choice;
    while(true)
    {
        cout << "\n----- University Management System -----\n";
        cout << "1. Add Student\n";
        cout << "2. Add Course\n";
        cout << "3. Display Students\n";
        cout << "4. Display Courses\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        try {
            // Check for valid menu choice range
            if(choice < 1 || choice > 5) {
                throw out_of_range("Invalid menu choice. ");
            }

            // Switch statement based on user's choice
            switch (choice) 
            {
                case 1: 
                    addStudent(); 
                    break;
                case 2: 
                    addCourse(); 
                    break;
                case 3: 
                    displayStudents(); 
                    break;
                case 4: 
                    viewCourses(); 
                    break;
                case 5: 
                    cout << "Exiting system. Goodbye!\n"; 
                    return; // Exit the menu loop
                default:
                    cout << "Invalid choice. Try again.\n";
                    break;
            }
        }
        catch(const exception &e) 
        {
            cerr << "Error: " << e.what() << endl;
        }
    }
}
    
                                        // main block 
int main()
{
try 
{
GradeBook gb;
gb.addGrade("S101", 105.0);
} 
catch(const UniversitySystemException& e) 
{
    cout << "Exception caught: " << e.what() << endl; 
}
Person p1;
//Person p1();
Person p2("Mansi",18,"abc123","9876543210",400,24);
p1.Person::set();
p1.Person::displayDetails();
p1.Person::calculatepayment();
Student s1;
Student s2("12/04/25","B.Tech",3.5);
s1.Student::set();
s1.Student::displayDetails();
Professor a1;
Professor a2("Physics","CSE","12/12/2006");
a1.Professor::set();
a1.Professor::displayDetails();
Course c1;
Course c2("PYL150","ENGINEERING PHYSICS",3,"Nice");
c1.Course::set();
c1.Course::display();
Department d1;
Department d2("Physics","RN104",40000);
d1.Department::set();
d1.Department::display();
cout << "\n Polymorphism Demonstration \n";
Person* people[2]; // array base class pointer
people[0] = new Student("01/01/24", "B.Tech", 3.8); //Student and Professor objects
people[1] = new Professor("Maths", "AI", "10/10/2010");
for(int i = 0; i < 2; ++i) 
{
testPolymorphism(people[i]);//calling test polymorphismmmm
cout << "Testing done."<<endl;
delete people[i]; //Memory deleted 
}
underGraduateStudent ug("12/12/2024","B.Tech",3.7,"CSE","Math","2028");
GraduateStudent gs("28/28/2021","M.Tech",3.9,"DATA SCIENCE","Dr.Rajni","Data");
Assistantprofessor ap("CSE","AIML","2019",true);
AssociateProfessor asp("EE","Diffraction","2012",10);
FullProfessor fp("ME","Thermodynamics","2005",20);
cout<<"Undergrad Details:"<<endl;
ug.displayDetails();
ug.calculatepayment();

cout<<"Graduate Details:"<<endl;
gs.displayDetails();
gs.calculatepayment();

cout<<"Assistant Professor Details:"<<endl;
ap.displayDetails();
ap.calculatepayment();

cout<<"Associate Professor Details:"<<endl;
asp.displayDetails();
asp.calculatepayment();

cout<<"Full Professor Details:"<<endl;
fp.displayDetails();
fp.calculatepayment();

UniversityManagementSystem ums;
ums.menu();
return 0;
}