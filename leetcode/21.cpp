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

// faster than 77.74% solution
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        ListNode* res = nullptr;
        ListNode* middle = nullptr;
        
        while (h1 && h2) {
            if (h1->val < h2->val) {
                if (res == nullptr) {
                    res = h1;
                    middle = res;
                } else {
                    middle->next = h1;
                    middle = middle->next;
                }
                h1 = h1->next;
            } else {
                if (res == nullptr) {
                    res = h2;
                    middle = res;
                } else {
                    middle->next = h2;
                    middle = middle->next;
                }
                h2 = h2->next;
            }
        }
        
        if (res == nullptr) {
            if (h1) res = h1;
            else res = h2;
            middle = res;
        } else {
        
            while (h1) {
                middle->next = h1;
                h1 = h1->next;
                middle = middle->next;
            }
            while (h2) {
                middle->next = h2;
                h2 = h2->next;
                middle = middle->next;
            }
        }
        return res;
        
    }
};

// more clean code
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(-1);
        ListNode* temp = res;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                temp->next = l1;
                temp = temp->next;
                l1 = l1->next;
            } else {
                temp->next = l2;
                temp = temp->next;
                l2 = l2->next;
            }
        }
        
        
        while (l1) {
            temp->next = l1;
            temp = temp->next;
            l1 = l1->next;
        }
        while (l2) {
            temp->next = l2;
            temp = temp->next;
            l2 = l2->next;
        }
        
        return res->next;
        
    }
};

// recursive
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

