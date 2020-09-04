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
// faster than 83.97% solution
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return head;
        // travel all, in order to get the length
        ListNode* temp = head;
        int length = 1;
        while (temp != nullptr) {
            temp = temp->next;
            length++;
        }
        // travel again to the target
        temp = head;
        ListNode* pre = nullptr;
        length -= n;
        while (--length) {
            pre = temp;
            temp = temp->next;
        }
        // remove it
        if (temp == head) {
            head = temp->next;
        } else if (temp->next == nullptr) {
            pre->next = nullptr;   
        } else {
            pre->next = temp->next;
        }
        return head;
    }
};
