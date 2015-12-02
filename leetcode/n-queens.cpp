#include "util.hpp"

class Solution {
private:
    void dfs(int n, int i, vector<string>& current, vector<vector<string>>& results, vector<bool>& a, vector<bool>& b, vector<bool>& c) {
        if (i >= n) {
            results.push_back(current);
            return;
        }
        for (int j = 0; j < n; j++)
            if (!a[j] && !b[i+j] && !c[i-j+n]) {
                a[j] = true;
                b[i+j] = true;
                c[i-j+n] = true;
                current[i][j] = 'Q';
                dfs(n, i+1, current, results, a, b, c);
                a[j] = false;
                b[i+j] = false;
                c[i-j+n] = false;
                current[i][j] = '.';
            }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        vector<string> current(n, string(n, '.'));
        vector<bool> a(n, false), b(2*n, false), c(2*n, false);
        dfs(n, 0, current, results, a, b, c);
        return results;
    }
};

int main() {
    Solution sol;
    int n = 8;
    vector<vector<string>> results = sol.solveNQueens(n);
    cout << results.size() << endl;
}
