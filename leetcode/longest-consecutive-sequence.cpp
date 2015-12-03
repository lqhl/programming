#include "util.hpp"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int ans = 0;
        for (auto& each : nums) {
            int count = 0;
            for (int i = each; ; i++)
                if (set.count(i)) {
                    count++;
                    set.erase(i);
                } else
                    break;
            for (int i = each-1; ; i--)
                if (set.count(i)) {
                    count++;
                    set.erase(i);
                } else
                    break;
            if (count > ans)
                ans = count;
        }
        return ans;
    }
};
