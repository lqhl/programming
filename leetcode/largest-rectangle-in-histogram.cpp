class Solution {
public:
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
