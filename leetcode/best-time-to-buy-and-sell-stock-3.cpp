#include "util.hpp"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> local(2+1, 0), global(2+1, 0);
        for (int i = 1; i < n; i++) {
            int diff = prices[i]-prices[i-1];
            for (int j = 2; j >= 1; j--) {
                local[j] = max(global[j-1] + max(diff, 0), local[j] + diff);
                global[j] = max(global[j], local[j]);
            }
        }
        return global[2];
    }
};
