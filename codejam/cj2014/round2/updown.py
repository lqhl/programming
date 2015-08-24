from sys import stdin, stdout
from fractions import gcd
from math import log

T = int(stdin.readline())

for case_no in range(1, T + 1):
    n = int(stdin.readline())
    d = map(int, stdin.readline().strip().split())
    ans = -1
    for m in range(n):
        dd = d[:]
        k = 0
        for i in range(m + 1):
            for j in range(i + 1, m + 1):
                if d[i] > d[j]:
                    d[i], d[j] = d[j], d[i]
                    k += 1
        for i in range(n - 1, m, -1):
            for j in range(i - 1, m, -1):
                if d[i] > d[j]:
                    d[i], d[j] = d[j], d[i]
                    k += 1
        if (ans == -1) or (k < ans):
                ans = k
        d = dd
    stdout.write("Case #{}: {}\n".format(case_no, ans))

