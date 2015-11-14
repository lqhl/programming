#include "util.hpp"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode* prev;
    TreeNode* a;
    TreeNode* b;
    void dfs(TreeNode* cur) {
        if (cur == NULL)
            return;
        dfs(cur->left);
        if (prev && prev->val > cur->val) {
            if (a == NULL) {
                a = prev;
                b = cur;
            } else {
                b = cur;
            }
        }
        prev = cur;
        dfs(cur->right);
    }
public:
    void recoverTree(TreeNode* root) {
        prev = NULL;
        a = NULL;
        b = NULL;
        dfs(root);
        if (a && b)
            swap(a->val, b->val);
        else
            cout << "fail" << endl;
    }
};
