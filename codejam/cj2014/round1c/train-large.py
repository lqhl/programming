from sys import stdin, stdout
from itertools import permutations
from collections import Counter, defaultdict
from string import ascii_lowercase
from math import factorial

n = int(stdin.readline())

def verify(counter, s):
    count = 0
    prev = None
    for c in s:
        if c == prev:
            count += 1
        else:
            if prev and counter[prev] != count:
                return False
            count = 1
            prev = c
    if counter[prev] != count:
        return False
    return True

def dfs(starter, left, s, prefix = None):
    global counter
    if left == 0:
        if verify(counter, s):
            return 1
        else:
            return 0
    if prefix:
        if not starter[prefix]:
            return dfs(starter, left, s)
        if len(starter[prefix][0]) == 1:
            new_starter = starter.copy()
            del new_starter[prefix]
            return factorial(len(starter[prefix])) * dfs(new_starter, left -
                    len(starter[prefix]), s + ''.join(starter[prefix]))
        elif len(starter[prefix][0]) > 1:
            new_starter = starter.copy()
            del new_starter[prefix]
            return factorial(len(starter[prefix])) * dfs(new_starter, left -
                    len(starter[prefix]), s + ''.join(starter[prefix]), starter[prefix][0][-1])
        else:
            assert False
    else:
        ans = 0
        for c in ascii_lowercase:
            if starter[c]:
                ans += dfs(starter, left, s, c)
        return ans


for case_no in range(1, n + 1):
    n = int(stdin.readline())
    st = stdin.readline().strip().split()
    counter = Counter(''.join(st))
    flag = False
    for i in range(len(st)):
        if len(st[i]) > 2:
            t_counter = counter - Counter(st[i])
            if not verify(Counter(st[i]), st[i]):
                flag = True
                break
            for c in st[i][1:-1]:
                if c != st[i][0] and c != st[i][-1] and t_counter[c]:
                    flag = True
                    break
            if flag:
                break
            if st[i][0] != st[i][-1]:
                st[i] = st[i][0] + st[i][-1]
            else:
                st[i] = st[i][0]
    if flag:
        stdout.write("Case #{}: 0\n".format(case_no))
        stdout.flush()
        continue
    starter = defaultdict(list)
    for s in st:
        starter[s[0]].append(s)
    print starter
    for k in starter:
        if len(starter[k]) > 2:
            for s in starter[k]:
                if len(s) > 1:
                    flag = True
                    break
            if flag:
                break
        if len(starter[k]) == 2:
            a, b = starter[k][0], starter[k][1]
            if len(a) > len(b):
                a, b = b, a
            if len(a) < len(b):
                n -= 1
                print a, b, n
                starter[k] = [a[0] + b[-1]]
    if flag:
        stdout.write("Case #{}: 0\n".format(case_no))
        stdout.flush()
        continue
    counter = Counter(''.join(st))
    stdout.write("Case #{}: {}\n".format(case_no, dfs(starter, n, "")))
    stdout.flush()

