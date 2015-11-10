#include "util.hpp"

class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0, reach = 0, last = 0;
        for (int i = 0; i <= reach && i < nums.size(); i++) {
            if (i > last) {
                step++;
                last = reach;
            }
            reach = max(reach, i+nums[i]);
        }
        if (reach >= nums.size()-1)
            return step;
        else
            return -1;
    }
};
