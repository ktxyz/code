#include <iostream>
#include <vector>

#include "task.h"


struct Test {
    std::string input1, input2;
    int output;
};

int main() {
    std::vector<Test> tests  = {
        {"a1", "c1", 2},
        {"a1", "f1", 3},
        {"a1", "f3", 3},
        {"a1", "f4", 4},
        {"a1", "f7", 5},
        {"h1", "f8", 5}
    };

    for (auto &t : tests) {
        std::cout << "TEST_CASE: " << t.input1 << "->" <<  t.input2 << " - ";
        auto result = knight(t.input1, t.input2);
        if (result != t.output) {
            std::cout << "FAILURE(EXPECTED: " << t.output << " GOT: " << result << ")" << std::endl;
        } else {
            std::cout << "SUCCESS" << std::endl;
        }
    }

    return 0;
}


