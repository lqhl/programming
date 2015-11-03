#include "util.hpp"

class Solution {
public:
    int evalRPN(vector <string> &tokens) {
        stack <int> s;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i].length() == 1 && tokens[i].find_first_of("+-*/") !=
                    string::npos) {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                if (tokens[i] == "+") {
                    s.push(a + b);
                } else if (tokens[i] == "-") {
                    s.push(a - b);
                } else if (tokens[i] == "*") {
                    s.push(a * b);
                } else if (tokens[i] == "/") {
                    s.push(a / b);
                }
            } else {
                int num;
                istringstream(tokens[i]) >> num;
                s.push(num);
            }
        }
        return s.top();
    }
};

int main() {
    Solution sol;
    const char *input[] = {"-1","1","*","-1","+"};
    vector <string> tokens(input, input + sizeof(input) / sizeof(char *));
    cout << sol.evalRPN(tokens) << endl;
}
