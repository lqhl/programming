from sys import stdin, stdout
from fractions import gcd
from math import log

def is_power2(num):
    'states if a number is a power of two'
    return num != 0 and ((num & (num - 1)) == 0)

n = int(stdin.readline())

for case_no in range(1, n + 1):
    line = map(int, stdin.readline().strip().split('/'))
    p, q = line[0], line[1]
    g = gcd(p, q)
    p, q = p / g, q / g
    if not is_power2(q) or q > 2**40:
        stdout.write("Case #{}: impossible\n".format(case_no))
        continue
    ans = 40 - int(log(2**40 / q * p, 2))
    stdout.write("Case #{}: {}\n".format(case_no, ans))

