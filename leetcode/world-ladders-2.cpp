#include <vector>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> id2w;
    unordered_map<string, int> w2id;

    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        wordList.insert(beginWord);
        wordList.insert(endWord);

        int n = 0;
        for (auto& w : wordList) {
            w2id[w] = n;
            id2w.push_back(w);
            n++;
        }
        int source = w2id[beginWord], dest = w2id[endWord];

        const int INF = n+10;
        vector<int> dist(n, INF);
        vector<vector<int>> prev(n);
        vector<bool> visited(n);
        for (auto& d : dist) d = INF;
        dist[source] = 0;
        deque<int> q;
        q.push_front(source);
        visited[source] = true;
        while (!q.empty()) {
            int head = q.front();
            q.pop_front();
            if (head == dest)
                break;
            for (int i = 0; i < id2w[head].size(); i++) {
                string v = id2w[head];
                for (char c = 'a'; c <= 'z'; c++) {
                    v[i] = c;
                    if (wordList.count(v) == 0)
                        continue;
                    int next = w2id[v];
                    if (dist[next] >= dist[head]+1) {
                        dist[next] = dist[head]+1;
                        prev[next].push_back(head);
                        if (!visited[next]) {
                            q.push_back(next);
                            visited[next] = true;
                        }
                    }
                }
            }
        }

        vector<string> path(dist[dest]+1);
        vector<vector<string>> result;
        dfs(dist[dest], dest, path, result, prev);
        return result;
    }
    void dfs(int i, int u, vector<string>& path, vector<vector<string>>& result, vector<vector<int>>& prev) {
        path[i] = id2w[u];
        if (i == 0)
            result.push_back(path);
        else {
            for (auto& v : prev[u])
                dfs(i-1, v, path, result, prev);
        }
    }
};

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    unordered_set<string> wordList = {"hot","dot","dog","lot","log"};
    Solution sol;
    vector<vector<string>> result = sol.findLadders(beginWord, endWord, wordList);
    for (auto& res : result) {
        for (auto& w : res) {
            cout << w << " ";
        }
        cout << endl;
    }
}
