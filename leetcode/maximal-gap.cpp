#include "util.hpp"

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        int n = nums.size();
        int min_val = nums[0], max_val = nums[0];
        for (auto& x : nums) {
            min_val = min(min_val, x);
            max_val = max(max_val, x);
        }
        if (min_val == max_val)
            return 0;
        if (n == 2)
            return max_val-min_val;
        int bucket_size = (max_val-min_val-1) / (n-1) + 1;
        int nbuckets = (max_val-min_val) / bucket_size + 1;
        vector<pair<int, int>> buckets(nbuckets, make_pair(-1, -1));
        for (auto& x : nums) {
            int i = (x-min_val) / bucket_size;
            if (buckets[i].first == -1)
                buckets[i] = make_pair(x, x);
            else {
                buckets[i].first = min(buckets[i].first, x);
                buckets[i].second = max(buckets[i].second, x);
            }
        }
        int result = 0;
        int last = buckets[0].second;
        for (int i = 1; i < nbuckets; i++) {
            if (buckets[i].first == -1)
                continue;
            result = max(result, buckets[i].first-last);
            last = buckets[i].second;
        }
        return result;
    }
};
