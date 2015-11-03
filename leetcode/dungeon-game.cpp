#include "util.hpp"

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = n-1; i >= 0; i--)
            for (int j = m-1; j>=0; j--) {
                int tmp = -1;
                if (i < n-1)
                    tmp = dp[i+1][j];
                if (j < m-1 && (tmp == -1 || dp[i][j+1] < tmp))
                    tmp = dp[i][j+1];
                if (tmp == -1)
                    tmp = 0;
                if (dungeon[i][j] >= 0)
                    dp[i][j] = max(0, tmp-dungeon[i][j]);
                else
                    dp[i][j] = -dungeon[i][j] + tmp;
            }
        return dp[0][0]+1;
    }
};
