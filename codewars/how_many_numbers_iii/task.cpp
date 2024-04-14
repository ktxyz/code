#include <iostream>
#include <vector>

#include "task.h"


struct Test {
    std::uint32_t input1, input2;
    std::optional<out_t> output;
};

int main() {
    std::vector<Test> tests  = {
        {10, 3, std::optional<out_t>(out_t(8, 118, 334))},
        {27, 3, std::optional<out_t>(out_t(1, 999, 999))},
        {84, 4, std::nullopt},
        {35, 6, std::optional<out_t>(out_t(123, 116999, 566666))}
    };

    for (auto &t : tests) {
        std::cout << "TEST_CASE: " << t.input1 << "->" <<  t.input2 << " - ";
        auto result = find_all(t.input1, t.input2);
        if (result != t.output) {
            if (result.has_value() && t.output.has_value())
                std::cout << "FAILURE(EXPECTED: " << std::get<2>(t.output.value()) << " GOT " << std::get<2>(result.value()) << ")" << std::endl;
            else
                std::cout << "FAILURE" <<  std::endl;
        } else {
            std::cout << "SUCCESS" << std::endl;
        }
    }

    return 0;
}


