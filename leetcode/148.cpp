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
    // merge sort
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head; 
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* half = slow->next;
        slow->next = nullptr;
        
        return Merge(sortList(head), sortList(half));
    }
    
    ListNode* Merge(ListNode* l1, ListNode* l2) {
        ListNode* res = nullptr;
        ListNode* temp_head = nullptr; 
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                if (res == nullptr) {
                    res = l1;
                    temp_head = l1;
                    l1 = l1->next;
                    continue;
                }
                temp_head->next = l1; 
                temp_head = temp_head->next;
                l1 = l1->next;
            } else {
                if (res == nullptr) {
                    res = l2;
                    temp_head = l2;
                    l2 = l2->next;
                    continue;
                }
                temp_head->next = l2; 
                temp_head = temp_head->next;
                l2 = l2->next;
            }
        }
        while (l1) {
            if (res == nullptr) {
                res = l1;
                temp_head = l1;
                l1 = l1->next;
                continue;
            }
            temp_head->next = l1; 
            temp_head = temp_head->next;
            l1 = l1->next;
        }
        while (l2) {
            if (res == nullptr) {
                res = l2;
                temp_head = l2;
                l2 = l2->next;
                continue;
            }
            temp_head->next = l2; 
            temp_head = temp_head->next;
            l2 = l2->next;
        }
        return res;
    }
};
