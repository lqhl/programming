class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0)
            return 0;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                if (i-1 >= 0)
                    dp[i] = dp[i-1];
                else
                    dp[i] = 1;
            }
            if (i-1 >= 0 && (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))) {
                if (i-2 >= 0)
                    dp[i] += dp[i-2];
                else
                    dp[i] += 1;
            }
        }
        return dp[n-1];
    }
};
