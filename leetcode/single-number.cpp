#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for (auto& each : nums)
            x ^= each;
        return x;
    }
};
