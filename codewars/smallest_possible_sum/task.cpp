#include <iostream>
#include <vector>

#include "task.h"


struct Test {
    std::vector<ullong> input;
    ullong output;
};

int main() {
    std::vector<Test> tests  = {
        {{1,21,55}, 3},
        {{3,13,23,7,83}, 5},
        {{4,16,24}, 12},
        {{30,12}, 12},
        {{60,12,96,48,60,24,72,36,72,72,48}, 132},
        {{71,71,71,71,71,71,71,71,71,71,71,71,71}, 923},
        {{11,22}, 22},
        {{9}, 9},
        {{1}, 1},
        {{9, 9}, 18}
    };

    for (auto &t : tests) {
        std::cout << "TEST_CASE: " << t.output << " - ";
        auto result = solution(t.input);
        if (result != t.output) {
            std::cout << "FAILURE(EXPECTED: " << t.output << " GOT: " << result << ")" << std::endl;
        } else {
            std::cout << "SUCCESS" << std::endl;
        }
    }

    return 0;
}


