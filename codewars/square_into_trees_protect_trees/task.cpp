#include <iostream>

#include "task.h"


struct Test {
    int input;
    std::vector<llong> output;
};

int main() {
    std::vector<Test> tests  = {
        {50, {1, 3, 5, 8, 49}},
        {44, {2, 3, 5, 7, 43}},
        {2, {}}
    };

    for (auto &t : tests) {
        std::cout << "TEST_CASE: " << t.input << " - ";
        if (Decomp::decompose(t.input) != t.output) {
            std::cout << "FAILURE" << std::endl;
        } else {
            std::cout << "SUCCESS" << std::endl;
        }
    }

    return 0;
}


