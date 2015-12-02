#include "util.hpp"

// DFS
class Solution {
private:
    int missed(string s) {
        int left = 0, right = 0;
        for (int i = 0; i < s.length(); i++)
            if (s[i] == '(' || s[i] == ')') {
                if (s[i] == '(')
                    left++;
                else
                    left--;
                right += left < 0;
                if (left < 0)
                    left = 0;
            }
        return left + right;
    }

    void dfs(string s, vector<string>& results, unordered_set<string>& visited) {
        int score = missed(s);
        if (score == 0) {
            results.push_back(s);
            return;
        }
        for (int i = 0; i < s.length(); i++)
            if (s[i] == '(' || s[i] == ')') {
                string t = s.substr(0, i) + s.substr(i+1);
                if (visited.count(t) == 0 && missed(t) < score) {
                    visited.insert(t);
                    dfs(t, results, visited);
                }
            }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> results;
        unordered_set<string> visited;
        visited.insert(s);
        dfs(s, results, visited);
        return results;
    }
};

// BFS
class Solution2 {
private:
    int missed(string s) {
        int left = 0, right = 0;
        for (int i = 0; i < s.length(); i++)
            if (s[i] == '(' || s[i] == ')') {
                if (s[i] == '(')
                    left++;
                else
                    left--;
                right += left < 0;
                if (left < 0)
                    left = 0;
            }
        return left + right;
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> results;
        unordered_set<string> visited;
        visited.insert(s);
        deque<string> q;
        q.push_back(s);
        while (!q.empty()) {
            string s = q.front();
            q.pop_front();
            int score = missed(s);
            if (score == 0) {
                results.push_back(s);
                continue;
            }
            for (int i = 0; i < s.length(); i++)
                if (s[i] == '(' || s[i] == ')') {
                    string t = s.substr(0, i) + s.substr(i+1);
                    if (visited.count(t) == 0 && missed(t) < score) {
                        visited.insert(t);
                        q.push_back(t);
                    }
                }
        }
        return results;
    }
};
