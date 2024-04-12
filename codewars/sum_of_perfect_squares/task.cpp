#include <iostream>
#include <vector>

#include "task.h"


struct Test {
    int input;
    int output;
};

int main() {
    std::vector<Test> tests  = {
        {15, 4},
        {16, 1},
        {17, 2},
        {18, 2},
        {19, 3},
        {710961384, 3},
        {644095981, 2}
    };

    for (auto &t : tests) {
        std::cout << "TEST_CASE: " << t.input << " - ";
        if (sum_of_squares(t.input) != t.output) {
            std::cout << "FAILURE(EXPECTED: " << t.output << " GOT: " << sum_of_squares(t.input) << ")" << std::endl;
        } else {
            std::cout << "SUCCESS" << std::endl;
        }
    }

    return 0;
}


