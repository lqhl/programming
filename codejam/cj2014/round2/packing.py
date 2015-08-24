from sys import stdin, stdout
from fractions import gcd
from math import log

T = int(stdin.readline())

for case_no in range(1, T + 1):
    line = map(int, stdin.readline().strip().split())
    n, x = tuple(line[:2])
    d = map(int, stdin.readline().strip().split())
    d = sorted(d)
    ans = n
    i, j = 0, n - 1
    while i < j:
        if d[i] + d[j] <= x:
            ans -= 1
            i += 1
            j -= 1
        else:
            j -= 1
    stdout.write("Case #{}: {}\n".format(case_no, ans))

