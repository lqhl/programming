#include "util.hpp"

class Solution {
public:
    void dfs(vector<string>& results, const int& target, long long cur, long long prev, char op, string num, string path) {
        for (int i = 1; i <= num.length(); i++) {
            string next = num.substr(0, i);
            if (i == 2 && next[0] == '0')
                break;
            long long n = stoll(next);
            long long local_cur = cur, local_prev = prev;
            if (op == '+') {
                local_cur += n;
                local_prev = n;
            } else if (op == '-') {
                local_cur -= n;
                local_prev = -n;
            } else { // if (op == '*') {
                local_cur += - local_prev + local_prev * n;
                local_prev *= n;
            }
            if (i < num.length()) {
                dfs(results, target, local_cur, local_prev, '+', num.substr(i, num.length()-i), path + next + '+');
                dfs(results, target, local_cur, local_prev, '-', num.substr(i, num.length()-i), path + next + '-');
                dfs(results, target, local_cur, local_prev, '*', num.substr(i, num.length()-i), path + next + '*');
            } else {
                // cout << local_cur << ": " << path + next << endl;
                if (local_cur == target) {
                    results.push_back(path + next);
                }
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> results;
        dfs(results, target, 0, 0, '+', num, "");
        return results;
    }
};
