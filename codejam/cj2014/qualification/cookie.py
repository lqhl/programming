from sys import stdin, stdout

n = int(stdin.readline())

for case_no in range(1, n + 1):
    d = map(float, stdin.readline().strip().split())
    C, F, X = tuple(d[:3])
    ans = X / 2
    for f in range(max(0, int(X / C) - 50), int(X / C) + 1):
    #for f in range(1, int(X / C) + 1):
        cost = sum(map(lambda i: C / (i * F + 2), range(f))) + X / (f * F + 2)
        ans = min(ans, cost)
    stdout.write("Case #%d: %.7lf\n" % (case_no, ans))
