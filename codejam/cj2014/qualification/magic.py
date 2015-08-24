import sys

n = int(sys.stdin.readline())

for i in range(1, n + 1):
    ans1 = int(sys.stdin.readline()) - 1
    d1 = []
    for u in range(4):
        d1.append(map(int, sys.stdin.readline().strip().split()))
    ans2 = int(sys.stdin.readline()) - 1
    d2 = []
    for u in range(4):
        d2.append(map(int, sys.stdin.readline().strip().split()))

    s1 = frozenset(d1[ans1])
    s2 = frozenset(d2[ans2])
    s = s1 & s2
    #print s1, s2, s

    sys.stdout.write("Case #%d: " % i)
    if len(s) == 1:
        st = str(next(iter(s)))
    elif len(s) > 1:
        st = "Bad magician!"
    else:
        st = "Volunteer cheated!"
    sys.stdout.write(st + "\n")

