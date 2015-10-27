#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> results;
        int len = words[0].length();
        unordered_map<string, int> need;
        for (auto& w : words) need[w]++;
        unordered_map<string, int> found;
        
        for (int k = 0; k < len; k++) {
            int missed = need.size();
            int i = k, j = k;
            found.clear();
            while (i < s.length() && j < s.length() && j+len <= s.length()) {
                string next = s.substr(j, len);
                auto it = need.find(next);
                if (it != need.end()) {
                    found[next]++;
                    if (found[next] == it->second) {
                        missed--;
                        if (missed == 0) {
                            results.push_back(i);
                            found[s.substr(i, len)]--;
                            missed++;
                            i += len;
                        }
                    } else if (found[next] > it->second) {
                        while (i < j) {
                            string first = s.substr(i, len);
                            if (found[first] == need[first])
                                missed++;
                            found[first]--;
                            i += len;
                            if (first == next)
                                break;
                        }
                    }
                    j += len;
                } else {
                    missed = need.size();
                    found.clear();
                    i = j = j + len;
                }
            }
        }
        
        return results;
    }
};
