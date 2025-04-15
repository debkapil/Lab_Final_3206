//command
//clang++ -std=c++17 -isystem /opt/homebrew/include -L/opt/homebrew/lib -lgtest -lgtest_main -pthread singleton.cpp -o test
//./test

//git status
//git add .
//git commit -m "Second commit"
//git push -u origin main


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <gtest/gtest.h>

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

    void removeStudent(const string& name) {
        auto it = find(students.begin(), students.end(), name);
        if (it != students.end()) {
            students.erase(it);
        }
    }

    vector<string> getStudents() const {
        return students;
    }

    void clear() {
        students.clear();
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


TEST(StudentManagerTest, AddStudents) {
    StudentManager& manager = StudentManager::getInstance();
    manager.clear();

    manager.addStudent("Ayan");
    manager.addStudent("joy");

    vector<string> expected = {"ayan", "joy"};
    EXPECT_EQ(manager.getStudents(), expected);
}

TEST(StudentManagerTest, RemoveStudent) {
    StudentManager& manager = StudentManager::getInstance();
    manager.clear();

    manager.addStudent("kamal");
    manager.addStudent("Dav");
    manager.removeStudent("kapil");

    vector<string> expected = {"Dav"};
    EXPECT_EQ(manager.getStudents(), expected);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}




/*#include <gtest/gtest.h>

// Function Definitions
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

// Google Test Cases
TEST(AdditionTest, HandlesPositiveNumbers) {
    EXPECT_EQ(add(3, 5), 8);
}

TEST(AdditionTest, HandlesPositiveAndNegative) {
    EXPECT_EQ(add(5, -2), 3);
}

TEST(AdditionTest, HandlesPositiveAndZero) {
    EXPECT_EQ(add(7, 0), 7);
}

TEST(SubtractionTest, HandlesPositiveNumbers) {
    EXPECT_EQ(subtract(10, 4), 6);
}

TEST(SubtractionTest, HandlesPositiveAndNegative) {
    EXPECT_EQ(subtract(6, -3), 9);
}

TEST(SubtractionTest, HandlesPositiveAndZero) {
    EXPECT_EQ(subtract(9, 0), 9);
}

TEST(MultiplicationTest, HandlesPositiveNumbers) {
    EXPECT_EQ(multiply(4, 3), 12);
}

TEST(MultiplicationTest, HandlesPositiveAndNegative) {
    EXPECT_EQ(multiply(7, -2), -14);
}

TEST(MultiplicationTest, HandlesPositiveAndZero) {
    EXPECT_EQ(multiply(5, 0), 0);
}

// Main function to run all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
*/




/*creat a C++ program that uses the singleton to manage a single instance of a StudentManager
 class , which holds a list of students. Now, Implement the Singleton Pattern?*/

 //Add functionalites to add,remove and display student names

 //Write at least 2 test cases using GTest
//Use git for version control and upload the project to GitHub.
