# Add Two Numbers
brute force 
O(max(length_l1, length_l2))
``` c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // add directly
        ListNode *temp_l1 = l1;
        ListNode *temp_l2 = l2;
        while (temp_l1 && temp_l2) {
            int t = temp_l2->val;
            temp_l2->val += temp_l1->val;
            temp_l1->val += t;
            temp_l1 = temp_l1->next;
            temp_l2 = temp_l2->next;
        }
        if (temp_l1) {
            temp_l1 = l1;
            while (temp_l1) {
                if (temp_l1->val > 9) {
                    // carry to next
                    if (temp_l1->next) temp_l1->next->val += 1;
                    else temp_l1->next = new ListNode(1);

                    temp_l1->val -= 10;
                }
                temp_l1 = temp_l1->next;            
            }
            return l1;
        }else {
            temp_l2 = l2;
            while (temp_l2) {
                if (temp_l2->val > 9) {
                    // carry to next
                    if (temp_l2->next) temp_l2->next->val += 1;
                    else temp_l2->next = new ListNode(1);

                    temp_l2->val -= 10;
                }
                temp_l2 = temp_l2->next;            
            }
            return l2;
        }
        
        
        //carry 
        
    }
};
```