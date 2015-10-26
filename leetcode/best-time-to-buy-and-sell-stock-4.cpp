#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k == 0)
            return 0;
        int n = prices.size();
        if (k >= n/2)
            return fastSolver(prices);

        vector<int> local(k+1, 0), global(k+1, 0);
        for (int i = 1; i < n; i++) {
            int diff = prices[i]-prices[i-1];
            for (int j = k; j >= 1; j--) {
                local[j] = max(global[j-1] + max(diff, 0), local[j] + diff);
                global[j] = max(global[j], local[j]);
            }
        }
        return global[k];
    }

    int fastSolver(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i++)
            if (prices[i] - prices[i-1] > 0)
                res += prices[i] - prices[i-1];
        return res;
    }
};
