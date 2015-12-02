#include "util.hpp"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n-1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] < nums[right])
                right = mid;
            else
                left = mid+1;
        }
        int pivot = left;
        left = 0, right = n-1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (target <= nums[(mid+pivot)%n])
                right = mid;
            else
                left = mid+1;
        }
        if (nums[(left+pivot)%n] == target)
            return (left+pivot)%n;
        else
            return -1;
    }
};
