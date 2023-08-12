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
    ListNode *swapPairs(ListNode *head) {
        if (!head)
            return head;
        if (head && head->next == nullptr)
            return head;

        ListNode *now = head;
        ListNode *next = head->next;
        ListNode *next_next = next->next;

        next->next = now;
        now->next = swapPairs(next_next);

        return next;
    }
};
