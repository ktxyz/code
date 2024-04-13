#include <iostream>
#include <vector>

#include "task.h"


struct Test {
    std::vector<std::vector<int>> input;
    std::vector<int> output;
};

int main() {
    std::vector<Test> tests  = {
        {
            {{}},
            {}
        },
        {
            {{1}},
            {1}
        },
        {
            {{1, 2},
            {3, 4}},
            {1, 2, 4, 3}
        },
        {
            {{1,2,3}, {8,9,4}, {7,6,5}},
            {1, 2, 3, 4, 5, 6, 7, 8, 9}
        },
        {
            {{1,2,3,4}, {12,13,14,5}, {11,16,15,6}, {10,9,8,7}},
            {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16}
        }
    };

    for (auto &t : tests) {
        std::cout << "TEST_CASE: " << " - ";
        auto result = snail(t.input);
        if (result != t.output) {
            std::cout << "FAILURE" << std::endl;
            std::cout << "\tEXPECTED:" << std::endl;
            std::cout << "\t\t";
            for(auto &r : t.output) {
                std::cout << r << " ";
            }
            std::cout << std::endl;
            std::cout << "\tGOT:" << std::endl;
            std::cout << "\t\t";
            for(auto &r : result) {
                std::cout << r << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "SUCCESS" << std::endl;
        }
    }

    return 0;
}


