#include "util.hpp"

// my own DP function
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

// standard
class Solution2 {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        return dp[n][m];
    }
};

// optimized for space
class Solution3 {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<int> dp(m+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = m; j >= 1; j--) {
                if (s[i-1] == t[j-1]) {
                    dp[j] = dp[j-1]+dp[j];
                } else {
                    dp[j] = dp[j];
                }
            }
        return dp[m];
    }
};
