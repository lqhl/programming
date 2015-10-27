#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool is_palindrome(string& s, int i, int len) {
        for (int k = 0; k < len/2; k++)
            if (s[i+k] != s[i+len-k-1])
                return false;
        return true;
    }
    void dfs(string& s, int i, int len, vector<vector<string>>& results, vector<string> path) {
        if (i == s.length()) {
            results.push_back(path);
            return;
        }
        path.push_back("");
        for (int l = 1; l <= len; l++) {
            if (is_palindrome(s, i, l)) {
                path.back() = s.substr(i, l);
                dfs(s, i+l, len-l, results, path);
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> results;
        dfs(s, 0, s.length(), results, vector<string>());
        return results;
    }
};

int main() {
    Solution sol;
    auto results = sol.partition("aabaa");
    for (auto& each : results) {
        for (auto& s : each)
            cout << s << ' ';
        cout << endl;
    }
}
