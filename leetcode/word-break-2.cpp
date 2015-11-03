#include "util.hpp"

class Solution {
public:
    void dfs(int start, string sentence, string& s, vector<vector<int>>& mark, vector<string>& results) {
        if (start == s.length()) {
            results.push_back(sentence);
            return;
        }
        for (auto& end : mark[start]) {
            string next = sentence + (sentence == "" ? s.substr(start, end-start) : " " + s.substr(start, end-start));
            dfs(end, next, s, mark, results);
        }
    }
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<vector<int>> mark(s.length());
        for (int end = s.length(); end > 0; end--) {
            if (end < s.length() && mark[end].empty())
                continue;
            for (int start = end-1; start >= 0; start--)
                if (wordDict.count(s.substr(start, end-start)))
                    mark[start].push_back(end);
        }
        vector<string> results;
        dfs(0, "", s, mark, results);
        return results;
    }
};

int main() {
    Solution sol;
    string s = "catsanddog";
    unordered_set<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    vector<string> result = sol.wordBreak(s, wordDict);
    for (auto& each : result)
        cout << each << endl;
}
