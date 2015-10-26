#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        if (prices.size() > 0) {
            int min_val = prices[0];
            for (int i = 1; i < prices.size(); i++) {
                if (prices[i] - min_val > res)
                    res = prices[i] - min_val;
                if (prices[i] < min_val)
                    min_val = prices[i];
            }
        }
        return res;
    }
};