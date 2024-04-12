#include <iostream>
#include <vector>

#include "task.h"


struct Test {
    int input;
    int output;
};

int main() {
    std::vector<Test> tests  = {
        {10, 22},
        {20, 57},
        {30, 91},
        {50, 175}
    };

    for (auto &t : tests) {
        std::cout << "TEST_CASE: " << t.input << " - ";
        if (DoubleLinear::dblLinear(t.input) != t.output) {
            std::cout << "FAILURE(EXPECTED: " << t.output << " GOT: " << DoubleLinear::dblLinear(t.input) << ")" << std::endl;
        } else {
            std::cout << "SUCCESS" << std::endl;
        }
    }

    return 0;
}


