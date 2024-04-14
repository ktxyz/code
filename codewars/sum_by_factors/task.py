import math
from collections import defaultdict


def sum_for_list(lst):
    prime_s = defaultdict(int)

    for n in lst:
        n_ = n
        for i in range(2, int(math.sqrt(abs(n))) + 1):
            if n_ % i == 0:
                prime_s[i] += n
            while n_ % i == 0:
                n_ = n_ // i
        if abs(n_) != 1:
            prime_s[abs(n_)] += n

    return sorted([[int(prime), sum] for prime, sum in prime_s.items()])
