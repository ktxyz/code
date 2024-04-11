n = int(input('m:'))

t = ['0', '1']
for i in range(1, n):
    a = t
    b = t
    b = b[::-1]

    for i in range(len(a)):
        a[i] = '0' + a[i]
        b[i] = '1' + b[i]

    t = a + b

d = [int(x, 2) for x in t]
print('t', t)
print('d', d)

