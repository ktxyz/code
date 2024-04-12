#include <iostream>
#include <vector>

#include "task.h"


struct Test {
    int input;
    std::string output;
};

int main() {
    std::vector<Test> tests  = {
        {1, "Range: 0 Average: 1.00 Median: 1.00"},
        {2, "Range: 1 Average: 1.50 Median: 1.50"},
        {3, "Range: 2 Average: 2.00 Median: 2.00"},
        {4, "Range: 3 Average: 2.50 Median: 2.50"},
        {5, "Range: 5 Average: 3.50 Median: 3.50"},
        {6, "Range: 8 Average: 4.75 Median: 4.50"}
    };

    for (auto &t : tests) {
        std::cout << "TEST_CASE: " << t.input << " - ";
        if (IntPart::part(t.input) != t.output) {
            std::cout << "FAILURE" << std::endl;
            std::cout << "\nEXPECTED: " << t.output << std::endl;
            std::cout << "\nGOT: " << IntPart::part(t.input) << std::endl;
        } else {
            std::cout << "SUCCESS" << std::endl;
        }
    }

    return 0;
}

