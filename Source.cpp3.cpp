#include <iostream>
#include <string>
using namespace std;
class Person {
protected:
    string name;
    string address;
public:
    Person(const string& n, const string& a) : name(n), address(a) {}

    string getName() const {
        return name;
    }
    string getAddress() const {
        return address;
    }
};
class Employee {
protected:
    int employeeID;
    double salary;
public:
    Employee(int id, double s) : employeeID(id), salary(s) {}
    int getEmployeeID() const {
        return employeeID;
    }
    double getSalary() const {
        return salary;
    }
};
class Teacher : public Person, public Employee {
private:
    string subject;
public:
    Teacher(const string& n, const string& a, int id, double s, const string& sub)
        : Person(n, a), Employee(id, s), subject(sub) {}

    string getSubject() const {
        return subject;
    }
};
int main() {
    Teacher myTeacher("John Doe", "123 Main St", 1234, 50000.0, "Math");

    cout << "Name: " << myTeacher.getName() << endl;
    cout << "Address: " << myTeacher.getAddress() << endl;
    cout << "Employee ID: " << myTeacher.getEmployeeID() << endl;
    cout << "Salary: " << myTeacher.getSalary() << endl;
    cout << "Subject: " << myTeacher.getSubject() << endl;
    return 0;
}
