import math


def proper_fractions(n):
    if n == 1:
        return 0
    phi = 1
    for i in range(2, int(math.sqrt(n)) + 1):
        p = 0
        while n % i == 0:
            p += 1
            n = n // i
        if p > 0:
            phi *= i**(p - 1) * (i - 1)
    if n != 1:
        phi *= n - 1
    return phi
