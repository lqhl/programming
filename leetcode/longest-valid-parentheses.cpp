#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char, int>> st;
        vector<int> dp(s.length(), 0);
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(make_pair(s[i], i));
            } else {
                if (!st.empty() && st.top().first == '(') {
                    int idx = st.top().second;
                    st.pop();
                    dp[i] = (i-idx+1) + (idx-1 >= 0 ? dp[idx-1] : 0);
                    res = max(res, dp[i]);
                }
            }
        }
        return res;
    }
};
