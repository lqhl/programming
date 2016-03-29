#include "util.hpp"

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> results(num+1, 0);
        int pow2 = 1;
        for (int i = 1; i <= num; i++) {
            if (pow2 * 2 <= i)
                pow2 *= 2;
            if (i == pow2)
                results[i] = 1;
            else
                results[i] = 1 + results[i-pow2];
        }
        return results;
    }
};
