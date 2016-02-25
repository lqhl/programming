#include "util.hpp"

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (auto each : nums) {
            if (s.count(each))
                return true;
            else
                s.insert(each);
        }
        return false;
    }
};
