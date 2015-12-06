#include "util.hpp"

inline int lowbit(int x) {
    return x & -x;
}

class Solution {
private:
    int n;
    vector<int> BIT;

    int sum(int i) {
        i++;
        int ans = 0;
        for (int j = i; j > 0; j -= lowbit(j))
            ans += BIT[j];
        return ans;
    }

    void update(int i, int delta) {
        i++;
        for (int j = i; j <= n; j += lowbit(j))
            BIT[j] += delta;
    }

    int binary_search(vector<int>& d, int x) {
        int left = 0, right = d.size()-1;
        while (left < right) {
            int mid = (left+right) / 2;
            if (d[mid] >= x)
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }

public:

    vector<int> countSmaller(vector<int>& nums) {
        n = nums.size();
        BIT.assign(n+1, 0);
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        for (int i = 0; i < n; i++)
            nums[i] = binary_search(sorted, nums[i]);
        vector<int> results;
        for (int i = n-1; i >= 0; i--) {
            if (nums[i] == 0)
                results.push_back(0);
            else
                results.push_back(sum(nums[i]-1));
            update(nums[i], 1);
        }
        reverse(results.begin(), results.end());
        return results;
    }
};
