#include <iostream>
#include <vector>

#include "task.h"


struct Test {
    llong a, b;
    llong output;
};

int main() {
    std::vector<Test> tests  = {
        {6, 4, 23},
        {30, 2, 65},
        {8, 6, 49},
        {16, 20, 333}
    };

    for (auto &t : tests) {
        std::cout << "TEST_CASE: " << t.a << " x " << t.b << " - ";
        auto result = rectangle_rotation(t.a, t.b);
        if (result != t.output) {
            std::cout << "FAILURE(EXPECTED: " << t.output << " GOT: " << result << ")" << std::endl;
        } else {
            std::cout << "SUCCESS" << std::endl;
        }
    }

    return 0;
}


