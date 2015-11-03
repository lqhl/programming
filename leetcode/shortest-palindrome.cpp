#include "util.hpp"

class Solution {
public:
    string shortestPalindrome(string s) {
        if (s == "")
            return "";
        int longest = 0;
        for (int i = 0; i <= s.length()/2;) {
            int begin, end;
            begin = end = i;
            while (end+1 < s.length() && s[end+1] == s[i])
                end++;
            i = end+1;
            while (end+1 < s.length() && begin-1 >= 0 && s[end+1] == s[begin-1]) {
                end++;
                begin--;
            }
            if (begin == 0) {
                int len = end+1;
                longest = max(longest, len);
            }
        }
        string p = s.substr(longest);
        reverse(p.begin(), p.end());
        return p + s;
    }
};
