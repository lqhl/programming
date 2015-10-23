#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Solution {

public:
    string proc(vector<string>& words, int maxWidth) {
        int len = 0;
        for (auto& w : words) len += w.length();
        int nspaces = maxWidth - len;
        ostringstream out;
        if (words.size() == 1) {
            out << words[0];
            for (int i = 0; i < nspaces; i++) out << " ";
            return out.str();
        }
        int avg = nspaces / (words.size()-1);
        int remain = nspaces % (words.size()-1);
        out << words[0];
        for (int i = 1; i < words.size(); i++) {
            for (int k = 0; k < avg; k++) out << " ";
            if (i <= remain) out << " ";
            out << words[i];
        }
        return out.str();
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int len = 0;
        vector<string> line;
        vector<string> result;
        for (int i = 0; i < words.size(); i++) {
            if (len == 0) {
                len = words[i].length();
                line.push_back(words[i]);
            } else if (len + words[i].length() + 1 <= maxWidth) {
                len += words[i].length() + 1;
                line.push_back(words[i]);
            } else {
                result.push_back(proc(line, maxWidth));
                line.clear();
                len = words[i].length();
                line.push_back(words[i]);
            }
        }
        
        ostringstream last;
        last << line[0];
        maxWidth -= line[0].length();
        for (int i = 1; i < line.size(); i++) {
            last << " " << line[i];
            maxWidth -= 1+line[i].length();
        }
        while (maxWidth-- > 0)
            last << " ";
        result.push_back(last.str());
        return result;
    }
};
