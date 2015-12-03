#include "util.hpp"

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxL(n, 0);
        for (int i = 1; i < n; i++)
            maxL[i] = max(maxL[i-1], height[i-1]);
        int maxR = 0;
        int ans = 0;
        for (int i = n-1; i >= 0; i--) {
            ans += max(0, min(maxL[i], maxR)-height[i]);
            maxR = max(maxR, height[i]);
        }
        return ans;
    }
};
