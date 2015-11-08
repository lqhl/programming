#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cassert>
#include <cstring>

using namespace std;

const int INF = 10000000;

int calc(int pos, int v) {
    if (pos == 0)
        return 0;
    if (v == 0)
        return INF;
    if (pos * v > 0)
        return INF;
    if (pos < 0) pos = -pos;
    if (v < 0) v = -v;
    return pos / v + (pos % v == 0 ? 0 : 1);
}

void work() {
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<int> velocity(M);
    for (int j = 0; j < M; j++)
        cin >> velocity[j];

    vector<int> P(N), H(N);
    for (int i = 0; i < N; i++)
        cin >> P[i] >> H[i];

    map<int, int> dp[2];
    dp[0][0] = 0;
    int cur = 0;
    int ans = INF;
    for (int i = 0; i < N; i++) {
        cur = 1-cur;
        dp[cur].clear();
        for (auto& kv : dp[1-cur]) {
            int q = kv.first;
            int t = kv.second;
            if (t < INF) {
                for (int h = 0; h < M; h++)
                    if (q + abs(h-H[i]) <= Q) {
                        int time = max(calc(P[i], velocity[h]), t);
                        if (time == INF)
                            continue;
                        auto it = dp[cur].find(q + abs(h-H[i]));
                        if (it == dp[cur].end() || time < it->second) {
                            if (it == dp[cur].end())
                                dp[cur][q + abs(h-H[i])] = time;
                            else
                                it->second = time;
                            if (i == N-1)
                                ans = min(ans, time);
                        }
                    }
            }
        }
        /* for (int q = 0; q <= Q; q++) */
        /*     if (dp[cur][q] < INF) */
        /*         cout << q << ":" << dp[cur][q] << " "; */
        /* cout << endl; */
    }
    if (ans == INF)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        work();
    }
}
