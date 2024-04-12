#include <iostream>
#include <vector>

#include "task.h"


struct TestTo {
    int input;
    std::string output;
};

struct TestFrom {
    std::string input;
    int output;
};

int main() {
    std::vector<TestTo> tests_to  = {
        {1000, "M"},
        {4, "IV"},
        {1, "I"},
        {9, "IX"},
        {1990, "MCMXC"},
        {2008, "MMVIII"},
        {3999, "MMMCMXCIX"}
    };

    for (auto &t : tests_to) {
        std::cout << "TEST_CASE: " << t.input << " - ";
        if (RomanNumerals.to_roman(t.input) != t.output) {
            std::cout << "FAILURE(EXPECTED: " << t.output << " GOT: " << RomanNumerals.to_roman(t.input) << ")" << std::endl;
        } else {
            std::cout << "SUCCESS" << std::endl;
        }
    }

    std::vector<TestFrom> tests_from = {
        {"XXI", 21},
        {"I", 1},
        {"IX", 9},
        {"IV", 4},
        {"MMVIII", 2008},
        {"MDCLXVI", 1666},
        {"MMMCMXVI", 3916}
    };

    for (auto &t : tests_from) {
        std::cout << "TEST_CASE: " << t.input << " - ";
        if (RomanNumerals.from_roman(t.input) != t.output) {
            std::cout << "FAILURE(EXPECTED: " << t.output << " GOT: " << RomanNumerals.from_roman(t.input) << ")" << std::endl;
        } else {
            std::cout << "SUCCESS" << std::endl;
        }
    }

    return 0;
}


