#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int roll_number;
    int marks;

    void input() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> roll_number;
        cout << "Enter marks: ";
        cin >> marks;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << roll_number << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    Student students[5];
    for (int i = 0; i < 5; i++) {
        cout << "Enter data for student " << i + 1 << endl;
        students[i].input();
    }

    // Write data to file
    ofstream file("students.txt");
    if (file.is_open()) {
        for (int i = 0; i < 5; i++) {
            file << students[i].name << endl;
            file << students[i].roll_number << endl;
            file << students[i].marks << endl;
        }
        file.close();
        cout << "Data written to file successfully." << endl;
    }
    else {
        cout << "Unable to open file for writing." << endl;
    }

    // Read data from file
    ifstream fileRead("students.txt");
    if (fileRead.is_open()) {
        string name;
        int roll_number, marks;
        for (int i = 0; i < 5; i++) {
            getline(fileRead, name);
            fileRead >> roll_number >> marks;
            fileRead.ignore(); // Ignore newline character after reading marks
            cout << "Student " << i + 1 << ":" << endl;
            cout << "Name: " << name << endl;
            cout << "Roll Number: " << roll_number << endl;
            cout << "Marks: " << marks << endl;
            cout << endl;
        }
        fileRead.close();
        cout << "Data read from file successfully." << endl;
    }
    else {
        cout << "Unable to open file for reading." << endl;
    }

    // Modify marks for a specific student
    int roll_number_to_modify;
    cout << "Enter roll number of student to modify marks: ";
    cin >> roll_number_to_modify;

    fstream fileModify("students.txt", ios::in | ios::out);
    if (fileModify.is_open()) {
        string name;
        int roll_number, marks;
        streampos pos;
        while (getline(fileModify, name)) {
            fileModify >> roll_number >> marks;
            fileModify.ignore(); // Ignore the newline after reading marks

            if (roll_number == roll_number_to_modify) {
                cout << "Enter new marks: ";
                int new_marks;
                cin >> new_marks;

                // Move back to the position where marks start
                pos = fileModify.tellg();
                fileModify.seekp(pos - static_cast<streamoff>(to_string(marks).length()));

                // Write new marks and pad with spaces if necessary
                fileModify << new_marks;
                fileModify.close();
                cout << "Marks modified successfully." << endl;
                return 0;
            }
        }
        fileModify.close();
        cout << "Roll number not found." << endl;
    }
    else {
        cout << "Unable to open file for modification." << endl;
    }

    return 0;
}
