#include <iostream>

using ulong = unsigned long long;
#include "task.h"


int main() {
    std::cout << "TEST_MYSTERY" << std::endl;
    std::cout << mystery(6) << " == 5" << std::endl;
    std::cout << mystery(9) << " == 13" << std::endl;
    std::cout << mystery(19) << " == 26" << std::endl;
    std::cout << "TEST MYSTERY_INV" << std::endl;
    std::cout << mysteryInv(5) << " == 6" << std::endl;
    std::cout << mysteryInv(13) << " == 9" << std::endl;
    std::cout << mysteryInv(26) << " == 19" << std::endl;

    std::cout << "AUTO-TEST 0.1000" << std::endl;
    for(int i = 0; i < 1001; ++i) {
        if (mystery(mysteryInv(i)) != i) {
            std::cout << "RESULT: FAIL AT " << i << std::endl;
            return 1;
        }
    }
    std::cout << "RESULT: OK" << std::endl;

    return 0;
}



