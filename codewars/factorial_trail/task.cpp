#include <iostream>
#include <vector>

#include "task.h"


struct Test {
    int input1;
    int input2;
    int output;
};

int main() {
    std::vector<Test> tests  = {
        {10, 10, 2},
        {16, 16, 3},
        {7, 50, 8},
        {12, 26, 10},
        {22, 3929, 391},
        {2, 524288, 524287}
    };

    for (auto &t : tests) {
        std::cout << "TEST_CASE: " << t.input1 << " " << t.input2 << " - ";
        if (Zeroes(t.input1, t.input2) != t.output) {
            std::cout << "FAILURE(EXPECTED: " << t.output << " GOT: " << Zeroes(t.input1, t.input2) << ")" << std::endl;
        } else {
            std::cout << "SUCCESS" << std::endl;
        }
    }

    return 0;
}


