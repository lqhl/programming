#include "util.hpp"

class Solution {
private:
    void dfs(int n, int i, int& ans, vector<bool>& a, vector<bool>& b, vector<bool>& c) {
        if (i >= n) {
            ans++;
            return;
        }
        for (int j = 0; j < n; j++)
            if (!a[j] && !b[i+j] && !c[i-j+n]) {
                a[j] = true;
                b[i+j] = true;
                c[i-j+n] = true;
                dfs(n, i+1, ans, a, b, c);
                a[j] = false;
                b[i+j] = false;
                c[i-j+n] = false;
            }
    }
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<bool> a(n, false), b(2*n, false), c(2*n, false);
        dfs(n, 0, ans, a, b, c);
        return ans;
    }
};
