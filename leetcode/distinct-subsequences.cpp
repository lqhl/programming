#include "util.hpp"

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        vector<int> dp2(m+1, 0);
        dp2[0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = m; j >= 1; j--) {
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = dp2[j-1];
                    dp2[j] += dp[i][j];
                }
            }
        return dp2[m];
    }
};
