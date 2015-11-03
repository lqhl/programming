#include "util.hpp"

class Solution {
private:
    int find(int* a, int* b, int n, int m, int k) {
        if (n == 0) return b[k-1];
        if (m == 0) return a[k-1];
        if (k == 1) return min(a[0], b[0]);

        if (a[n/2] <= b[m/2]) {
            if (n/2 + 1 + m/2 >= k)
                return find(a, b, n, m/2, k);
            else
                return find(a+n/2+1, b, n-n/2-1, m, k-n/2-1);
        } else {
            if (n/2 + m/2 + 1 >= k)
                return find(a, b, n/2, m, k);
            else
                return find(a, b+m/2+1, n, m-m/2-1, k-m/2-1);
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if ((n+m)%2 == 1)
            return find(&nums1[0], &nums2[0], n, m, (n+m+1)/2);
        else
            return (double) (find(&nums1[0], &nums2[0], n, m, (n+m)/2) + find(&nums1[0], &nums2[0], n, m, (n+m)/2+1)) / 2;
    }
};
