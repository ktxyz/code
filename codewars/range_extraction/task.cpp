#include <iostream>
#include <vector>

#include "task.h"


struct Test {
    std::vector<int> input;
    std::string output;
};

int main() {
    std::vector<Test> tests  = {
        {{-6,-3,-2,-1,0,1,3,4,5,7,8,9,10,11,14,15,17,18,19,20}, "-6,-3-1,3-5,7-11,14,15,17-20"},
        {{-3,-2,-1,2,10,15,16,18,19,20}, "-3--1,2,10,15,16,18-20"}
    };

    for (auto &t : tests) {
        std::cout << "TEST_CASE: " << t.output << " - ";
        if (range_extraction(t.input) != t.output) {
            std::cout << "FAILURE(EXPECTED: " << t.output << " GOT: " << range_extraction(t.input) << ")" << std::endl;
        } else {
            std::cout << "SUCCESS" << std::endl;
        }
    }

    return 0;
}


