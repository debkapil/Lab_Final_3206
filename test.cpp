//command
//clang++ -std=c++17 -isystem /opt/homebrew/include -L/opt/homebrew/lib -lgtest -lgtest_main -pthread test.cpp -o test
//./test

//git status
//git add .
//git commit -m "Second commit"
//git push -u origin main

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class StudentManager {
private:
    vector<string> students;

    StudentManager() {}  

    StudentManager(const StudentManager&) = delete;
    StudentManager& operator=(const StudentManager&) = delete;

public:
    static StudentManager& getInstance() {
        static StudentManager instance;
        return instance;
    }

    void addStudent(const string& name) {
        students.push_back(name);
        cout << "Added student: " << name << endl;
    }

    void removeStudent(const string& name) {
        auto it = find(students.begin(), students.end(), name);
        students.erase(it);
        cout << "Removed student: " << name << endl;
    }

    void displayStudents() const {
        cout << "\nStudent List:\n";
        if (students.empty()) {
            cout << "No students in the list.\n";
            return;
        }
        for (const auto& name : students) {
            cout << "- " << name << '\n';
        }
    }
};

int main() {
    StudentManager& manager = StudentManager::getInstance();

    manager.addStudent("ayan");
    manager.addStudent("joy");
    manager.addStudent("raton");
    manager.addStudent("mamun");

    manager.displayStudents();

    manager.removeStudent("mamun");
    manager.removeStudent("raton"); 

    manager.displayStudents();

    return 0;
}



