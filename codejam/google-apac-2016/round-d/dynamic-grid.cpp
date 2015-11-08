#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <cstring>

using namespace std;

int R, C;
int last_ans = -1;
bool changed = false;
vector<string> d;
vector<vector<bool>> visited;

int dx[] = { 0, 1, 0,-1};
int dy[] = { 1, 0,-1, 0};

void dfs(int x, int y) {
    if (x < 0 || x >= R || y < 0 || y >= C || visited[x][y] || d[x][y] == '0')
        return;
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
        dfs(x + dx[i], y + dy[i]);
}

int query() {
    if (last_ans != -1 && !changed) {
        return last_ans;
    }
    int ans = 0;

    for (auto& each : visited)
        each.assign(C, false);
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            if (d[i][j] == '1' && !visited[i][j]) {
                ans++;
                dfs(i, j);
            }
        }

    last_ans = ans;
    changed = false;
    return ans;
}

void update() {
    int x, y;
    char z;
    cin >> x >> y >> z;
    assert(z == '0' || z == '1');
    if (d[x][y] != z) {
        d[x][y] = z;
        changed = true;
    }
}

void work() {
    cin >> R >> C;
    d.resize(R);
    for (int i = 0; i < R; i++) {
        cin >> d[i];
        assert(d[i].length() == C);
    }
    visited.resize(R);
    last_ans = -1;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        switch (c) {
            case 'Q':
                cout << query() << endl;
                break;
            case 'M':
                update();
                break;
            default:
                assert(false);
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ":" << endl;
        work();
    }
}
