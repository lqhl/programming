#include "util.hpp"

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> last;
        for (int i = 0; i < nums.size(); i++) {
            if (last.count(nums[i])) {
                if (i - last[nums[i]] <= k)
                    return true;
                else
                    last[nums[i]] = i;
            } else
                last[nums[i]] = i;
        }
        return false;
    }
};
