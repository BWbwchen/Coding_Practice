class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) return nullptr;
        ListNode *newhead = nullptr;
        ListNode *left = nullptr;
        ListNode *right = nullptr;
        ListNode *righthead = nullptr;
        
        while (head) {
            if (head->val < x) {
                if (left) {
                    left->next = head; 
                    left = left->next;
                } else {
                    left = head;
                    newhead = head;
                }
            } else {
                if (right) {
                    right->next = head;
                    right = right->next;
                } else {
                    right = head;
                    righthead = head;
                }
            }
            head = head->next;
        }
        if (left) {
            left->next = righthead;
            if (right) right->next = nullptr;
        } else {
            newhead = righthead;
            right->next = nullptr;
        }
        return newhead;
    }
};
