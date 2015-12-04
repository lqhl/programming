#include "util.hpp"

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* p = root;
        TreeLinkNode* first = NULL;
        TreeLinkNode* last = NULL;
        while (p) {
            if (!first) {
                if (p->left)
                    first = p->left;
                else if (p->right)
                    first = p->right;
            }
            if (p->left) {
                if (last)
                    last->next = p->left;
                last = p->left;
            }
            if (p->right) {
                if (last)
                    last->next = p->right;
                last = p->right;
            }
            if (p->next)
                p = p->next;
            else {
                p = first;
                first = NULL;
                last = NULL;
            }
        }
    }
};

int main() {
    TreeLinkNode one(1), two(2), three(3);
    one.left = &two;
    one.right = &three;
    Solution sol;
    sol.connect(&one);
}
