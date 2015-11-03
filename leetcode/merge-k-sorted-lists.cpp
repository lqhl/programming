#include "util.hpp"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct Compare {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.first > b.first;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> p;
        for (int i = 0; i < lists.size(); i++)
            if (lists[i] != nullptr) {
                p.push(make_pair(lists[i]->val, i));
                lists[i] = lists[i]->next;
            }
        ListNode* root = nullptr;
        ListNode* last = nullptr;
        while (!p.empty()) {
            ListNode* cur = new ListNode(p.top().first);
            if (root == nullptr) {
                root = last = cur;
            } else {
                last->next = cur;
                last = cur;
            }
            int i = p.top().second;
            p.pop();
            if (lists[i] != nullptr) {
                p.push(make_pair(lists[i]->val, i));
                lists[i] = lists[i]->next;
            }
        }
        return root;
    }
};

