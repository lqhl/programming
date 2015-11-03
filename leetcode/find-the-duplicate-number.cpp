#include "util.hpp"

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = 0;
        for (auto& each : nums)
            if (each > n)
                n = each;
        int left = 1, right = n;
        while (left < right) {
            int mid = (left+right)/2;
            int count = 0;
            for (auto& each : nums)
                if (each <= mid)
                    count++;
            if (count > mid)
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
};
