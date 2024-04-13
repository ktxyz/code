#include <iostream>
#include <vector>

#include "task.h"


struct Test {
    long input;
    long output;
};

int main() {
    std::vector<Test> tests  = {
        {12, 21},
        {513, 531},
        {2017, 2071},
        {414, 441},
        {144, 414},
        {10990, 19009}
    };

    for (auto &t : tests) {
        std::cout << "TEST_CASE: " << t.input << " - ";
        if (nextBigger(t.input) != t.output) {
            std::cout << "FAILURE(EXPECTED: " << t.output << " GOT: " << nextBigger(t.input) << ")" << std::endl;
        } else {
            std::cout << "SUCCESS" << std::endl;
        }
    }

    return 0;
}


