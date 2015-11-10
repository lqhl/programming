#include "util.hpp"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n; i++) {
            while (!q.empty() && nums[q.back()] < nums[i])
                q.pop_back();
            q.push_back(i);
            if (!q.empty() && q.front() <= i-k)
                q.pop_front();
            if (i >= k-1)
                res.push_back(nums[q.front()]);
        }
        return res;
    }
};
