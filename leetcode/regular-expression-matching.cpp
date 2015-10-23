#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string s, p;
    vector<vector<bool>> d;
    vector<vector<bool>> v;
    bool compare(int i, int j) {
        if (d[i][j]) return v[i][j];
        if (i >= s.length() && j >= p.length())
            v[i][j] = true;
        else if (i >= s.length()) {
            while (j+1 < p.length() && p[j+1] == '*') j+=2;
            v[i][j] = j == p.length();
        } else if ((j+1 == p.length() || p[j+1] != '*') && (s[i] == p[j] || p[j] == '.')) {
            v[i][j] = compare(i+1, j+1);
        } else if (j+1 < p.length() && p[j+1] == '*') {
            v[i][j] = compare(i, j+2);
            if (!v[i][j])
                for (int k = i+1; k <= s.length(); k++) {
                    if (p[j] != '.' && s[k-1] != p[j])
                        break;
                    if (compare(k, j+2)) {
                        v[i][j] = true;
                        break;
                    }
                }
        } else
            v[i][j] = false;
        d[i][j] = true;
        return v[i][j];
    }

    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;
        d = vector<vector<bool>>(s.size()+1);
        for (auto& each : d) each = vector<bool>(p.size()+1, false);
        v = vector<vector<bool>>(s.size()+1);
        for (auto& each : v) each = vector<bool>(p.size()+1, false);
        return compare(0, 0);
    }
};
