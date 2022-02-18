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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        int now = head->val;
        ListNode **indirect = &head->next;
        for (ListNode* i = head->next; i; i = i->next) {
            if (i->val == now) {
                *indirect = (*indirect)->next;
            } else {
                indirect = &(*indirect)->next;
                now = i->val;
            }
        }
        return head;
    }
};
