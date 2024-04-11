#include <vector>
#include <algorithm>


std::vector<bool> to_binary(ulong n) {
    std::vector<bool> bin;
    while(n) {
        bin.push_back(static_cast<bool>(n % 2));
        n /= 2;
    }

    // we actually want inverse
    // std::reverse(bin.begin(), bin.end());
    return bin;
}

ulong get_ceil_pow(ulong a, ulong x) {
    ulong l = 1;
    while (l < a)
        l *= x;
    return l;
}

ulong mystery(ulong n) {
    n += 1;
    ulong number = 0;
    ulong length = get_ceil_pow(n, 2);

    while (length > 1) {
        number <<= 1;
        if (n > length / 2) {
            number += 1;
            n = (length / 2) - (n - (length / 2)) + 1;
        }

        length /= 2;
    }

    return number;
}

ulong mysteryInv(ulong n) {
    auto bin = to_binary(n);

    ulong pos = 1;
    ulong length = 2;
    for(size_t i = 0; i < bin.size(); ++i) {
        if (bin[i] == 1) {
            ulong distance_to_end = (length / 2) - pos + 1;
            pos = (length / 2) + distance_to_end;
        }

        length *= 2;
    }

    return pos - 1;
}

std::string nameOfMystery() {
    return "Gray code";
}

