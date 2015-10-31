#include <vector>
#include <stack>
#include <cstdlib>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*, bool>> s;
        s.push(make_pair(root, true));
        vector<int> result;
        while (!s.empty()) {
            TreeNode* cur = s.top().first;
            bool flag = s.top().second;
            s.pop();
            if (cur == nullptr)
                continue;
            if (flag) {
                s.push(make_pair(cur->right, true));
                s.push(make_pair(cur, false));
                s.push(make_pair(cur->left, true));
            } else
                result.push_back(cur->val);
        }
        return result;
    }
};
