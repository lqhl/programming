from sys import stdin, stdout

n = int(stdin.readline())

def dfs(x, y):
    global quota, find
    cord = []
    for i in range(8):
        tx, ty = x + dx[i], y + dy[i]
        if tx >= 0 and tx < R and ty >= 0 and ty < C and m[tx][ty] == '*':
            cord.append((tx, ty))
    if quota >= len(cord):
        quota -= len(cord)
        if not find and quota == 0:
            find = True
        for tx, ty in cord:
            m[tx][ty] = '.'
        for tx, ty in cord:
            dfs(tx, ty)

for case_no in range(1, n + 1):
    stdout.write("Case #%d:\n" % case_no)
    d = map(int, stdin.readline().strip().split())
    R, C, M = tuple(d[:3])
    quota = R * C - M - 1
    m = [['*' for i in range(C)] for j in range(R)]
    m[0][0] = 'c'
    find = False
    if quota == 0:
        find = True
    if not find:
        dx = [ 1, 1, 0,-1,-1,-1, 0, 1]
        dy = [ 1, 0, 1,-1, 0, 1,-1,-1]
        dfs(0, 0)
    if not find:
        quota = R * C - M - 1
        m = [['*' for i in range(C)] for j in range(R)]
        m[0][0] = 'c'
        dx = [ 0, 1, 1,-1,-1,-1, 0, 1]
        dy = [ 1, 0, 1,-1, 0, 1,-1,-1]
        dfs(0, 0)
    if not find:
        quota = R * C - M - 1
        m = [['*' for i in range(C)] for j in range(R)]
        m[0][0] = 'c'
        dx = [ 1, 0, 1,-1,-1,-1, 0, 1]
        dy = [ 0, 1, 1,-1, 0, 1,-1,-1]
        dfs(0, 0)
    if find:
        for i in range(R):
            stdout.write(''.join(m[i]) + '\n')
    else:
        stdout.write("Impossible\n")
