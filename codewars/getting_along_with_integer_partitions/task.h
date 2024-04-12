#include <string>
#include <sstream>
#include <functional>
#include <unordered_map>
#include <numeric>
#include <algorithm>

using llong = long long;
using ldouble = long double;


constexpr llong MAX_N = 20;
constexpr ldouble TWO = 2;

std::unordered_map<llong, std::string> mem;
std::unordered_map<llong, std::vector<llong>> mem_p;

class IntPart
{
public:
    static std::string part(llong n) {
        if (mem.count(n))
            return mem[n];

        std::function<std::vector<llong>(llong)> calc_p;
        calc_p = [&](llong x) -> std::vector<llong> {
            if (x == 1) {
                return {1};
            } else if (x == 2) {
                return {1, 2};
            } else if (mem_p.count(x)) {
                return mem_p[x];
            }

            std::vector<llong> curr_p = {x};
            for(auto i = x - 1; i >= 1; --i) {
                auto j = x - i;
                auto ip = calc_p(i);

                for(auto &ipv: ip) {
                    curr_p.push_back(ipv * j);
                }
            }

            // Make those values unique
            std::sort(curr_p.begin(), curr_p.end());
            curr_p.erase(std::unique(curr_p.begin(), curr_p.end()), curr_p.end());

            mem_p[x] = curr_p;
            return curr_p;
        };

        auto p = calc_p(n);

        std::stringstream ss;
        ss.precision(2);
        ss << "Range: " << p.back() - p.front() << " Average: ";
        ldouble avg = static_cast<ldouble>(std::accumulate(p.begin(), p.end(), 0LL)) / static_cast<double>(p.size());
        ss << std::fixed << avg << " Median: " << std::fixed << (p.size() % 2 ? p[p.size() / 2] : (static_cast<ldouble>(p[p.size() / 2] + p[p.size() / 2 - 1]) / TWO));

        mem[n] = ss.str();
        return mem[n];
    }
};