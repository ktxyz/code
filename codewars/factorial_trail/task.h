#include <cmath>
#include <algorithm>

using llong = long long;


int Zeroes (int base, int number)
{
    auto count = [&](int p) {
        int count = 0;
        int p_ = p;
        int base_ = base;

        while (number >= p_) {
            count += number / p_;
            p_ *= p;
        }

        return count;
    };
    
    int answer = 1e9;
    int base_ = base;
    for(int i = 2; i <= base; ++i) {
        if (base_ % i != 0) {
            continue;
        }

        auto answer_ = count(i);
        int pow = 0;
        while (base_ % i == 0) {
            base_ /= i;
            ++pow;
        }

        answer = std::min(answer, answer_ / pow);
    }

    return answer;
}
