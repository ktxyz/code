#include <iostream>
#include <vector>
#include <functional>
#include <unordered_map>

using llong = long long;


std::unordered_map<llong, std::vector<llong>> mem;
class Decomp {
public:
    static std::vector<llong> decompose(llong n) {
        if (n == 1) {
            return {1};
        } else if (n < 1) {
            return {};
        } else if (mem.count(n)) {
            return mem[n];
        }

        llong sq = n * n;

        std::function<std::vector<llong>(llong, llong)> find_decomp;
        find_decomp = [&](llong sum_needed, llong x) -> std::vector<llong> {
            if (sum_needed < 1) {
                return {};
            }

            for(llong k = x - 1; k >= 1; --k)
            {
                if (k * k == sum_needed) {
                    return {k};
                }

                auto k_decomp = find_decomp(sum_needed - k * k, k);
                if (!k_decomp.empty()) {
                    k_decomp.push_back(k);
                    return k_decomp;
                }
            }
            return {};
        };

        return mem[n] = find_decomp(sq, n);
    }
};