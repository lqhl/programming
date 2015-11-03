#include "util.hpp"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        s.push(root);
        vector<int> result;
        while (!s.empty()) {
            TreeNode* cur = s.top();
            s.pop();
            if (cur == nullptr)
                continue;
            result.push_back(cur->val);
            s.push(cur->right);
            s.push(cur->left);
        }
        return result;
    }
};
