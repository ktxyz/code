#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

class RomanHelper
{
public:
    std::string to_roman(unsigned int n)
    {
        long k = n;
        std::vector<std::pair<std::string, int>> roman_values = {
            {"I", 1},
            {"IV", 4},
            {"V", 5},
            {"IX", 9},
            {"X", 10},
            {"XL", 40},
            {"L", 50},
            {"XC", 90},
            {"C", 100},
            {"CD", 400},
            {"D", 500},
            {"CM", 900},
            {"M", 1000}
        };

        std::string result;

        for (int i = roman_values.size() - 1; i >= 0; --i)
        {
            while (k - roman_values[i].second >= 0)
            {
                result += roman_values[i].first;
                k -= roman_values[i].second;
            }
        }

        return result;
    }

    int from_roman(const std::string &rn)
    {
        std::unordered_map<std::string, int> roman_values = {
            {"I", 1},
            {"IV", 4},
            {"V", 5},
            {"IX", 9},
            {"X", 10},
            {"XL", 40},
            {"L", 50},
            {"XC", 90},
            {"C", 100},
            {"CD", 400},
            {"D", 500},
            {"CM", 900},
            {"M", 1000}};

        int result = 0;

        int i = 0;
        while (i < rn.size()) {
            std::string c;
            c.push_back(rn[i++]); 
            if (rn.size() >= (i + 1)) {
                if (roman_values.count(c + rn[i])) {
                    c.push_back(rn[i++]);
                } else {
                }
            }

            result += roman_values[c];
        }

        return result;
    }
} RomanNumerals;
