from sys import stdin, stdout
from itertools import permutations
from collections import Counter

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
    counter = Counter(''.join(st))
    ans = 0
    for each in permutations(st):
        s = ''.join(each)
        if verify(counter, s):
            ans += 1
    stdout.write("Case #{}: {}\n".format(case_no, ans))
    stdout.flush()

