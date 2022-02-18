/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    const int REMOVED = 666;
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return head;
        
        // delete duplicate only first and mark the node that should be removed later
        ListNode **prev_indirect = &head;
        ListNode **indirect = &head->next;
        int now = head->val;
        int count = 0;
        for (ListNode *i = head->next; i; i = i->next) {
            if (now == i->val) {
                count ++;
                *indirect = (*indirect)->next; 
            } else {
                if (count) {
                    (*prev_indirect)->val = REMOVED;
                }
                prev_indirect = indirect;
                indirect = &(*indirect)->next;
                now = i->val;
                count = 0;
            }
        }
        if (count) {
            (*prev_indirect)->val = REMOVED;
        }
        
        // delete the marked node
        indirect = &head;
        while((*indirect)) {
            if ((*indirect)->val == REMOVED) {
                *indirect = (*indirect)->next;
            } else {
                indirect = &(*indirect)->next;
            }
        }
        return head;
    }
};
