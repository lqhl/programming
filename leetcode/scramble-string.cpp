#include "util.hpp"

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length())
            return false;
        int n = s1.length();
        if (n == 0)
            return true;
        if (s1 == s2)
            return true;
        string t1 = s1, t2 = s2;
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        if (t1 != t2)
            return false;
        for (int len = 1; len < n; len++) {
            if (isScramble(s1.substr(0, len), s2.substr(0, len)) and
                isScramble(s1.substr(len), s2.substr(len)))
                return true;
            if (isScramble(s1.substr(0, len), s2.substr(n-len)) and
                isScramble(s1.substr(len), s2.substr(0, n-len)))
                return true;
        }
        return false;
    }
};
