/*
 * Contest: Google APAC 2016 University Graduates Test - Round C
 * Problem: gRanks
 * Author: Qin Liu
 *
 * Tag: simulation
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

bool compare(pair<string, int> a, pair<string, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ":" << endl;
        int P, N, M;

        cin >> P;
        vector<int> S(P);
        for (int i = 0; i < P; i++)
            cin >> S[i];

        cin >> N;
        unordered_map<string, vector<int> > scores;
        for (int i = 0; i < N; i++) {
            int W;
            cin >> W;
            for (int j = 0; j < P; j++) {
                string name;
                cin >> name;
                scores[name].push_back(W * S[j]);
            }
        }

        cin >> M;

        vector<pair<string, int> > rank;
        for (auto& kv : scores) {
            sort(kv.second.begin(), kv.second.end(), greater<int>());
            int score = 0;
            for (int i = 0; i < min(M, (int) kv.second.size()); i++)
                score += kv.second[i];
            rank.push_back(make_pair(kv.first, score));
        }

        sort(rank.begin(), rank.end(), compare);

        int r = 1;
        for (size_t i = 0; i < rank.size(); i++) {
            if (i > 0 && rank[i].second == rank[i-1].second) {
            } else
                r = i+1;
            cout << r << ": " << rank[i].first << endl;
        }
    }
}
