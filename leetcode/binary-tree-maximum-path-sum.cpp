#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int dfs(TreeNode* root, int& res) {
        if (root == nullptr)
            return 0;
        int ret = INT_MIN;
        int left = dfs(root->left, res);
        int right = dfs(root->right, res);
        ret = max(ret, root->val);
        ret = max(ret, root->val+left);
        ret = max(ret, root->val+right);
        res = max(res, ret);
        res = max(res, left+root->val+right);
        return ret;
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        dfs(root, res);
        return res;
    }
};
