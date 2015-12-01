#include "util.hpp"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL)
            return NULL;
        vector<ListNode*> list;
        for (ListNode* cur = head; cur != NULL; cur = cur->next)
            list.push_back(cur);
        for (int start = 0; start < list.size(); start += k) {
            int end = start+k;
            if (end > list.size())
                break;
            reverse(list.begin()+start, list.begin()+end);
        }
        for (int i = 0; i < list.size()-1; i++)
            list[i]->next = list[i+1];
        list[list.size()-1]->next = NULL;
        return list[0];
    }
};
