#include "util.hpp"

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<int, int> d2i;
        for (int i = 0; i < nums.size(); i++) {
            long d = nums[i];
            auto it = d2i.lower_bound(d-t);
            while (it != d2i.end() && it->first <= d+t) {
                if (it->second+k >= i)
                    return true;
                auto t = it;
                it++;
                d2i.erase(t);
            }
            d2i[d] = i;
        }
        return false;
    }
};
