#include <iostream>
#include <vector>

#include "task.h"


struct Test {
    std::vector<std::pair<int, int>> input;
    int output;
};

int main() {
    std::vector<Test> tests  = {
        {
            {{1, 5}},
            4
        },
        {
            {{1, 5}, {6, 10}},
            8
        },
        {
            {{1, 4}, {7, 10}, {3, 5}},
            7
        },
        {
            {{-1000000000, 1000000000}},
            2000000000
        },
        {
            {{0, 20}, {-100000000, 10}, {30, 40}},
            100000030
        }
    };

    for (auto &t : tests) {
        std::cout << "TEST_CASE: " << t.output << " - ";
        auto result = sum_intervals(t.input);
        if (result != t.output) {
            std::cout << "FAILURE(EXPECTED: " << t.output << " GOT: " << result << ")" << std::endl;
        } else {
            std::cout << "SUCCESS" << std::endl;
        }
    }

    return 0;
}


