//command
//clang++ -std=c++17 -isystem /opt/homebrew/include -L/opt/homebrew/lib -lgtest -lgtest_main -pthread example.cpp -o test
//./test

#include <gtest/gtest.h>

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
