#include "util.hpp"

class Solution {
public:
    bool isNumber(string s) {
        if (s.length() == 0)
            return false;
        int n = s.length();
        bool point = false, e = false, num1 = false, num2 = false;
        int start = 0;
        while (s[start] == ' ' || s[start] == '\t') start++;
        int end = n-1;
        while (s[end] == ' ' || s[end] == '\t') end--;
        if (start > end) return false;
        for (int i = start; i <= end; i++)
            if (s[i] >= '0' && s[i] <= '9') {
                if (e)
                    num2 = true;
                else
                    num1 = true;
            }
            else if (s[i] == '.') {
                if (point)
                    return false;
                if (e)
                    return false;
                point = true;
            } else if (s[i] == 'e') {
                if (e)
                    return false;
                e = true;
            } else if (s[i] == '-' || s[i] == '+') {
                if (i == start)
                    continue;
                if (s[i-1] == 'e' && i < end)
                    continue;
                return false;
            } else
                return false;
        if (!num1)
            return false;
        if (e && !num2)
            return false;
        return true;
    }
};
