#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length()+s2.length())
            return false;
        if (s1.empty())
            return s2 == s3;
        if (s2.empty())
            return s1 == s3;
        
        int n = s1.length(), m = s2.length();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++) {
                if (i > 0)
                    dp[i][j] = dp[i][j] || (dp[i-1][j] && s1[i-1] == s3[i+j-1]);
                if (j > 0)
                    dp[i][j] = dp[i][j] || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
                if (i > 0 && j > 0) {
                    dp[i][j] = dp[i][j] || (dp[i-1][j-1] && s1[i-1] == s3[i+j-2] && s2[j-1] == s3[i+j-1]);
                    dp[i][j] = dp[i][j] || (dp[i-1][j-1] && s1[i-1] == s3[i+j-1] && s2[j-1] == s3[i+j-2]);
                }
            }
        return dp[n][m];
    }
};
