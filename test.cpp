//command
//clang++ -std=c++17 -isystem /opt/homebrew/include -L/opt/homebrew/lib -lgtest -lgtest_main -pthread singleton.cpp -o test
//./test

#include <iostream>
#include <vector>
#include <string>

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
    }

    void removeStudent(const string& name){
        students.push_back(name);
    }

    void displayStudents() const {
        cout << "Student List:\n";
        for (const auto& name : students) {
            cout << "- " << name << '\n';
        }
    }
};

int main() {
    StudentManager& manager = StudentManager::getInstance();

    manager.addStudent("Ayan");
    manager.addStudent("Rifat");
    manager.addStudent("Joy");
    manager.addStudent("Mamun");

    manager.displayStudents();

    return 0;
}




