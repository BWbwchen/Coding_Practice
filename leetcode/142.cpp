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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast && fast->next) {
            slow = slow->next; 
            fast = fast->next->next; 
            if (slow == fast) {
                // cycle
                ListNode *start = head;
                while (start != slow) {
                    slow = slow->next;
                    start = start->next;
                }
                return start;
            }
        }
        return nullptr;
    }
};

// Solution:
// consider a general case :
// The length of no cycle : r
// The length of cycle : k
// When fast pointer met slow pointer :
// The path that slow pointer had finished : r + nk(how many cycle have finished) + w(part of cycle)
// The path that fast pointer had finished : r + (n+1)k(how many cycle have finished) + w(part of cycle)
// We know that the path fast pointer had finished is twice longer than slow pointer had finished :
//      2(r + nk + w) = r + (n+1)k + w
// =>   r + nk + w = k
// =>   r + nk = k - w => k - w is the remain part of the cycle !!!
// So Let's think about what is k - w ?
// k - w is r + nk, and k - w is less than k. Since it is just part of the cycle.
// So 
//      k - w <= k
// =>   r + nk <= k
//      n should be 0, if r > 0.
// or   n == 1, r = 0
