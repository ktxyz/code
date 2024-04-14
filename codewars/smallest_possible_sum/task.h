#include <vector>
#include <numeric>


using ullong = unsigned long long;

ullong solution(const std::vector<ullong>& arr){
    if (arr.empty())
        return {};

    ullong n = arr[0];
    for(auto i = 1; i < arr.size(); ++i)
        n = std::gcd(n, arr[i]);
    
    return n * arr.size();
}
