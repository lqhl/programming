#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int starI = -1, starJ = -1;
        while (i < s.length()) {
            if (j < p.length() && (s[i] == p[j] || p[j] == '?')) {
                i++;
                j++;
            } else if (j < p.length() && p[j] == '*') {
                starI = i;
                starJ = j;
                j++;
            } else if (starJ != -1) {
                starI = i = starI + 1;
                j = starJ + 1;
            } else
                return false;
        }
        while (j < p.length() && p[j] == '*') j++;
        return j == p.length();
    }
};
