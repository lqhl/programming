#include "util.hpp"

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> count(256, 0);
        vector<int> total(256, 0);
        for (auto& c : t)
            total[c]++;
        int begin = 0;
        int total_len = 0, cur_len = 0;
        for (auto& each : total)
            if (each > 0)
                total_len++;
        int min_len = -1, r_begin, r_end;
        for (int end = 0; end < s.length(); end++) {
            const char& c = s[end];
            count[c]++;
            if (total[c] > 0 && count[c] == total[c])
                cur_len++;
            if (cur_len == total_len) {
                char b = s[begin];
                while (total[b] == 0 || (total[b] > 0 && count[b] > total[b])) {
                    count[b]--;
                    b = s[++begin];
                }
                if (min_len == -1 || end-begin+1 < min_len) {
                    min_len = end-begin+1;
                    r_begin = begin;
                    r_end = end;
                }
            }
        }
        if (min_len == -1)
            return "";
        else
            return s.substr(r_begin, r_end-r_begin+1);
    }
};
