#include "util.hpp"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> results;
        TreeNode* cur = root;
        while (true) {
            if (cur != nullptr) {
                s.push(cur);
                cur = cur->left;
            } else if (!s.empty()) {
                cur = s.top();
                s.pop();
                results.push_back(cur->val);
                cur = cur->right;
            } else
                break;
        }
        return results;
    }
};

class Solution2 {
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
