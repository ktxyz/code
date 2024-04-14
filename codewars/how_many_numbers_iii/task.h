#include <tuple>
#include <cmath>
#include <string>
#include <cstdint>
#include <optional>
#include <functional>

using out_t = std::tuple<std::uint32_t, std::uint64_t, std::uint64_t>;


std::optional<out_t> find_all(std::uint32_t digit_sum, std::uint32_t digit_count) {
    std::uint32_t count = 0;
    std::uint64_t smallest = UINT64_MAX, largest = 0;

    std::string number = "";
    std::function<void(int, int, char)> find;
    find = [&](int digits_left, int sum_left, char min_d) -> void {
        if (digits_left == 0 && sum_left == 0)
        {
            count += 1;
            std::uint64_t number_v = std::stoull(number);
            smallest = std::min(number_v, smallest);
            largest = std::max(number_v, largest);
        }

        if (digits_left == 0 || sum_left == 0)
            return;

        for (char c = min_d; c <= '9'; ++c)
        {
            number.push_back(c);
            find(digits_left - 1, sum_left - (c - '0'), c);
            number.pop_back();
        }
    };

    find(digit_count, digit_sum, '1');

    if (count == 0)
        return std::nullopt;
    return std::make_tuple(count, smallest, largest);
}