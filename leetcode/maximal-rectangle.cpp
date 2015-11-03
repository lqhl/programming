#include "util.hpp"

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = n > 0 ? matrix[0].size() : 0;
        vector<vector<int>> height(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (matrix[i][j] == '1') {
                    height[i][j] = 1;
                    if (i > 0)
                        height[i][j] += height[i-1][j];
                }
        int res = 0;
        for (int i = 0; i < n; i++)
            res = max(res, largestRectangleArea(height[i]));
        return res;
    }
    int largestRectangleArea(vector<int>& height) {
        stack<int> s;
        height.push_back(0);
        int res = 0;
        for (int i = 0; i < height.size(); ) {
            if (s.empty() || height[s.top()] < height[i]) {
                s.push(i++);
            } else {
                int c = s.top();
                s.pop();
                res = max(res, height[c] * (s.empty() ? i : i-s.top()-1));
            }
        }
        return res;
    }
};
