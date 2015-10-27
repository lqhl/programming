#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n));
        vector<int> cut(n);
        for (int j = 0; j < n; j++) {
            cut[j] = j;
            for (int i = 0; i <= j; i++) {
                if (s[i] == s[j] && (i+1 >= j || dp[i+1][j-1])) {
                    dp[i][j] = true;
                    if (i > 0)
                        cut[j] = min(cut[j], cut[i-1]+1);
                    else
                        cut[j] = 0;
                }
            }
        }
        return cut[n-1];
    }
};
