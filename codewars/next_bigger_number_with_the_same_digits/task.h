#include <set>
#include <vector>


long nextBigger(long n) {
    long n_ = n;

    std::vector<int> digits;
    while(n_) {
        digits.push_back(n_ % 10);
        n_ /= 10;
    }

    bool found = false;
    int swap_idx = -1;
    int swapped_idx = -1;

    std::multiset<std::pair<int, int>> available;
    
    for(int i = 0; i < digits.size(); ++i) {
        auto larger_ptr = std::upper_bound(available.begin(), available.end(), std::make_pair(digits[i], i));
        available.insert({digits[i], i});

        if (larger_ptr == available.end() || larger_ptr->first == digits[i]) {
            continue;
        }

        found = true;
        swap_idx = i;
        swapped_idx = larger_ptr->second;
        break;
    }

    if (found == false)
        return -1;

    std::swap(digits[swap_idx], digits[swapped_idx]);

    std::vector<int> larger_d;
    for(int i = 0; i < swap_idx; ++i)
        larger_d.push_back(digits[i]);
    std::sort(larger_d.begin(), larger_d.end(), [](int a, int b) { return a > b; });
    for(int i = swap_idx; i < digits.size(); ++i)
        larger_d.push_back(digits[i]);

    n_ = 0;
    std::reverse(larger_d.begin(), larger_d.end());
    for(auto &d : larger_d)
        n_ = (n_ * 10 + d);

    return n_;
}
