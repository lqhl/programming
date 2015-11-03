#include "util.hpp"

class Solution {
public:
    int candy(vector<int>& ratings) {
        int res = 1, prev = 1, last = 0, v = 1;
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i-1]) {
                prev++;
                res += prev;
                last = i;
                v = prev;
            } else if (ratings[i] < ratings[i-1]) {
                if (prev > 1) {
                    prev = 1;
                    res += prev;
                } else {
                    res += i-last + prev;
                    if (v >= i-last+1)
                        res--;
                }
            } else {
                last = i;
                if (prev > 1) {
                    prev = 1;
                    res += prev;
                } else {
                    res += prev;
                }
                v = prev;
            }
        }
        return res;
    }
};
