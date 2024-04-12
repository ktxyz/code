#include <set>
#include <unordered_map>

using llong = long long;

std::set<llong> unprocessed;
std::set<llong> processed;

class DoubleLinear
{
public:
    static int dblLinear(int n) {
        if (processed.size() == 0)
        {
            processed.insert(1);
            unprocessed.insert(3);
            unprocessed.insert(4);
        }

        while(processed.size() <= 10 * n)
        {
            std::set<llong> new_unprocessed;
            for(auto &p : unprocessed)
            {
                processed.insert(p);
                new_unprocessed.insert(2 * p + 1);
                new_unprocessed.insert(3 * p + 1);
            }
            unprocessed = new_unprocessed;
        }

        return *std::next(processed.begin(), n);
    }
};
