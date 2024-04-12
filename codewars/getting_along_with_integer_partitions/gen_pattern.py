import math

def part(n):
    if n == 0:
        return [[]]
    partitions = []
    for i in range(1, n + 1):
        for partition in part(n - i):
            partitions.append([i] + partition)
    return partitions

number = int(input('number: '))
parts = part(number)

def mul(arr):
    a = 1
    for b in arr:
        a *= b
    return a

results = []
for p in parts:
    results += [mul(p)]
results = list(sorted(set(results)))

range = results[-1] - results[0]
average = sum(results) / len(results)
median = results[len(results) // 2] if len(results) % 2 == 1 else (results[len(results) // 2] + results[len(results) // 2 - 1]) / 2

print(len(results))
print(results)
print(range, average, median)
