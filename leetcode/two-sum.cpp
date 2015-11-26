#include "util.hpp"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> data;
        for (int i = 0; i < n; i++)
            data.push_back(make_pair(nums[i], i+1));
        sort(data.begin(), data.end());
        int i = 0, j = n-1;
        vector<int> result;
        while (i < j) {
            if (data[i].first+data[j].first == target) {
                int a = data[i].second, b = data[j].second;
                if (a > b)
                    swap(a, b);
                result.push_back(a);
                result.push_back(b);
                break;
            } else if (data[i].first+data[j].first > target)
                j--;
            else
                i++;
        }
        return result;
    }
};
