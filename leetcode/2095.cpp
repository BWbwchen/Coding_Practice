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
    ListNode* deleteMiddle(ListNode* head) {
        cin.tie(NULL);
        ios_base::sync_with_stdio(false);
        
        ListNode* fast = head;
        ListNode** indirect = &head;
        
        while(fast && fast->next) {
            indirect = &(*indirect)->next;
            fast = fast->next->next;
        }
        *indirect = (*indirect)->next;
        return head;
    }
};
