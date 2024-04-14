import math


def doubles(maxk, maxn):
    answer = 0
    for k in range(1, maxk + 1):
        for n in range(1, maxn + 1):
            val = 1 / (k * (n + 1)**(2 * k))
            if val < 1e-15:
                break
            answer += val
    return answer
