#include "util.hpp"

class Solution {
public:
    void reverseWords(string &s) {
        string tmp = "", word = "";
        s += ' ';
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ')
                word += s[i];
            else {
                if (word.length() > 0 && tmp.length() > 0)
                    word += ' ';
                tmp = word + tmp;
                word = "";
            }
        }
        s = tmp;
    }
};

int main() {
    string s = "the sky is blue";
    Solution sol;
    sol.reverseWords(s);
    cout << s << endl;
}
