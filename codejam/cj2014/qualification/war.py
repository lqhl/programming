from sys import stdin, stdout

num_case = int(stdin.readline())

for case_no in range(1, num_case + 1):
    n = int(stdin.readline())
    naomi = map(float, stdin.readline().strip().split())
    ken = map(float, stdin.readline().strip().split())
    naomi, ken = sorted(naomi), sorted(ken)
    l, x = 0, 0
    for i in range(len(naomi)):
        if naomi[i] > ken[l]:
            x += 1
            l += 1

    r, y = n - 1, 0
    for i in range(len(naomi) - 1, -1, -1):
        if naomi[i] > ken[r]:
            y += 1
        else:
            r -= 1

    stdout.write("Case #%d: %d %d\n" % (case_no, x, y))
