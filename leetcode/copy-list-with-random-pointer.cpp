#include "util.hpp"

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
private:
    RandomListNode* copy(RandomListNode* cur, unordered_map<RandomListNode*, RandomListNode*>& o2n) {
        if (cur == NULL)
            return NULL;
        if (o2n.count(cur))
            return o2n[cur];
        RandomListNode* node = new RandomListNode(cur->label);
        o2n[cur] = node;
        node->next = copy(cur->next, o2n);
        node->random = copy(cur->random, o2n);
        return node;
    }
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> o2n;
        return copy(head, o2n);
    }
};
