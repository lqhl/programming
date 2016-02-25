#include "util.hpp"

class Solution {
public:
    vector<int> maxNumber(const vector<int>& nums, int k) {
        vector<int> result;
        int idx = 0;
        for (int i = 0; i < k; i++) {
            int max_val = nums[idx], max_idx = idx;
            for (int j = idx+1; j < nums.size()-(k-i-1); j++)
                if (nums[j] > max_val) {
                    max_val = nums[j];
                    max_idx = j;
                }
            idx = max_idx+1;
            result.push_back(max_val);
        }
        return result;
    }
    
    bool greater(const vector<int>& nums1, int i, const vector<int>& nums2, int j) {
        for ( ; i < nums1.size() && j < nums2.size(); i++, j++) {
            if (nums1[i] > nums2[j])
                return true;
            else if (nums1[i] < nums2[j])
                return false;
        }
        return i < nums1.size();
    }

    vector<int> merge(const vector<int>& nums1, const vector<int>& nums2) {
        vector<int> result;
        for (int i = 0, j = 0; i < nums1.size() || j < nums2.size(); ) {
            if (greater(nums1, i, nums2, j))
                result.push_back(nums1[i++]);
            else
                result.push_back(nums2[j++]);
        }
        return result;
    }

    int compare(const vector<int>& nums1, const vector<int>& nums2) {
        int r = 0;
        for (int i = 0; i < nums1.size(); i++) {
            r = nums1[i] - nums2[i];
            if (r != 0)
                return r;
        }
        return r;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> result;
        for (int i = 0; i <= k; i++) {
            if (i > nums1.size() || k-i > nums2.size())
                continue;
            vector<int> num = merge(maxNumber(nums1, i), maxNumber(nums2, k-i));
            if (result.empty() || compare(result, num) < 0) {
                result = num;
            }
        }
        return result;
    }
};
