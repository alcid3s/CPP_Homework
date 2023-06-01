#include <gtest/gtest.h>
#include "pch.h"
#include <fstream>

// Rekenkundige functies
int Add(int a, int b) {
    return a + b;
}

int Sub(int a, int b) {
    return a - b;
}

int Divide(int a, int b) {
    return a / b;
}

int Multiply(int a, int b) {
    return a * b;
}

// Test fixture
class MyTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        // Initialisatiecode hier
    }

    virtual void TearDown() {
        // Opruimcode hier
    }

    std::ofstream output_file; // Uitvoerbestand

    virtual void SetUpTestCase() {
        output_file.open("test_results.txt"); // Open het uitvoerbestand
    }

    virtual void TearDownTestCase() {
        output_file.close(); // Sluit het uitvoerbestand
    }
};

// Testcase met ASSERT_EQ macro
TEST_F(MyTest, TestAddition) {
    // De feitelijke test
    ASSERT_EQ(Add(2, 2), 4);
}

TEST_F(MyTest, TestSubtraction) {
    ASSERT_EQ(Sub(5, 3), 2);
}

TEST_F(MyTest, TestDivision) {
    ASSERT_EQ(Divide(10, 2), 5);
}

TEST_F(MyTest, TestMultiplication) {
    ASSERT_EQ(Multiply(3, 4), 12);
}

int main(int argc, char** argv) {
    // Initialiseer het Google Test-framework
    ::testing::InitGoogleTest(&argc, argv);

    // Voer alle testcases uit
    int result = RUN_ALL_TESTS();

    return result;
}