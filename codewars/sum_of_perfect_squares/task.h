#include <cmath>
#include <unordered_map>

struct PrimeFactor {
    int prime;
    int factor;
};

int sum_of_squares(int n)
{
    // perfect squares as 1
    int sqroot = std::sqrt(n);
    if (sqroot * sqroot == n)
    {
        return 1;
    }

    // numbers that dont have any prime = 3 mod 4 with odd power can be expressed as 2
    {
        int k = n;
        bool bvalid = true;
        for(int i = 2; i <= sqroot + 1; ++i) {
            int pow = 0;

            while (k % i == 0) {
                k /= i;
                ++pow;
            }

            if ((i % 4 == 3) && (pow % 2 == 1)) {
                bvalid = false;
                break;
            }
        }

        if ((k % 4 == 3))
            bvalid = false;

        if (bvalid)
            return 2;
    }

    // only numbers in form 4^a(8b + 7) can't be expressed as 3
    {
        int divded = n;
        while (divded % 4 == 0)
            divded /= 4;
        int b = divded / 8;
        if (divded % (8 * b) != 7)
            return 3;
    }

    // every number can be expressed as 4
    return 4;
}