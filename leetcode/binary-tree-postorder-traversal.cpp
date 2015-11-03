#include "util.hpp"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> results;
        TreeNode* prev = nullptr;
        stack<TreeNode*> s;
        if (root)
            s.push(root);
        else
            return results;
        while (!s.empty()) {
            TreeNode* cur = s.top();
            if (prev == nullptr || prev->left == cur || prev->right == cur) {
                if (cur->left)
                    s.push(cur->left);
                else if (cur->right)
                    s.push(cur->right);
            } else if (prev == cur->left) {
                if (cur->right)
                    s.push(cur->right);
            } else {
                results.push_back(cur->val);
                s.pop();
            }
            prev = cur;
        }
        return results;
    }
};

class Solution2 {
private:
    void dfs(TreeNode* cur, vector<int>& result) {
        if (cur == nullptr) return;
        dfs(cur->left, result);
        dfs(cur->right, result);
        result.push_back(cur->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }
};
